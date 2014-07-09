#include "SERVER.h"

using namespace std;

void SERVER()
{
	long SUCCESSFUL;
	WSADATA WinSockData;
	WORD DLLVERSION;

	DLLVERSION =MAKEWORD(2,1);

	SUCCESSFUL=WSAStartup(DLLVERSION,&WinSockData);

	SOCKADDR_IN ADDRESS;
	int AddressSize=sizeof(ADDRESS);

	SOCKET sock_LISTEN;
	SOCKET sock_CONNECTION;

	sock_CONNECTION = socket(AF_INET,SOCK_STREAM,NULL);
	ADDRESS.sin_addr.s_addr=inet_addr("127.0.0.1");
	ADDRESS.sin_family=AF_INET;
	ADDRESS.sin_port=htons(12345);

	sock_LISTEN=socket(AF_INET,SOCK_STREAM,NULL);
	bind(sock_LISTEN,(SOCKADDR*)&ADDRESS,sizeof(ADDRESS));
	listen(sock_LISTEN,SOMAXCONN);

	for(;;)
	{
		cout<<"\n\tSERVER: Waiting for incoming connection...";
		if(sock_CONNECTION=accept(sock_LISTEN,(SOCKADDR*)&ADDRESS,&AddressSize))
		{
			cout<<"\n\tA connection was found!"<<endl;
			SUCCESSFUL=send(sock_CONNECTION,"Welcome you have connected to banana serever",46,NULL);


		}

	}

}