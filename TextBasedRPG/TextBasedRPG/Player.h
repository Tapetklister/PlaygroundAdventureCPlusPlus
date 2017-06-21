#pragma once

#include <iostream>

#include "Item.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();

	const int &getHP() const;
	const int &getGold() const;
	const Item *getItems() const;

	void viewStatus() const;
	void addItem(const Item &item);

private:
	int hp;
	int gold;
	Item items[];
};

