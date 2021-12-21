#include "Game.h"

void Game::startGame()
{
	int temp;
	srand(time(0));

	packet.setPurposeSize(1 + rand() % 7);
	cout << "��ǥ���� ������ :" << packet.getPurposeSize() << endl;

	packet.newArray(packet.getPurposeSize());		//�����迭 ����
	
	for (int i = 0; i < packet.getPurposeSize(); i++)
	{
		int randNumber = 31 + rand() % 69;
		int ten = randNumber / 10;
		int one = randNumber % 10;
		packet.setIndexArray(i, randNumber);
		int j = 2*i + 3;
		packet.sendArray[j] = 48+ten;
		packet.sendArray[j + 1] = 48+one;
	}
	packet.sendArray[3 + 2*packet.getPurposeSize()] = 45;
	packet.sendArray[3 + 2*packet.getPurposeSize()+1] = 49;
	
	cout << "���� ��뿡�� ������ �迭�� :" << endl;
	for (int i = 0; i < 19; i++)
	{
		cout << packet.sendArray[i];
	}
	cout << endl;
	packet.sendPacket();
}

void Game::extraction()
{
	int size;
	size = strlen(packet.sendArray) - 5;
	packet.setPurposeSize(size/2);			//size
	for (int i = 0; i < size / 2; i++)
	{
		int j = 2 * i + 3;
		packet.intArray[i] = 10 * (packet.sendArray[j] - 48) + (packet.sendArray[j + 1] - 48);
	}		//intArray ����
}


void Game::changeTurn()
{
	packet.recvPacket();
	extraction();
	packet.sorting();
	/*�� �迭�� �����ؼ� ����� �迭
	cout << "�̰��� intARray[i] " << endl;
	for (int i = 0; i < packet.getPurposeSize(); i++)
	{
		cout << packet.intArray[i];
	}
	*/
	packet.sendPacket();
}
void Game::firstInput()
{
	packet.recvPacket();
	Sendextraction();
	int randNumber;
	srand(time(0));
	randNumber = rand() % 5 + 1;
	randNumber = packet.getSendNumber() + randNumber;
	
	packet.putArray(randNumber);
	packet.setSendNumber(randNumber);
	//cout << "first client Number �̰� ���;���:" << packet.getSendNumber();
	if (randNumber < 10)
	{
		packet.sendArray[0] = 49;
		packet.sendArray[1] = 48;
		packet.sendArray[2] = 50;
		packet.sendArray[3] = randNumber + 48;
		packet.sendArray[4] = 45;
		packet.sendArray[5] = 49;
	}
	else
	{
		packet.sendArray[0] = 49;
		packet.sendArray[1] = 48;
		packet.sendArray[2] = 50;
		packet.sendArray[3] = 49;
		packet.sendArray[4] = 48;
		packet.sendArray[5] = 45;
		packet.sendArray[6] = 49;
	}
	//cout << "client ������ ��: " << packet.getSendNumber() << endl;
	cout << "client �� ������ ���� :";
	for (int i = 0; i < strlen(packet.sendArray); i++)
	{
		cout << packet.sendArray[i];
	}
	cout << endl;
	packet.sendPacket();
}

void Game::Sendextraction()
{
	int size;
	int i = 0;
	size = strlen(packet.sendArray);

	while (packet.sendArray[i] != ' ')
	{
		i++;
	}
	cout << "i�� ���� :" << i<<endl;
	if (i == 6)
	{
		packet.putArray(packet.sendArray[3] - 48);
		packet.setSendNumber(packet.sendArray[3] - 48);

	}
	else if (i == 7)
	{
		int x = packet.sendArray[3];
		int y = packet.sendArray[4];
		cout << "x�� �� : " << x << "y�� �� " << y;
		//packet.putArray((10 * (packet.sendArray[3] - 48)) + packet.sendArray[4] - 48);
		//packet.setSendNumber((10 * (packet.sendArray[3] - 48)) + packet.sendArray[4] - 48);
		cout << "sendNumber�� ���� :" << packet.getSendNumber() << endl;
	}
	else
	{
		cout << "�۵��� ����";
	}

	/*
	if (size == 1)
	{
		packet.putArray(packet.sendArray[3] - 48);
		packet.setSendNumber(packet.sendArray[3] - 48);
	}
	else if(size==2)
	{
			packet.putArray(10 * (packet.sendArray[3] - 48) + (packet.sendArray[4] - 48));
			packet.setSendNumber(10 * (packet.sendArray[3] - 48) + (packet.sendArray[4] - 48));
	}
	*/
}
void Game::sendNumber()
{
	packet.recvPacket();
	Sendextraction();

	packet.setSendNumber(packet.getSendNumber() + packet.gap());
	packet.putArray(packet.getSendNumber() + packet.gap());

	if (packet.getSendNumber() < 10)
	{
		packet.sendArray[0] = 49;
		packet.sendArray[1] = 48;
		packet.sendArray[2] = 50;
		packet.sendArray[3] = packet.getSendNumber() + 48;
		packet.sendArray[4] = 45;
		packet.sendArray[5] = 49;
	}
	else
	{
		int ten, one;
		ten = packet.getSendNumber() / 10;
		one = packet.getSendNumber() % 10;
		packet.sendArray[0] = 49;
		packet.sendArray[1] = 48;
		packet.sendArray[2] = 50;
		packet.sendArray[3] = 48 + ten;
		packet.sendArray[4] = 48 + one;
		packet.sendArray[5] = 45;
		packet.sendArray[6] = 49;
	}
	//cout << "client�� sendNumber�� :" << packet.getSendNumber() << endl;
	cout << "client �� ������ ���� :";
	for (int i = 0; i < 7; i++)
	{
		cout << packet.sendArray[i];
	}
	cout << endl;
	packet.sendPacket();
}

void Game::addScore()
{

}

