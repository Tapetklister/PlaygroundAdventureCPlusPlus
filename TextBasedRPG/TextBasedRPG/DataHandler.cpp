#include "stdafx.h"
#include "DataHandler.h"


DataHandler::DataHandler()
{
	setupDirections();
	setupLocations();
}


DataHandler::~DataHandler()
{
}

void DataHandler::setupDirections()
{
	map <string, int> directionMap1;
	directionMap1.insert(pair<string, int>("west", 0));
	directionMap1.insert(pair<string, int>("east", 1));
	directionMap1.insert(pair<string, int>("south", 2));
	directionMap1.insert(pair<string, int>("north", 3));

	map <string, int> directionMap2;
	directionMap2.insert(pair<string, int>("east", 0));

	map <string, int> directionMap3;
	directionMap3.insert(pair<string, int>("west", 0));

	map <string, int> directionMap4;
	directionMap4.insert(pair<string, int>("north", 0));

	_locDirections.insert(make_pair(0, directionMap1));
	_locDirections.insert(make_pair(1, directionMap2));
	_locDirections.insert(make_pair(2, directionMap3));
	_locDirections.insert(make_pair(3, directionMap4));
}

void DataHandler::setupLocations()
{
	_locations[0] = Location("the Crossroads", "You are standing at the Crossroads. The sun is shining down throught the foilage", _locDirections[0], 0);
	_locations[1] = Location("the Plains", "You are standing on the Plains of Grinding. Monsters are lined up in a queue, staring at you.", _locDirections[1], 1);
	_locations[2] = Location("the Shop", "You enter the conventiently placed Hero's Shop. A shopkeeper is staring at you.", _locDirections[2], 2);
	_locations[3] = Location("the Pool of Rejuvenation", "You enter the Pool of Rejuventaion.You feel power surge through you.", _locDirections[3], 3);
	_locations[4] = Location("the Cave", "You run straight into the cave, shouting out your own name, swinging your sword above your head.", _locDirections[4], 4);
}

const Location DataHandler::getLocation(const int id)
{
	return _locations[id];
}
