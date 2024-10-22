#pragma once
#include <iostream>
#include <sqlite3.h>
#include "format"
#include "Shape.h"

class Square : private Shape{
private:
	//from left top angle to rigth;

	int A;
public:
	Square(string name, int A) 
		:   Shape(name), A{ A } {	}
	string Show() override { cout << format("A,B,C,D {}cm", A); }
	vector<Shape*> Load() override{
		sqlite3* DB;
		int errors = sqlite3_open(getDir(), &DB);
		if (errors != SQLITE_OK) {
			return {};
		}

	}
	
};

