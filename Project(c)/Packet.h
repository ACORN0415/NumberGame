#pragma once
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<winsock.h>

#define sPort 4578
#define BUFSIZE 1024
#define SERVER_IP  "127.0.0.1"
#pragma comment(lib, "ws2_32")
using namespace std;
class Packet
{
public:
	Packet();
	~Packet();

	int getSendNumber() { return sendNumber; }
	int* getPurposeNumbers() { return purposeNumbers; }
	int getPurposeSize() { return purposeSize; }
	char* getSendArray() { return sendArray; }
	int* getIntArray() { return intArray; }

	void setSendNumber(int number) { sendNumber = number; }
	void setPurposeSize(int number) { purposeSize = number; }
	void setPurposeNumbers(int* pointer) { purposeNumbers = pointer; }

	int* newArray(int size);
	void setIndexArray(int index, int Value);
	bool compare(int size,int totalSize);
	
	void seeArray();
	void putNumber(int number);
	void putArray(int input);
	int gap();
	void sorting();

	int recvPacket();
	int sendPacket();

	char sendArray[20];
	int intArray[7];
private:
	SOCKET clntSock;								//SOCKET º¯¼ö

	int sendNumber;
	int* purposeNumbers;
	int purposeSize;
	
	int a[3];
};	
