#include "Runtime/IO/ResourceManager.h"
#if YOSEF_IPHONE || YOSEF_OSX_PLAYER
#include "IOSBundleManager.h"
#elif YOSEF_ANDROID
#include "AndroidAssetReader.h"
#endif
#include "Runtime/String/StringUtils.h"
#include "FileSystem.h"
#include "YosefResource.h"

namespace YOSEF
{
	//static char *sOuterRootPath = nullptr;
	FixedString*ResourceManager::mAssetsDir = nullptr;
	FixedString*ResourceManager::mDataDir = nullptr;
    FixedString*ResourceManager::mDocumentDir = nullptr;
    FixedString*ResourceManager::mDesktopDir = nullptr;
	bool ResourceManager::Exist(const char*path) {
		return FileSystem::Exists(path);
	}
	bool ResourceManager::DeleteFileWithPath(const char*path) {
#if YOSEF_WIN_PLAYER
		return FileSystem::DeleteFileWithPath(path);
#elif YOSEF_OSX_PLAYER || YOSEF_IPHONE
		return IOSBundleManager::DeleteFileWithPath(path);
#elif YOSEF_ANDROID
		return AndroidAssetReader::DeleteFileWithPath(path);
#endif
		return false;
	}
	bool ResourceManager::CreateDir(const char*path) {
		return FileSystem::CreateDir(path);
	}
	bool ResourceManager::DeleteDir(const char*path) {
#if YOSEF_WIN_PLAYER
        return FileSystem::DeleteDir(path);
#elif YOSEF_OSX_PLAYER || YOSEF_IPHONE
        return IOSBundleManager::DeleteDir(path);
#elif YOSEF_ANDROID
		return AndroidAssetReader::DeleteDir(path);
#endif
		return false;
	}
    void ResourceManager::GetItemListInDirectory(lua_State *L, const char *path){
#if YOSEF_WIN_PLAYER
        FileSystem::GetItemListInDirectory(L, path);
#elif YOSEF_OSX_PLAYER || YOSEF_IPHONE
        IOSBundleManager::GetItemListInDirectory(L, path);
#elif YOSEF_ANDROID
		AndroidAssetReader::GetItemListInDirectory(L, path);
#endif
    }
	void ResourceManager::CopyInternalFileOut(const char*internalPath) {
		YOSEF::Data src;
#if YOSEF_OSX_PLAYER || YOSEF_IPHONE
		YOSEF::ResourceManager::LoadInternalData(internalPath, src);
#elif YOSEF_ANDROID
		AndroidAssetReader::LoadInternalData(internalPath, src);
#endif
		if (src.mDataLen != 0) {
			char szFullPath[256];
			memset(szFullPath, 0, 256);
			strcpy(szFullPath, YOSEF::ResourceManager::mDataDir->mText);
			strcat(szFullPath, internalPath);
			FILE *pFile = fopen(szFullPath, "wb");
			if (pFile) {
				fwrite(src.mData, 1, src.mDataLen, pFile);
				fclose(pFile);
			}
		}
	}
	bool ResourceManager::ExistInternal(const char*path){
		char szFullPath[256];
		memset(szFullPath, 0, 256);
#if YOSEF_EDITOR
		strcpy(szFullPath, "Assets/");
		strcat(szFullPath, path);
		return FileSystem::Exists(szFullPath);
#endif
		return false;
	}


	bool ResourceManager::CreateInternalFile(const char*targetPath)
	{
#if YOSEF_EDITOR
		char szFullPath[256];
		memset(szFullPath, 0, 256);
		strcpy(szFullPath, "Assets/");
		strcat(szFullPath, targetPath);
		return FileSystem::CreateFile(szFullPath);
#else
		return false;
#endif
	}

	bool ResourceManager::SaveInternalData(const char*path, Data&data)
	{
		char szFullPath[256];
		memset(szFullPath, 0, 256);
#if YOSEF_EDITOR
		strcpy(szFullPath, "Assets/");
		strcat(szFullPath, path);
		return FileSystem::SaveData(szFullPath, data);
#else
		return false;
#endif
		return false;
	}

	bool ResourceManager::RenameInternalFileName(const char*srcFile, const char*dstFile)
	{
		char srcPath[256],dstPath[256];
		memset(srcPath, 0, 256);
		memset(dstPath, 0, 256);
#if YOSEF_EDITOR
		strcpy(srcPath, "Assets/");
		strcpy(dstPath, "Assets/");
		strcat(srcPath, srcFile);
		strcat(dstPath, dstFile);
		return FileSystem::MoveFile(srcPath, dstPath);
#else
		return false;
#endif
		return false;
	}

