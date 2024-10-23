#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class Shape {
public:
	string name;
	string directory = "";
	json json_array;
	//Shape(string name, string directory) : name{ name }, directory{ directory } {}
	Shape(string name, json json_array) : name{name}, json_array{json_array} {}
	Shape(string name) : name{ name }, directory{ "./" } {}
	void SetJArray(json jarr) { json_array["json_array"] = jarr; }
	//Shape(string name) : name{ name } { directory = ""; }
	virtual ~Shape() { cout << "\nparent distructor\n";	}
	virtual string Show() = 0;
	virtual bool Save() = 0;
	virtual vector<Shape*>Load() = 0;
	const char* getDir() const { return directory.c_str(); }
	json getJson() { return json_array; }

};

