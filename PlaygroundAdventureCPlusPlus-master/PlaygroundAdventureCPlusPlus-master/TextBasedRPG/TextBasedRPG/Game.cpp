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
	_wares;
	_wares.push_back(Item("Charm of Capitalism"));
	_wares.push_back(Item("Talisman of Truth"));
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
	else if (_currentLocation.getID() == 2 && nextMove == "look inventory")
	{
		checkWares();
	}
	else if (_currentLocation.getID() == 2 && nextMove == "buy charm")
	{
		buyWare(nextMove);
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

	cout << "You kill the monster without mercy. Mercilessly!" << endl;
	cout << "You take " << damageTaken << " damage. You receive " << awardedGold << " gold." << endl;
}

void Game::checkWares()
{
	cout << "The shopkeeper has the following items in stock:" << endl;
	cout << "-Charm of Capitalism (20 gold)" << endl;
	cout << "-Talisman of Truth (100 gold)" << endl;
}

void Game::buyWare(string nextMove)
{
	if (nextMove == "buy charm")
	{
		_player.addItem(Item("Charm of Capitalism"));
		_wares.erase(_wares.begin());
	}
}
