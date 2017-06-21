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
	_wares.push_back(Item("Charm of Capitalism", "buy charm", 20, 0));
	_wares.push_back(Item("Talisman of Truth", "buy talisman", 100, 1));
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

	if (_currentLocation.getID() == 4)
	{
		finishGame();
	}
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
	else if (_currentLocation.getID() == 2 && (nextMove == "buy charm" || nextMove == "buy talisman"))
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

	if (_player.getHP() > 0)
	{
		_player.increaseGold(awardedGold);
		cout << "You kill the monster without mercy. Mercilessly!" << endl;
		cout << "You take " << damageTaken << " damage. You receive " << awardedGold << " gold." << endl;
	}
	else
	{
		cout << "The monster slams you over the head with a pink squid" << endl;
		cout << "You fall to the ground. You were killed by a squid. Great!" << endl;
		gameOver(false);
	}
}

void Game::checkWares()
{
	cout << "The shopkeeper has the following items in stock:" << endl;

	for (int i = 0; i < _wares.size(); i++)
	{
		cout << _wares.at(i).getName() << endl;
	}
}

void Game::buyWare(string nextMove)
{
	for (int i = 0; i < _wares.size(); i++)
	{
		if (_wares.at(i).getBuyCommand() == nextMove)
		{
			_player.addItem(_wares.at(i));
		}
	}
}

void Game::finishGame()
{
	bool isWinner = false;

	for (int i = 0; i < _player.getItems().size(); i++)
	{
		if (_player.getItems().at(i).getID() == 1)
		{
			isWinner = true;
		}
	}
	gameOver(isWinner);
}

void Game::gameOver(bool isWinner)
{
	string gameOverText;
	if (isWinner) gameOverText = "You are victorious!";
	else gameOverText = "You failed!";

	cout << gameOverText << endl;
	cout << "-----Game Over....." << endl;
	int wait;
	cin >> wait;
	_isGameOver = true;
}