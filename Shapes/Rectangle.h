#pragma once
#include <format>
#include "Shape.h"
class Rectangle : public Shape{

	int A, B;
public:
	Rectangle(string name, int A, int B);
	string Show() override { cout << format("A,C {}cm, B,D {}cm", A, B); }
	bool Save() override {

	}
	vector<Shape*> Load() override {

	}
};

