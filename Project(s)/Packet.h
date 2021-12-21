#pragma once
#include<iostream>
#include <stdio.h>
#include <Winsock2.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdio>

#define PORT 4578
#define PACKET_SIZE 1024
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
	
	void see();
	int* newArray(int size);
	void setIndexArray(int index, int Value);
	bool compare(int size, int totalSize);
	void sorting();

	
	void putArray(int input);
	int recvPacket();
	int sendPacket();
	int gap();

	char sendArray[20];
	int intArray[7];

private:
	SOCKET hClient;
	SOCKET hListen;
	int sendNumber;
	int* purposeNumbers;
	int purposeSize;

	int a[3];
};

