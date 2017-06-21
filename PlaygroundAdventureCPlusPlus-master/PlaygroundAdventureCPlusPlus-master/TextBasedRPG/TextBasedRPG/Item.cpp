#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}

Item::Item(string name, string buyCommand, int price, int id)
{
	_name = name;
	_buyCommand = buyCommand;
	_price = price;
	_id = id;
}


Item::~Item()
{
}

string Item::getName()
{
	return _name;
}

string Item::getBuyCommand()
{
	return _buyCommand;
}

int Item::getPrice()
{
	return _price;
}

int Item::getID()
{
	return _id;
}