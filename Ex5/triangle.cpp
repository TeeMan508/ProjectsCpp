#include "Figures.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

triangle::triangle(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_) {
	x1 = x1_;
	y1 = y1_;
	x2 = x2_;
	y2 = y2_;
	x3 = x3_;
	y3 = y3_;
	name = "Triangle";
}
string triangle::getname() const {
	return name;
}
double triangle::area() {
    return abs(0.5*(x1 - x3)*(y2 - y3) - 0.5*(x2 - x3)*(y1 - y3));
}
double triangle::perimeter() {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) + sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)) + sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
}

void triangle::print_parameters() const {
	cout << name << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}
void triangle::Triangle_print_results() const {
	triangle buf(x1, y1, x2, y2, x3, y3);
	//cout << endl;
	cout << "S=" << buf.area() << " P=" << buf.perimeter() << endl;
}
