#include "stdafx.h"
#include <iostream>

#include "Player.h"

using namespace std;

Player::Player()
{
	hp = 100;
	gold = 0;
}


Player::~Player()
{
}

const int &Player::getHP() const
{
	return hp;
}

const int &Player::getGold() const
{
	return gold;
}

const Item *Player::getItems() const
{
	return items;
}

void Player::viewStatus() const
{
	cout << "HP: " << this->getHP() << " Gold: " << this->getGold() <<endl;
}

void Player::addItem(const Item & item)
{
}
