#pragma once

#include <iostream>
#include <vector>

#include "Item.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();

	const int &getHP() const;
	const int &getGold() const;
	const vector<Item> *getItems() const;

	void viewStatus() const;
	void addItem(const Item &item);
	void takeDamage(int damageTaken);
	void increaseGold(int goldAwarded);

private:
	int _hp;
	int _gold;
	vector<Item> _items;
};

