#include "stdafx.h"
#include <iostream>

#include "Player.h"

using namespace std;

Player::Player()
{
	_hp = 100;
	_gold = 0;
	_items;
}


Player::~Player()
{
}

const int &Player::getHP() const
{
	return _hp;
}

const int &Player::getGold() const
{
	return _gold;
}

const vector<Item> *Player::getItems() const
{
	return &_items;
}

void Player::viewStatus() const
{
	cout << "HP: " << getHP() << " Gold: " << this->getGold() <<endl;
}

void Player::addItem(const Item & item)
{
	_items.push_back(item);
}

void Player::takeDamage(int damageTaken)
{
	_hp -= damageTaken;
}

void Player::increaseGold(int goldAwarded)
{
	_gold += goldAwarded;
}
