#include "stdafx.h"
#include <string>

#include "Game.h"

Game::Game()
{

	_nextMove = "";
	_isGameOver = false;
	_handler;
	_currentLocation;
	_player;

	_currentLocation = _handler.getLocation(3);

	_directions[0] = "east";
	_directions[1] = "west";
	_directions[2] = "north";
	_directions[3] = "south";
}


Game::~Game()
{
}

void Game::run() {

	while (!getIsGameOver())
	{
		getline(cin, _nextMove);
		handleInput(_nextMove);
	}
}

void init()
{
}

void Game::handleInput(string nextMove)
{

	if (nextMove == "status")
	{
		_player.viewStatus();
	}
	if (nextMove == "location")
	{
		cout << _currentLocation.getName() << endl;
	}
}

bool Game::getIsGameOver() const
{
	return this->_isGameOver;
}