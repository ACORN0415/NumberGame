#include "Packet.h"

Packet::Packet()
{
	WSADATA wsaData;
	SOCKET hServSock;
	SOCKADDR_IN servAddr, clntAddr;
	int szClntAddr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("winsock error!\n");
		exit(1);
	}
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
	{
		printf("socket() error!\n");
		WSACleanup();
		exit(1);
	}
	printf("socket succeed..\n");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(PORT);

	if (bind(hServSock, (sockaddr*)& servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		printf("bind() 오류\n");
		closesocket(hServSock);
		WSACleanup();
		exit(1);
	}

	if (listen(hServSock, 5) == SOCKET_ERROR)
	{
		printf("listen() error");
		WSACleanup();
		closesocket(hServSock);
		exit(1);
	}

	printf("listen succeed..\n");

	szClntAddr = sizeof(clntAddr);

	hClient = accept(hServSock, (SOCKADDR*)& clntAddr, &szClntAddr);
	if (hClient == INVALID_SOCKET || hClient == SOCKET_ERROR)
	{
		printf("accept() error\n");
		WSACleanup();
		closesocket(hServSock);
		exit(1);
	}
	printf("listen succeed..\n");

}

Packet::~Packet()
{
	WSACleanup();
	closesocket(hClient);
	closesocket(hListen);
}

int Packet::recvPacket()
{
	
	return recv(this->hClient, (char*)sendArray, sizeof(sendArray), 0);		//data 12
	
}

int Packet::sendPacket()
{
	return send(hClient, (char*)sendArray, sizeof(sendArray), 0);


}

int* Packet::newArray(int size)
{
	if (size > 0 && purposeNumbers == NULL)
		purposeNumbers = new int[size];
	return purposeNumbers;
}

void Packet::setIndexArray(int index, int Value)
{
	if (purposeNumbers != NULL && index < purposeSize)	//해석
		purposeNumbers[index] = Value;
}

bool Packet::compare(int size, int totalSize)
{

	for (int i = 0; i <= size; i++)
	{
		for (int j = i + 1; j < totalSize; j++)
		{
			purposeNumbers[i] == purposeNumbers[j];
			return -1;
		}
	}
	return 1;
}
void Packet::see()
{
	cout << sendArray[0] << sendArray[1] << sendArray[2] << sendArray[3] << sendArray[4];
}

void Packet::putArray(int input)
{
	a[0] = a[1];
	a[1] = a[2];
	a[2] = input;
}

int Packet::gap()
{
	int gapNum;
	gapNum = a[2] - a[1];
	return gapNum;
}


void Packet::sorting()
{
	for (int j = 0; j < getPurposeSize(); j++)
	{
		for (int i = 0; i < getPurposeSize() - 1; i++)
		{
			if (intArray[i] > intArray[i + 1]) {

				int jemt;
				jemt = intArray[i];
				intArray[i] = intArray[i + 1];
				intArray[i + 1] = jemt;
			}
		}
	}
}
