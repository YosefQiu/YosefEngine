#include "DefaultAllocator.h"
#include "tlsf/tlsf.h"

#define USE_POOL 1

//1024 1KB
//1024x1024 1MB 1048576
//1024x1024x1024 1GB 1073741824
static unsigned long sReservedTotalMemory = 50485760;
static unsigned int mReservedSize = 504857600;//500MB
static tlsf_t sTLSF = nullptr;
static bool sbAppQuited = false;
extern "C" void InitMemory() 
{
#if USE_POOL
	if (sTLSF == nullptr)
	{
		void* buffer = malloc(mReservedSize);
		sTLSF = tlsf_create_with_pool(buffer, mReservedSize);
	}
#endif
}
extern "C" void OnQuitMemory() {
	sbAppQuited = true;
}
void AllocateMemoryFromSystem(std::size_t size) {
	void*buffer = malloc(mReservedSize);
	tlsf_add_pool(sTLSF, buffer, mReservedSize);
	sReservedTotalMemory += mReservedSize;
}
static void*GetMemory(size_t size) {
	if (sTLSF == nullptr) {
		InitMemory();
	}
	void * ptrMemory = nullptr;
	ptrMemory = tlsf_malloc(sTLSF, size);
	while (ptrMemory == nullptr) {
		AllocateMemoryFromSystem(mReservedSize);
		ptrMemory = tlsf_malloc(sTLSF, size);
	}
	return ptrMemory;
}
static void Recycle(void*ptr) {
	if (sbAppQuited) {
		return;
	}
	tlsf_free(sTLSF, ptr);
}

void*operator new(std::size_t size) {
	void* ptr = GetMemory(size);
	return ptr;
}

void*operator new(std::size_t size, MemoryLabel memID) {
	void* ptr = GetMemory(size);
	return ptr;
}

void*operator new[](std::size_t size, MemoryLabel memID) {
	void* ptr = GetMemory(size);
	return ptr;
}

void operator delete(void*ptr,MemoryLabel memID){

}

void operator delete[](void*ptr, MemoryLabel memID){

}
void operator delete(void*ptr){
	Recycle(ptr);
}

void operator delete [](void*ptr){
	Recycle(ptr);
}