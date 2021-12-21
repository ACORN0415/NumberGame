#pragma once
#include "Packet.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Game
{
public:
	void startGame();
	void extraction();

	void firstInput();
	void Sendextraction();
	void sendNumber();


private:
	Packet packet;
	Player player;
};

