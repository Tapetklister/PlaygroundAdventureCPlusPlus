#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	nextMove = "";
	player;
}


Game::~Game()
{
}

void Game::handleInput() {

	cin >> nextMove;

	if (nextMove == "test")
	{
		
	}
}

bool Game::getIsGameOver() const
{
	return this->isGameOver;
}
