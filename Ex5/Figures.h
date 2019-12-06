#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <string>

class figure {
protected:
	std::string name;
	double a;
	double p;
public:
	virtual std::string getname() const = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual void print_parameters() const = 0;
};

class circle:public figure {
private:
	double x0, y0, z0, r;
public:
	circle(double x_, double y_, double r_);
    std::string getname() const;
	double area();
	double perimeter();
	void print_parameters() const;
	void Circle_print_results() const;
};

class triangle :public figure {
private:
	double x1, y1, x2, y2, x3, y3;
public:
	triangle(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_);
	std::string getname() const;
	double area();
	double perimeter();
	void print_parameters() const;
	void Triangle_print_results() const;
};
	