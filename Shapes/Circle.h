#pragma once
#include <nlohmann/json.hpp>

#include "format"
#include "Shape.h"

using json = nlohmann::json;

class Circle : private Shape{

	int R;
public:
	Circle(string name, int R);
	string Show() override;
	bool Save() override {
		return true;

	}
	vector<Shape*> Load() override {
		return {};
	}
};

