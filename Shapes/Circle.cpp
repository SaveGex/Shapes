#include "Circle.h"



Circle::Circle(string name, int R)
	: Shape::Shape(name), R{R}{

}

string Circle::Show() {
	cout << format("\nname: {}Radius: {}", name, R); 
	return format("\nname: {}Radius: {}", name, R);
}
