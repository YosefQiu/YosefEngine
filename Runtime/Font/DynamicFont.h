#pragma once
#include "FontFace.h"
#include "Runtime/IO/ResourceManager.h"
#include <string>
#include <unordered_map>
#include <list>
#include "Runtime/Serializer/TextureAtlas.serializer.h"
#include "Runtime/IO/FontResource.h"
#include "CharInfo.h"

namespace YOSEF{
class DynamicFont : public Object{
public:
	DynamicFont();
	~DynamicFont();
	SmartPtr<FontFace> mFace;
	//key is : [size+charstyle](8bit)+bold_strength(4bit)+outlinesize(4bit)+shadow_x(8bit)+shadow_y(8bit)+  unicode(32bit)
	std::unordered_map<YOSEFUInt64, CharInfo*> mCachedChars;
	std::list<DynamicTextureAtlas*> mAtlases;
public:
	CharInfo * GetCharInfoWithCharID(YOSEFUInt64 char_id);
	bool UpdateFTMatrix(CharStyle style);
	CharInfo * NewChar(YOSEFUInt64 charID,YOSEFUInt32 unicodeChar, CharStyle style, YOSEFSInt8 size, YOSEFSInt8 outlineSize, YOSEFSInt8 shadow_x, YOSEFSInt8 shadow_y);
	bool CreateChar(YOSEFUInt32 unicodeChar, CharStyle style, YOSEFSInt8 size, CharInfo**charInfo, YOSEFSInt8 outlineSize = 0, YOSEFSInt8 shadow_x = 0, YOSEFSInt8 shadow_y = 0);
	void CachingChar(CharInfo *tempChar, YOSEFUInt64 charID, YOSEFUInt8*charData);
public:
	static DynamicFont* mDefaultFont;
	static std::unordered_map<std::string, DynamicFont*> mCachedFonts;
	static bool CreateDisplayChar(const char*fontName, YOSEFUInt32 unicodeChar, CharStyle style, YOSEFSInt8 size, CharInfo**charInfo, YOSEFSInt8 outlineSize = 0, YOSEFSInt8 shadow_x = 0, YOSEFSInt8 shadow_y = 0);
	static void InitFTLib();
	static DynamicFont* GetFont(const char*fontName);
	static void CheckChar(YOSEFUInt32&unicodeChar);
public:
	DECLEAR_YOSEF_CLASS(DynamicFont)
};
}
