#include <iostream>
#include <sqlite3.h>
#include <nlohmann/json.hpp>

#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Elips.h"
using namespace std;
using json = nlohmann::json;

void clear_alloc_memory(vector<Shape*> vector_shapes) {
	for (int i = 0; i < vector_shapes.size(); i++) {
		delete vector_shapes[i];
	}
}
void add_data_in_vector(vector<Shape*>* pvector, vector<Shape*> source) {
	for (int i = 0; i < source.size(); i++) {
		pvector->push_back(source[i]);
	}
}
// I have all shapes is correct!
int main() {
	Square square("square", 10);
	Rectangle rect("rectangle", 15, 100);
	Circle circle("circle", 18);
	Elips elip("Elips", 4, 8, 0, 0);
	square.Save();
	rect.Save();
	circle.Save();
	elip.Save();

	vector<Shape*> vector_shape = square.Load();
	add_data_in_vector(&vector_shape, rect.Load());
	add_data_in_vector(&vector_shape, circle.Load());
	add_data_in_vector(&vector_shape, elip.Load());

	cout << endl;
	string name = vector_shape[0]->getName();
	for (auto i : vector_shape) {
		if (name != i->getName()) {
			cout << endl;
			cout << "_______________________";
			name = i->getName();
		}
		i->Show();
	}
	clear_alloc_memory(vector_shape);
	
	return 0;
}