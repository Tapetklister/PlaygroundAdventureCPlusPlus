#pragma once

#include <iostream>
#include <map>

using namespace std;

class Location
{
public:
	Location();
	Location(string name, string description, map<string, int> exitPoints, int id);
	~Location();

	const string &getName() const;
	const string &getDescription() const;
private:
	string _name;
	string _description;
	map <string, int> _exitPoints;
	int _id;
};

