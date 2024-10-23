#pragma once
#include <iostream>
#include <sqlite3.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include "format"
#include "Shape.h"

using json = nlohmann::json;

class Square : private Shape{
private:
	//from left top angle to rigth for coordinates;

	int A;
	sqlite3* DB;
	sqlite3_stmt* stmt;
	string name_table = "Square";
	string directory = "./DB/Square.db";
public:
	Square(string name, int A); // constructor to open DB in body
	~Square() { sqlite3_close(this->DB); }

	string Show() override { 
		cout << format("\nname:{}\nA,B,C,D {}cm", name, A); 
		return format("\nname:{}\nA,B,C,D {}cm", name, A);
	}

	bool Save() override;
	vector<Shape*> Load() override;

};

