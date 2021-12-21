#include "Game.h"


void Game::startGame()
{
	packet.recvPacket();

	extraction();

	srand(time(0));
	
	int size = packet.getPurposeSize();

	int newsize = rand()%size + 1;
	
	packet.newArray(newsize);


	for (int i = 0; i < newsize; i++)
	{
		int ten, one;
		packet.intArray[i];
		ten = packet.intArray[i] / 10;
		one = packet.intArray[i] % 10;
		int j = 2 * i + 3;
		packet.sendArray[j] = 48 + ten;
		packet.sendArray[j + 1] = 48 + one;
	}

	packet.sendArray[3 + 2 * packet.getPurposeSize()] = 45;
	packet.sendArray[3 + 2 * packet.getPurposeSize() + 1] = 49;

	packet.sorting();

	cout << "server�� �����ؼ� ��뿡�� ���� ��ǥ���� :";
	for (int i = 0; i < strlen(packet.sendArray); i++)
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
		packet.intArray[i] = 10 * (packet.sendArray[j] -48)+ (packet.sendArray[j + 1]-48);
	}		//intArray ����
}

void Game::Sendextraction()
{

	int i = 0;

	while (packet.sendArray[i] != ' ')
	{
		i++;
	}
	cout << "i�� ���� :" << i<<endl;
	//packet.setPurposeSize(size);			//size
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
		cout << "�۵��� ���� ����";
	}
}

void Game::firstInput()
{
	packet.recvPacket();
	srand(time(0));
	int randNumber = rand() % 5 + 1;
	
	for (int i = 0; i < strlen(packet.sendArray); i++)
	{
		packet.sendArray[i] = ' ';
	}
	
	packet.putArray(randNumber);
	packet.setSendNumber(randNumber);
	packet.sendArray[0] = 49;
	packet.sendArray[1] = 48;
	packet.sendArray[2] = 50;
	packet.sendArray[3] = randNumber + 48;
	packet.sendArray[4] = 45;
	packet.sendArray[5] = 49;
	
	//cout << "server�� ������ ���ڴ�:" << packet.getSendNumber() << endl;
	//cout << "sendArray �� ��峪��?" << endl;
	cout << "server �� ������ ���� :";
	for(int i=0; i<strlen(packet.sendArray); i++)
	{
		cout << packet.sendArray[i];
	}
	cout << endl;
	packet.sendPacket();
}

void Game::sendNumber()
{
	packet.recvPacket();
	Sendextraction();
	
	packet.setSendNumber(packet.getSendNumber() + packet.gap());
	packet.putArray(packet.getSendNumber() + packet.gap());

	if (packet.getSendNumber()< 10)
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
		packet.sendArray[3] = 48+ten;
		packet.sendArray[4] = 48+one;
		packet.sendArray[5] = 45;
		packet.sendArray[6] = 49;
	}
	//cout << "server�� sendNumber�� :" << packet.getSendNumber() << endl;
	cout << "server �� ������ ����:";
	for (int i = 0; i < 7; i++)
	{
		cout << packet.sendArray[i];
	}
	cout << endl;
	packet.sendPacket();
}