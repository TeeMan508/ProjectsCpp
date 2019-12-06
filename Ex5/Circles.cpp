#include "figures.h"
#include <math.h>
#include <iostream>
#include <string>
#define pi 3.14159265358
using namespace std;

circle::circle(double x_, double y_, double r_) {
	x0 = x_;
	y0 = y_;
	r = r_;
	name = "Circle";
}
string circle::getname() const {
	return name;
}
double circle::area() {
	double res =  pi * r * r;
	return res;
}

double circle::perimeter() {
	double res = 2 * pi* r;
	return res;
}

void circle::print_parameters() const {
	cout << name << " "<< x0 <<" " << y0 << " " << r << endl;
}
void circle::Circle_print_results() const {
	circle buf(x0, y0, r);
	//cout << endl;
	cout<< "S=" << buf.area() << " P="<<buf.perimeter()<<endl;
}
