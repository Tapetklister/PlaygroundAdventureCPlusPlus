#pragma once

#include <string>
#include <iostream>

#include "Player.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void handleInput();

	bool getIsGameOver() const;

private:
	string nextMove;
	bool isGameOver = false;
	Player player;
};

