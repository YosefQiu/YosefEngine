#pragma once
#include "Runtime/Base/Object.h"
#include "Runtime/Utils/LinkedList.h"
#include "Runtime/Font/DynamicFont.h"
#include "Runtime/Render/VertexData.h"
#include "Runtime/Render/DrawCall.h"
#include "Runtime/Scene/RendererManager.h"
#include "Runtime/Font/CharInfo.h"
#include "Runtime/String/StringUtils.h"

namespace YOSEF{
	class DisplayChar :public DoubleLinkedList{
	public:
		CharInfo*mCharInfo;
		YOSEFUInt32 mCharCode;
		bool mbCustomColor;
		float mFrameWith;
		Color4B mColor;
		YOSEFUInt16 mIndex;
		DisplayChar();
		virtual ~DisplayChar();
		float GetFrameWidth();

		float GetCharLeft(float startPoint);
		float GetCharRight(float startPoint);

		bool InitCharInfoWithFontName(const char*fontName, const UTF32Char &charCode, CharStyle style, YOSEFSInt32 size, YOSEFSInt32 outlineSize, YOSEFSInt32 shadowX, YOSEFSInt32 shadowY);
		bool InitCharInfoWithFont(DynamicFont*font, const UTF32Char &charCode, CharStyle style, YOSEFSInt32 size, YOSEFSInt32 outlineSize, YOSEFSInt32 shadowX, YOSEFSInt32 shadowY);
		void Render(RenderQueue*rq
#if YOSEF_EDITOR
			, DrawCallInfo &rs
#endif
		);
	};
}
