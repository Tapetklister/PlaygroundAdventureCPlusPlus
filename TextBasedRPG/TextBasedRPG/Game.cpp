#include "stdafx.h"
#include <string>
#include <random>

#include "Game.h"

Game::Game()
{

	_nextMove = "";
	_isGameOver = false;
	_handler;
	_currentLocation;
	_player;

	_currentLocation = _handler.getLocation(0);
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

bool Game::getIsGameOver() const
{
	return this->_isGameOver;
}

void Game::moveTo(int id)
{
	_currentLocation = _handler.getLocation(id);
	cout << _currentLocation.getDescription() << endl;
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

	cout << _currentLocation.getID() << endl;

	if (_currentLocation.getID() == 0)
	{
		if (nextMove == "west")
			moveTo(1);
		if (nextMove == "east")
			moveTo(2);
		if (nextMove == "south")
			moveTo(3);
		if (nextMove == "north")
			moveTo(4);
	}
	else if (_currentLocation.getID() == 1 && nextMove == "kill monster")
	{
		killMonster();
	}
	else if (_currentLocation.getID() == 1)
	{
		if (nextMove == "east")
		{
			moveTo(0);
		}
	}
	else if (_currentLocation.getID() == 2)
	{
		if (nextMove == "west")
		{
			moveTo(0);
		}
	}
	else if (_currentLocation.getID() == 3)
	{
		if (nextMove == "north")
		{
			moveTo(0);
		}
	}

}

void Game::killMonster()
{
	random_device random;
	int damageTaken = (random() % 20) + 1;
	int awardedGold = (random() % 10) + 1;

	_player.takeDamage(damageTaken);
	_player.increaseGold(awardedGold);
}