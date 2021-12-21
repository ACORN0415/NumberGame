#include<iostream>
#include "Game.h"
#include "Packet.h"
#include "Player.h"

using namespace std;

int main()
{
	Game game;
	game.startGame();
	game.firstInput();
	game.sendNumber();
	game.sendNumber();
	game.sendNumber();
	game.sendNumber();
	game.sendNumber();
	return 0;
}