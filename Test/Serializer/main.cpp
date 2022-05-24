#include <iostream>
#include "Prefab.txt.serializer.h"
using namespace std;

class GameObject
{
public:
	char mName[32];
	int mLayer;
};

class BB
{
public:
	char mName[32];
	int mLayer;
};

void SaveToFile(const char* path, void* buffer, int size)
{
	FILE* file;
	int err = fopen_s(&file, path, "wb");
	if (err == 0)
	{
		fwrite(buffer, sizeof(char), size, file);
		fclose(file);
	}
}

char* GetFileContent(const char* path, int& size)
{
	FILE* file;
	int err = fopen_s(&file, path, "rb");
	if (err == 0)
	{
		fseek(file, 0, SEEK_END);
		int nLen = ftell(file);
		size = nLen;
		char* szBuffer = new char[nLen + 1];
		rewind(file);
		fread(szBuffer, sizeof(char), nLen, file);
		fclose(file);
		szBuffer[nLen] = 0;
		return szBuffer;
	}
	return NULL;
}

int main(int argc, char* argv[])
{
	cout << "Test for Serialize----------" << endl;
	GameObject go;
	memset(go.mName, 0, 32);
	strcpy_s(go.mName, 32, "Yosef");
	go.mLayer = 1;

	char szBuffer[64] = { 0 };
	memcpy(szBuffer, &go, sizeof(go));
	cout << "GameObject" << endl;
	cout << go.mName << " " << go.mLayer << endl;
	SaveToFile("test.prefab", szBuffer, sizeof(go));

	int size = 0;
	char* fileContent = GetFileContent("test.prefab", size);
	BB a;
	memcpy(&a, fileContent, sizeof(BB));
	cout << "BB" << endl;
	cout << a.mName << " " << a.mLayer << endl;
	delete[]fileContent;

	cout << "Proto buffer-----------" << endl;
	GameObject aa;
	memset(aa.mName, 0, 32);
	strcpy_s(aa.mName, 32, "Yoseffffff");
	aa.mLayer = 2;
	XiaoHua::Prefab prefab;
	prefab.set_name(aa.mName);
	prefab.set_layer(aa.mLayer);
	char szBuffer1[128] = { 0};
	prefab.SerializeToArray(szBuffer1, 128);
	cout << "Prefabe size " << prefab.ByteSize() << endl;
	SaveToFile("test1.prefab", szBuffer1, prefab.ByteSize());

	int size1 = 0;
	char* fileco = GetFileContent("test1.prefab", size);
	prefab.ParseFromArray(fileco, size);
	cout << prefab.name() << " " << prefab.layer() << endl;
	system("pause");
	return 0;
}