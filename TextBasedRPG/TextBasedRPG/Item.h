#pragma once

#include <iostream>

using namespace std;

class Item
{
public:
	Item();
	~Item();
private:
	string _name;
	string _buyCommand;
	int _price;
	int _id;
};

