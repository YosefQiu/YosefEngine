/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated May 1, 2019. Replaces all prior versions.
 *
 * Copyright (c) 2013-2019, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
 * NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, BUSINESS
 * INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include <spine/Skin.h>
#include <spine/extension.h>

_Entry* _Entry_create (int slotIndex, const char* name, spAttachment* attachment) {
	_Entry* self = NEW(_Entry);
	self->slotIndex = slotIndex;
	MALLOC_STR(self->name, name);
	self->attachment = attachment;
	return self;
}

void _Entry_dispose (_Entry* self) {
	spAttachment_dispose(self->attachment);
	FREE(self->name);
	FREE(self);
}

static _SkinHashTableEntry* _SkinHashTableEntry_create (_Entry* entry) {
	_SkinHashTableEntry* self = NEW(_SkinHashTableEntry);
	self->entry = entry;
	return self;
}

static void _SkinHashTableEntry_dispose (_SkinHashTableEntry* self) {
	FREE(self);
}

/**/

spSkin* spSkin_create (const char* name) {
	spSkin* self = SUPER(NEW(_spSkin));
	MALLOC_STR(self->name, name);
	return self;
}

void spSkin_dispose (spSkin* self) {
	_Entry* entry = SUB_CAST(_spSkin, self)->entries;

	while (entry) {
		_Entry* nextEntry = entry->next;
		_Entry_dispose(entry);
		entry = nextEntry;
	}

	{
		_SkinHashTableEntry** currentHashtableEntry = SUB_CAST(_spSkin, self)->entriesHashTable;
		int i;

		for (i = 0; i < SKIN_ENTRIES_HASH_TABLE_SIZE; ++i, ++currentHashtableEntry) {
			_SkinHashTableEntry* hashtableEntry = *currentHashtableEntry;

			while (hashtableEntry) {
				_SkinHashTableEntry* nextEntry = hashtableEntry->next;
				_SkinHashTableEntry_dispose(hashtableEntry);
				hashtableEntry = nextEntry;
			}
		}
	}

	FREE(self->name);
	FREE(self);
}

void spSkin_addAttachment (spSkin* self, int slotIndex, const char* name, spAttachment* attachment) {
	_Entry* newEntry = _Entry_create(slotIndex, name, attachment);
	newEntry->next = SUB_CAST(_spSkin, self)->entries;
	SUB_CAST(_spSkin, self)->entries = newEntry;

	{
		unsigned int hashTableIndex = (unsigned int)slotIndex % SKIN_ENTRIES_HASH_TABLE_SIZE;

		_SkinHashTableEntry* newHashEntry = _SkinHashTableEntry_create(newEntry);
		newHashEntry->next = SUB_CAST(_spSkin, self)->entriesHashTable[hashTableIndex];
		SUB_CAST(_spSkin, self)->entriesHashTable[hashTableIndex] = newHashEntry;
	}
}

spAttachment* spSkin_getAttachment (const spSkin* self, int slotIndex, const char* name) {
	const _SkinHashTableEntry* hashEntry = SUB_CAST(_spSkin, self)->entriesHashTable[(unsigned int)slotIndex % SKIN_ENTRIES_HASH_TABLE_SIZE];
	while (hashEntry) {
		if (hashEntry->entry->slotIndex == slotIndex && strcmp(hashEntry->entry->name, name) == 0) return hashEntry->entry->attachment;
		hashEntry = hashEntry->next;
	}
	return 0;
}

const char* spSkin_getAttachmentName (const spSkin* self, int slotIndex, int attachmentIndex) {
	const _Entry* entry = SUB_CAST(_spSkin, self)->entries;
	int i = 0;
	while (entry) {
		if (entry->slotIndex == slotIndex) {
			if (i == attachmentIndex) return entry->name;
			i++;
		}
		entry = entry->next;
	}
	return 0;
}

void spSkin_attachAll (const spSkin* self, spSkeleton* skeleton, const spSkin* oldSkin) {
	const _Entry *entry = SUB_CAST(_spSkin, oldSkin)->entries;
	while (entry) {
		spSlot *slot = skeleton->slots[entry->slotIndex];
		if (slot->attachment == entry->attachment) {
			spAttachment *attachment = spSkin_getAttachment(self, entry->slotIndex, entry->name);
			if (attachment) spSlot_setAttachment(slot, attachment);
		}
		entry = entry->next;
	}
}
