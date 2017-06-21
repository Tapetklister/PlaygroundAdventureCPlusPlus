#pragma once

#include "Location.h"
#include <map>

class DataHandler
{
public:
	DataHandler();
	~DataHandler();

	void setupDirections();
	void setupLocations();

	const Location getLocation(const int id);

private:
	Location _locations[5];
	map <int, map<string, int>> _locDirections;
};