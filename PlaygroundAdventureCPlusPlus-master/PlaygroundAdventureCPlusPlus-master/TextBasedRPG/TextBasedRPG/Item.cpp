#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}

Item::Item(string name)
{
	_name = name;
}


Item::~Item()
{
}

string Item::getName()
{
	return _name;
}
