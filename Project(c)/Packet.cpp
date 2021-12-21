#define _CRT_SECURE_NO_WARNINGS
#include "Packet.h"


Packet::Packet()
{
	WSADATA wsaData;
	SOCKADDR_IN servAddr;

	char sAddr[15];
	int nRcv;
	unsigned int Addr;
	struct hostent* host;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		//ErrorHandling(message1);
		exit(0);
	}

	clntSock = socket(AF_INET, SOCK_STREAM, 0);
	if (clntSock == INVALID_SOCKET)
		//ErrorHandling(message2);

		memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
	servAddr.sin_port = htons(sPort);

	if (connect(clntSock, (sockaddr*)& servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		//ErrorHandling(message3);
	}
	else {
		printf("Server와 연결이 되었습니다!...\n");
	}
	sendArray[0] = 49;
	sendArray[1] = 48;
	sendArray[2] = 49;
}

Packet::~Packet() 
{
	//if (PacketData.purposeNumbers != NULL)delete[]  PacketData.purposeNumbers;
	closesocket(clntSock);
	WSACleanup();
}


int Packet::recvPacket()
{
	
	return recv(clntSock, (char*)sendArray, sizeof(sendArray), 0);

}

int Packet::sendPacket()
{

	return send(clntSock, (char*)sendArray, sizeof(sendArray), 0);
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

bool Packet::compare(int size,int totalSize)
{
	
	for (int i = 0; i <= size; i++)
	{
		for (int j = i+1; j < totalSize; j++)
		{
			purposeNumbers[i] == purposeNumbers[j];
			return -1;
		}
	}
	return 1;
}

void Packet::putNumber(int number)
{
	int ten, one;

	sendArray[0] = 49;
	sendArray[1] = 48;
	sendArray[2] = 49;
	ten = number / 10;
	one = number % 10;

	for (int i =0; i <purposeSize; i++)
	{
		if(i%2==1)
			sendArray[2 * i + 3] = ten;
		if(i%2==0)
			sendArray[2 * i + 4] = one;
	}
	sendArray[3 + 2 * purposeSize] = 45;
	sendArray[3 + 2 * purposeSize+1] = 49;
}

void Packet::seeArray()
{
	for (int i = 0; i < 19; i++)
	{
		cout << sendArray[i];
	}
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
	for (int j = 0; j<getPurposeSize(); j++)
	{
		for (int i = 0; i < getPurposeSize() - 1; i++)
		{
			if(intArray[i] > intArray[i + 1]) {

				int jemt;
				jemt = intArray[i];
				intArray[i] = intArray[i + 1];
				intArray[i + 1] = jemt;
			}
		}
	}
}