#pragma once
#include "YosefGL.h"
namespace YOSEF{
	enum PremitiveType{
		kPremitiveTypeTriangle,
		kPremitiveTypeTriangleStrip,
		kPremitiveTypeTriangleFan,
		kPremitiveTypePoints,
		kPremitiveTypeLines,
		kPremitiveTypeLineStrip,
		kPremitiveTypeLineLoop,
		kPremitiveTypeCount
	};
	enum RenderingQueue {
		kRenderingQueueSkyBox = 1,
		kRenderingQueueOpaque = 500,
		kRenderingQueueTransparent = 1000,
		kRenderingQueueRenderQueueCount
	};
	enum LightingPass {
		kLightingPassNone = 1,
		kLightingPassOnePass = 2,
		kLightingPassForwardBase = 3,
		kLightingPassForwardAdditive = 4,
		kLightingPassDeffered = 5
	};
	enum RenderArchitecture{
		kRenderArchitectureForward = 1,
		kRenderArchitectureDefered,
		kRenderArchitectureCount
	};
	enum RenderPassCatagory {
		kRenderPassCatagoryNoLit = 1,
		kRenderPassCatagoryOnePass,
		kRenderPassCatagoryForwardBase,
		kRenderPassCatagoryForwardAdd,
		kRenderPassCatagoryShadowCaster,
		kRenderPassCatagoryProjector,
		kRenderPassCatagoryDepthMap,
		kRenderPassCatagoryCount
	};
#define YOSEF_ONE GL_ONE
#define YOSEF_ZERO GL_ZERO
#define YOSEF_SRC_ALPHA GL_SRC_ALPHA
#define YOSEF_SRC_COLOR GL_SRC_COLOR
#define YOSEF_DST_ALPHA GL_DST_ALPHA
#define YOSEF_DST_COLOR GL_DST_COLOR
#define YOSEF_ONE_MINUS_SRC_COLOR GL_ONE_MINUS_SRC_COLOR
#define YOSEF_ONE_MINUS_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
#define YOSEF_ONE_MINUS_DST_COLOR GL_ONE_MINUS_DST_COLOR
#define YOSEF_ONE_MINUS_DST_ALPHA GL_ONE_MINUS_DST_ALPHA
}