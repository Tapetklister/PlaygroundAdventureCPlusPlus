// TextBasedRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#include <iostream>

#include "Game.h"

using namespace std;

int main()
{
	Game game;

	while (!game.getIsGameOver())
	{
		game.handleInput();
	}

    return 0;
}

