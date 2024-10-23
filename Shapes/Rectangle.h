#pragma once
#include <format>
#include <nlohmann/json.hpp>

#include "Shape.h"

using json = nlohmann::json;


class Rectangle : private Shape{

	int A, B;
public:
	Rectangle(string name, int A, int B);
	string Show() override { 
		cout << format("\nname: {}\nA,C {}cm, B,D {}cm", name, A, B); 
		return format("\nname: {}\nA,C {}cm, B,D {}cm", name, A, B);
	}
	bool Save() override {
		return true;

	}
	vector<Shape*> Load() override {
		return {};
	}
};

