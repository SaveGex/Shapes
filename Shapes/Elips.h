#pragma once
#include <string>
#include <nlohmann/json.hpp>

#include "format"
#include "Shape.h"
#include "Rectangle.h"


using namespace std;
using json = nlohmann::json;

class Elips : private Shape{
private:
	//from left top angle to rigth for coordinates;
	int A, B, X, Y;
	sqlite3* DB;
	sqlite3_stmt* stmt;
	string name_table = "Elips";
	string directory = "./DB/Elips.db";
public:
	Elips(string name, int A, int B, int X, int Y);
	~Elips() { sqlite3_close(this->DB); }

	string Show() override;

	bool Save() override;
	vector<Shape*> Load() override;
};

