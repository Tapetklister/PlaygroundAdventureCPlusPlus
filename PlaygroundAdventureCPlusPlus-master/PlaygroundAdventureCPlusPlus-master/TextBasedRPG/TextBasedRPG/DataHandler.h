#pragma once

#include "Location.h"
#include <map>
#include <vector>

class DataHandler
{
public:
	DataHandler();
	~DataHandler();

	void setupDirections();
	void setupLocations();

	const Location getLocation(const int id);

	map <int, map<string, int>> _locDirections;

private:
	vector<Location> _locations;
};