	bool ResourceManager::CopyFileToInternal(const char*srcFile, const char*dstFile)
	{
		char dstPath[256];
		memset(dstPath, 0, 256);
#if YOSEF_EDITOR
		strcpy(dstPath, "Assets/");
		strcat(dstPath, dstFile);
		return FileSystem::CopyFile(srcFile, dstPath);
#else
		return false;
#endif
		return false;
	}

	bool ResourceManager::MoveInternalFile(const char*srcFile, const char*dstFile)
	{
		char srcPath[256];
		char dstPath[256];
		memset(srcPath, 0, 256);
		memset(dstPath, 0, 256);
#if YOSEF_EDITOR
		strcpy(dstPath, "Assets/");
		strcat(dstPath, dstFile);
		strcpy(srcPath, "Assets/");
		strcat(srcPath, srcFile);
		return FileSystem::MoveFile(srcPath, dstPath);
#else
		return false;
#endif
		return false;
	}

	bool ResourceManager::DeleteInternalFile(const char*targetFile)
	{
		char srcPath[256];
		memset(srcPath, 0, 256);
#if YOSEF_EDITOR
		strcpy(srcPath, "Assets/");
		strcat(srcPath, targetFile);
		return FileSystem::DeleteDir(srcPath);
#else
		return false;
#endif
		return false;
	}
	//guid/builtin resource :
	//     in editor : cache path
	//     in win player : data path
	//     android,ios,osx player : data path
	//user path:
	//	   Dev,Editor : Assets path
	//
	bool ResourceManager::LoadDataFromRuntimeDataPath(const char*path, Data&data, FixedString *realPath /* = nullptr */) {
		//in this mode path may be a guid or a relative path inside 'Assets' folder
		const char * guid = Resource::GetResourceGUIDViaUserName(path);//if it's a relative path inside 'Assets' folder,there would be a guid
		const char *target = guid == nullptr ? path : guid;
		if (LoadOuterData(target, data)) {//this method can load files inside the 'Data' path
			if (realPath != nullptr) {
				(*realPath) = target;
			}
			return true;
		}
		return false;
	}
	bool ResourceManager::LoadDataFromBuiltinDataPath(const char*path, Data&data, FixedString *realPath /* = nullptr */) {
		//in this mode path may be a guid or a relative path inside 'Assets' folder
		const char * guid = Resource::GetResourceGUIDViaUserName(path);//if it's a relative path inside 'Assets' folder,there would be a guid
		//1、Editor mode : relative path
		//2、Win Player Runtime mode : relative path -> guid (or relative path is guid eg:builtin/xx/xx)
		//3、Win Player Dev Runtime mode : relative path (or relative path is guid eg:builtin/xx/xx)
		//4、Android Player Runtime mode : relative path -> guid (or relative path is guid eg:builtin/xx/xx)
		//5、OSX Player Runtime mode : relative path -> guid (or relative path is guid eg:builtin/xx/xx)
		//6、iOS Player Runtime mode : relative path -> guid (or relative path is guid eg:builtin/xx/xx)
		const char *target = guid == nullptr ? path : guid;
		if (LoadInternalData(target, data)) {//this method can load files from 'Mobile Package files'/'Assets folder files'/'builtin folder files'
			if (realPath != nullptr) {
				(*realPath) = target;
			}
			return true;
		}
		return false;
	}
	bool ResourceManager::LoadData(const char*path, Data&data, FixedString *realPath) {
		if (LoadDataFromRuntimeDataPath(path,data,realPath)){
			return true;
		}
		if (LoadDataFromBuiltinDataPath(path,data,realPath)){
			return true;
		}
		//direct load from the path
		if (FileSystem::LoadDataFromPath(path, data)) {
			if (realPath != nullptr) {
				(*realPath) = path;
			}
			return true;
		}
		return false;
	}

