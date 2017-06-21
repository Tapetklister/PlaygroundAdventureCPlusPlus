#include "stdafx.h"
#include "Location.h"


Location::Location()
{
}


Location::Location(string name, string description, map<string, int> exitPoints, int id)
{
	_name = name;
	_description = description;
	_exitPoints = exitPoints;
	_id = id;
}

Location::~Location()
{
}

const string & Location::getName() const
{
	return _name;
}

const string & Location::getDescription() const
{
	return _description;
}

const int & Location::getID() const
{
	return _id;
}
