#pragma once

#include <string>
#include <iostream>

#include "Player.h"
#include "Location.h"
#include "DataHandler.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void init();
	void handleInput(string nextMove);
	void run();
	bool getIsGameOver() const;

private:
	string _nextMove;
	bool _isGameOver = false;
	string _directions[4];
	DataHandler _handler;
	Location _currentLocation;
	Player _player;

	void moveTo(int id);
	void killMonster();
};

