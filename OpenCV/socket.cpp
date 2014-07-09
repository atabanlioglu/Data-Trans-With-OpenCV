#include "socket.h"

void socket()
{
	long SUCCESSFUL;
	WSADATA WinSockData;
	WORD DLLVERSION;
	DLLVERSION =MAKEWORD(2,1);
	SUCCESSFUL=WSAStartup(DLLVERSION,&WinSockData);

	string RESPONSE;
	string CONVERTER;
	char MESSAGE[200];

	SOCKADDR_IN ADDRESS;

	SOCKET sock;
	sock=socket(AF_INET,SOCK_STREAM,NULL);
		
	ADDRESS.sin_addr.s_addr=inet_addr("127.0.0.1");
	ADDRESS.sin_family=AF_INET;
	ADDRESS.sin_port=htons(12345);

	
		cout<<"\n\Client: Istek kurulmak isteniyor mu? (Y/N)";
		cin>>RESPONSE;

		RESPONSE[0]=tolower(RESPONSE[0]);

		if(RESPONSE=="n")
		{
			cout<<"\n\tMesaj ulasti.";
		}
		else if(RESPONSE=="y")
		{
			connect(sock,(SOCKADDR*)&ADDRESS,sizeof(ADDRESS));
			SUCCESSFUL=recv(sock,MESSAGE,sizeof(MESSAGE),NULL);
			CONVERTER = MESSAGE;
			cout<<"\n\tSERVER'in mesaji:\n\n\t"<<CONVERTER<<endl;

		}
		else
		{
			cout<<"\n\tBeklenmeyen hareket";
		}
		cout<<"\n\n\t";
		system("pause");
		exit(1);
	

}