	bool ResourceManager::LoadInternalData(const char*path, Data&data){
		char szFullPath[256];
		memset(szFullPath, 0, 256);
#if YOSEF_EDITOR
		strcpy(szFullPath, mAssetsDir->mText);
		strcat(szFullPath, path);
		return FileSystem::LoadDataFromPath(szFullPath, data);
#elif YOSEF_WIN_PLAYER
		strcpy(szFullPath, mAssetsDir->mText);
		strcat(szFullPath, path);
		return FileSystem::LoadDataFromPath(szFullPath, data);
#elif YOSEF_ANDROID
		strcpy(szFullPath, path);
		StringUtils::TrimFileExtension(szFullPath);
		return AndroidAssetReader::LoadInternalData(szFullPath, data);
#elif YOSEF_IPHONE
		strcpy(szFullPath, "Data/");
		strcat(szFullPath, path);
		return IOSBundleManager::LoadInternalData(szFullPath, data);
#elif YOSEF_OSX_PLAYER
#if _DEBUG
        strcpy(szFullPath, mAssetsDir->mText);
        strcat(szFullPath, path);
        return FileSystem::LoadDataFromPath(szFullPath, data);
#else
        strcpy(szFullPath, "Data/");
        strcat(szFullPath, path);
        return IOSBundleManager::LoadInternalData(szFullPath, data);
#endif
#endif
		return false;
	}

	bool ResourceManager::LoadOuterData(const char*path, Data&data) {
		char szFullPath[256] = { 0 };
#if YOSEF_PLATFORM_WIN
		strcpy(szFullPath, mDataDir->mText);
		strcat(szFullPath, path);
		return FileSystem::LoadDataFromPath(szFullPath, data);
#elif YOSEF_OSX_PLAYER
        strcpy(szFullPath, mDataDir->mText);
        strcat(szFullPath, path);
        return FileSystem::LoadDataFromPath(szFullPath, data);
#elif YOSEF_ANDROID
		strcpy(szFullPath, mDataDir->mText);
		strcat(szFullPath, path);
		return FileSystem::LoadDataFromPath(szFullPath, data);
#elif YOSEF_IPHONE
        strcpy(szFullPath, mDataDir->mText);
        strcat(szFullPath, path);
        return FileSystem::LoadDataFromPath(szFullPath, data);
#endif
	}

	bool ResourceManager::LoadBuiltinData(const char*path, Data&data)
	{
#if YOSEF_EDITOR
		return FileSystem::LoadDataFromPath(path,data);
#elif YOSEF_WIN_PLAYER
		char szFullDataPath[256];
		memset(szFullDataPath, 0, 256);
		strcpy(szFullDataPath, "Data/");
		strcat(szFullDataPath, path);
		return FileSystem::LoadDataFromPath(szFullDataPath, data);
#elif YOSEF_ANDROID
		return AndroidAssetReader::LoadInternalData(path, data);
#elif YOSEF_IPHONE || YOSEF_OSX_PLAYER
		LoadInternalData(path, data);
#endif
		return false;
	}
	int ResourceManager::UnloadResource(lua_State*L){
		return 0;
	}
	int ResourceManager::AssetsPath(lua_State*L) {
		lua_pushstring(L, mAssetsDir->mText);
		return 1;
	}
	int ResourceManager::DataPath(lua_State*L) {
		lua_pushstring(L, mDataDir->mText);
		return 1;
	}
	int ResourceManager::DocPath(lua_State*L){
		lua_pushstring(L, mDocumentDir->mText);
		return 1;
    }
    int ResourceManager::DesktopPath(lua_State*L){
        lua_pushstring(L, mDesktopDir->mText);
        return 1;
    }

	void ResourceManager::Init() {
		mAssetsDir = new (kMemDefaultId)FixedString(256);
		mDataDir = new (kMemDefaultId)FixedString(256);
		mDocumentDir = new (kMemDefaultId)FixedString(256);
        mDesktopDir=new (kMemDefaultId)FixedString(256);
#ifdef YOSEF_EDITOR
		(*mAssetsDir) = "Assets/";
		(*mDataDir) = "Data/";
		(*mDocumentDir) = "";
		(*mDesktopDir) = "Code/";
#elif YOSEF_WIN_PLAYER
		(*mAssetsDir) = "Assets/";
		(*mDataDir) = "Data/";
		(*mDocumentDir) = "";
		(*mDesktopDir) = "Code/";
#elif YOSEF_OSX_PLAYER | YOSEF_IPHONE
#if _DEBUG
        (*mAssetsDir) = "Assets/";
        (*mDataDir) = "Data/";
        (*mDocumentDir) = "";
        (*mDesktopDir) = "Code/";
#else
        (*mDocumentDir) = IOSBundleManager::GetOuterDataPath();
        (*mDocumentDir) << "/XEdu/";
		(*mAssetsDir) = (*mDocumentDir);
		(*mAssetsDir) << "Assets/";
		(*mDataDir) = (*mDocumentDir);
		(*mDataDir) << "Data/";
		(*mDesktopDir) = IOSBundleManager::GetDesktopPath();
		(*mDesktopDir) << "/";
#endif
#endif
	}
}
