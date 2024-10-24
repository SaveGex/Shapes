#pragma once
#include <nlohmann/json.hpp>

#include "format"
#include "Shape.h"

using json = nlohmann::json;

class Circle : private Shape{

	int R;
	sqlite3* DB;
	sqlite3_stmt* stmt;
	string name_table = "Square";
	string directory = "./DB/Cirle.db";
public:
	Circle(string name, int R);
	string Show() override;
	bool Save() override;
	vector<Shape*> Load() override;

};

