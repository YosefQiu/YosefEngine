#pragma once
/*
这里主要是用于跨平台的Socket宏定义
*/
#include "Runtime/RuntimePrefix.h"
#ifdef YOSEF_PLATFORM_WIN
#define YOSEFSocket SOCKET
#define YOSEFFDSet fd_set
#define YOSEFAddressInfo addrinfo
#define NewSocket socket
#define YOSEFCloseSocket closesocket
#elif YOSEF_PLATFORM_UNIX
#define NewSocket socket
#define YOSEFFDSet fd_set
#define YOSEFAddressInfo addrinfo
#define YOSEFSocket int
#define YOSEFCloseSocket close
#endif
namespace YOSEF {
	int GetHostFromURL(const char *url, int len, char *host);
	int GetPortFromHost(const char *host, int len);
	void TrimPortFromHost(char *host, int len);
	extern int gConnectTimeOut;
	bool CanRead(YOSEFSocket fd, int second = 0, int ms = 0);
	bool CanWrite(YOSEFSocket fd, int second = 0, int ms = 0);
	YOSEFSocket ConnectWithSpecificProtocol(const char *peer, int port,int port6, int protocol, bool confirm_connection);
	YOSEFSocket ConnectSocket(const char *peer, int port, int portv6, bool confirm_connection);
	//进行异步链接的时候，不能保证能链接成功，所以指定协议版本
	YOSEFSocket AsyncConnectSocket(const char *peer, int port, int portv6,int protocol=AF_UNSPEC);
	//最后一个参数表示，是否保证该链接成功，如果不检测，则需要应用层来保证该链接已经成功
	//最后一个参数传入true，则可以让整个socket变成异步的方式，使得链接的时候不会卡顿
	YOSEFSocket ConnectPeer(YOSEFAddressInfo*address_info, int port, int port6, bool confirm_connection);
	void MakeSocketUnblock(YOSEFSocket fd);
	void MakeSocketBlock(YOSEFSocket fd);
	bool GetIPAddress(const char* domain_name, int ipversion, char * ip);
}