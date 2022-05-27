#include "RendererManager.h"
#include "Runtime/Allocator/DefaultAllocator.h"
#include "Runtime/IO/ResourceManager.h"
#include "Runtime/IO/FileSystem.h"
namespace YOSEF{
	static RendererManager * spRenderManager=nullptr;
	RendererManager::RendererManager(){
		mRenderArchitecture = kRenderArchitectureForward;
	}
	void RendererManager::InitDynamicFontMaterial(){
	}
	void RendererManager::InitVideoSpriteMaterial() {
	}
	void RendererManager::InitDefault2DMaterial(){
	}
	void RendererManager::InitDefaultColorMaterial() {
	}
	void RendererManager::InitDefaultSimpleColorMaterial() {
	}
	void RendererManager::InitDefaultFrameBufferRenderMaterial() {
	}
	void RendererManager::InitStencilRenderMaterial() {
	}
	RendererManager&GetRendererManager()
	{
		if (spRenderManager==nullptr)
		{
			spRenderManager = new RendererManager();
		}
		return *spRenderManager;
	}
}
