#pragma once
#include "Runtime/RuntimePrefix.h"
#include "Runtime/Plugins/freeimage/FreeImage.h"
#include "Runtime/IO/YOSEFData.h"
namespace YOSEF{
	int RawImage2Uncompressed32BITRGBA(unsigned char * const data, int dataLen, YOSEF::Data&outPixel, int&width, int&height);
	bool GetImageInfo(unsigned char * const data, int dataLen,int&width, int&height,int&bpp);
	bool SaveFreeTypeFontToPNG32(const char*filePath, YOSEFUInt8*imageData, YOSEFSInt32 width, YOSEFSInt32 height);
	bool SaveRGBAToPNG32(const char*filePath, YOSEFUInt8*imageData, YOSEFSInt32 width, YOSEFSInt32 height);
	bool SaveRGBToJPEG24(const char*filePath, YOSEFUInt8*imageData, YOSEFSInt32 width, YOSEFSInt32 height);
	bool SaveRToJPEG8(const char*filePath, YOSEFUInt8*imageData, YOSEFSInt32 width, YOSEFSInt32 height);
	void BGRAToRGBA(unsigned char * pixel, int width, int height);
	void BGRToRGB(unsigned char * pixel, int width, int height);
	void AlphaToRGBA(unsigned char luminance,unsigned char * pixel, int width, int height, unsigned char *out);
	YOSEFAny GenAlphaGradiantQuadImage(int size,float e=8.0f);
	YOSEFAny GenRGBImage(int width, int height, YOSEFUInt8 r,YOSEFUInt8 g,YOSEFUInt8 b);
	class ImageUtils{
	public:
		static void Init();
		static void OnImageOperationException(FREE_IMAGE_FORMAT fif, const char *message);
	};
}