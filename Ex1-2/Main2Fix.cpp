#include "LorentzV.h"
#include <iostream>
#include <math.h>
using namespace std;

double LorentzVector::getx() const {
	return x;
}
double LorentzVector::gety() const {
	return y;
}
double LorentzVector::getz() const {
	return z;
}
double LorentzVector::gett() const {
	return t;
}
void LorentzVector::operator+=(const LorentzVector& l) {
	x += l.x;
	y += l.y;
	z += l.z;
	t += l.t;
	
}
void LorentzVector::operator-=(const LorentzVector& l) {
	x -= l.x;
	y -= l.y;
	z -= l.z;
	t -= l.t;
	
}
void LorentzVector::operator*=(double a) {
	x *= x * a;
	y *= y * a;
	z *= z * a;
	t *= t * a;

}
LorentzVector LorentzVector::operator+(const LorentzVector& l) const {
	LorentzVector buf;
	buf.x = x + l.x;
	buf.y = x + l.y;
	buf.z = x + l.z;
	buf.t = x + l.t;
	return buf;
}
LorentzVector LorentzVector::operator-(const LorentzVector& l) const {
	LorentzVector buf;
	buf.x = x - l.x;
	buf.y = x - l.y;
	buf.z = x - l.z;
	buf.t = x - l.t;
	return buf;
}
LorentzVector LorentzVector::operator*(double a) const {
	LorentzVector buf;
	buf.x = a * x;
	buf.y = a * y;
	buf.z = a * z;
	buf.t = a * t;
	return buf;

}
LorentzVector operator*(double a, const LorentzVector& l) {
	LorentzVector buf;
	buf.x = a * l.x;
	buf.y = a * l.y;
	buf.z = a * l.z;
	buf.t = a * l.t;
	return buf;

}
LorentzVector LorentzVector::operator-() const {
	LorentzVector buf;
	buf.x = -x;
	buf.y = -y;
	buf.z = -z;
	buf.t = -t;
	return buf;
}
double LorentzVector::operator*(const LorentzVector& l) const {
	return x * l.x + y * l.y + z * l.z - t * l.t;
}

std::istream& operator>>(std::istream& is, LorentzVector& l) {
	is >> l.x;
	is >> l.y;
	is >> l.z;
	is >> l.t;
	return is;
}
std::ostream& operator<<(std::ostream& os, const LorentzVector l) {
	os << l.x << " " << l.y << " " << l.z << " " << l.t;
	return os;
}
void LorentzVector::out() {
	cout << x <<" " << y << " " << z << " " << t;
}
LorentzVector LorentzVector::in() {
	LorentzVector buf;
	cin >> x >> y >> z >> t;
	buf.x = x;
	buf.y = y;
	buf.z = z;
	buf.t = t;	
	return buf;
}
LorentzVector LorentzVector::Convert(double b) {
	LorentzVector buf;
	buf.z = (z - b * t) / sqrt(1 - b * b);
	buf.y = y;
	buf.x = x;
	buf.t = (t - b * x) / sqrt(1 - b * b);

	return buf;
}
double LorentzVector::norm() const {
	return x * x + y * y + z * z - t * t;
}
int main() {
	LorentzVector l1(0, 0, 0, 0), l2(0, 0, 0, 0), l;
	double a, b;
	cout << "Input first vector: ";
	l1.in();
	cout << endl;
	cout << "Input second vector: ";
	l2.in();
	cout << endl;
	cout << "Input multiplication const: ";
	cin >> a;
	cout << endl;
	cout << "Input beta: ";
	cin >> b;
	while (b > 1) {
		cout << "Beta onput is incorrect, check and input beta again: ";
		cin >> b;
	};
	cout << endl;
	l = l1;
	l += l2;
	cout << "sum is: " << l1 + l2 << "  " << l << endl;
	l = l1;
	l -= l2;
	cout << "sub is: " << l1 - l2 << "  " << l << endl;
	l = l1;
	l *= a;
	cout << "mult is: " << l1 * l2 << "  " << l1*a << "  " << a*l1 << "  " << l <<endl;
	cout << "l1 conver is: " << l1.Convert(b) << endl;
	cout << "l1 squared norm is: " << l1.norm() << endl;
	cout << "l2 squared norm is: " << l2.norm() << endl;







}





























