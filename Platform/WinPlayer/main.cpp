#include <windows.h>
#include "Runtime/Base/Object.h"
#include "Runtime/Utils/LinkedList.h"

#if _DEBUG
#pragma comment( linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

extern "C" void YOSEFGo(HINSTANCE, HINSTANCE, LPSTR, int);

INT WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	YOSEFGo(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
	return 0;
}