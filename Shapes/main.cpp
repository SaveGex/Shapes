#include <iostream>
#include <sqlite3.h>
#include <nlohmann/json.hpp>

#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;
using json = nlohmann::json;

void clear_alloc_memory(vector<Shape*> vector_shapes) {
	for (int i = 0; i < vector_shapes.size(); i++) {
		delete vector_shapes[i];
	}
}
// I have all shapes is correct!
int main() {
	const string dir_rectangle = "./Rectangle.db";
	const string dir_circle = "./Circle.db";

	Square square("square", 10);
	Rectangle rect("rectangle", 5, 10);
	Circle cirle("circle", 8);

	rect.Show();
	square.Show();
	square.Save();
	vector<Shape*> vector_shape = square.Load();
	for (auto i : vector_shape) {
		i->Show();
	}
	clear_alloc_memory(vector_shape);
	
	return 0;
}