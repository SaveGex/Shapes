#pragma once
#include <format>
#include <nlohmann/json.hpp>
#include <string>
#include "Shape.h"

using json = nlohmann::json;
using namespace std;

class Rectangle : protected Shape{
protected:
	int A, B;
	sqlite3* DB;
	sqlite3_stmt* stmt;
	string name_table = "Rectangle";
	string directory = "./DB/Rectangle.db";
public:
	Rectangle(string name, int A, int B);
	string Show() override;
	bool Save() override;
	vector<Shape*> Load() override;

};

