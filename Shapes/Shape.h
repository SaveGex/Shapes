#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>

using namespace std;

class Shape{
public:
	string name;
	string directory = "";
	Shape(string name, string directory) : name{ name }, directory{ directory } {}
	Shape(string name) : name{ name } { directory = ""; }
	virtual ~Shape() { cout << "parent distructor";	}
	virtual string Show() = 0;
	virtual bool Save() = 0;
	virtual vector<Shape*>Load() = 0;
	const char* getDir() const { return directory.c_str(); }

};

