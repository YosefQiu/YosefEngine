#pragma once
/*
������Ҫ�����ڿ�ƽ̨��Socket�궨��
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
	//�����첽���ӵ�ʱ�򣬲��ܱ�֤�����ӳɹ�������ָ��Э��汾
	YOSEFSocket AsyncConnectSocket(const char *peer, int port, int portv6,int protocol=AF_UNSPEC);
	//���һ��������ʾ���Ƿ�֤�����ӳɹ����������⣬����ҪӦ�ò�����֤�������Ѿ��ɹ�
	//���һ����������true�������������socket����첽�ķ�ʽ��ʹ�����ӵ�ʱ�򲻻Ῠ��
	YOSEFSocket ConnectPeer(YOSEFAddressInfo*address_info, int port, int port6, bool confirm_connection);
	void MakeSocketUnblock(YOSEFSocket fd);
	void MakeSocketBlock(YOSEFSocket fd);
	bool GetIPAddress(const char* domain_name, int ipversion, char * ip);
}