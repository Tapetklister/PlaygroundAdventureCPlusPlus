#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	hp = 100;
	gold = 0;
}


Player::~Player()
{
}

const int & Player::getHP() const
{
	return hp;
}

const int & Player::getGold() const
{
	return gold;
}
