#pragma once

#include <iostream>

using namespace std;

class Item
{
public:
	Item();
	Item(string name, string buyCommand, int price, int id);
	~Item();

	string getName();
	string getBuyCommand();
	int getPrice();
	int getID();
private:
	string _name;
	string _buyCommand;
	int _price;
	int _id;
};

