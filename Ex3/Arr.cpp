#include "HeaderArr.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

Arr::Arr(std::vector<cord> vec_) {
	vec = vec_;

	sort(vec.begin(), vec.end());

	vector<double> norm(vec.size());

	transform(vec.begin(), vec.end(), norm.begin(), [](cord v) {return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); });
	Cmean = accumulate(norm.begin(), norm.end(), double(0.)) / norm.size();

	vector<double> squares(vec.size());
	transform(vec.begin(), vec.end(), squares.begin(), [](cord v) {return v.x* v.x + v.y * v.y + v.z * v.z; });
	Crms = sqrt((accumulate(squares.begin(), squares.end(), double(0.)) / squares.size()) - Cmean * Cmean);


	double c;
	cout << "Input const: ";
	cin >> c;
	transform(vec.begin(), vec.end(), norm.begin(), [](cord v) {return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);});
	vector<double>::const_iterator p = upper_bound(norm.begin(), norm.end(), c);
	k = norm.end() - p;
}



ostream& operator << (ostream& os, const Arr::cord& v) {
	os << v.x << " " << v.y << " " << v.z << " " << endl;
	return os;
}
istream& operator >> (istream& is, Arr::cord& v) {
	is >> v.x >> v.y >> v.z;
	return is;
}
bool operator < (const Arr::cord& v1, const Arr::cord& v2) {
	double firstnorm = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	double secondnorm = sqrt(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z);
	return firstnorm < secondnorm;
}
Arr Arr::RFF(const string & name) const {
	ifstream file(name);
	vector<cord> vec;
	if (!file.good()) { cout << "Error.Can't open file!" << endl; exit(1); };
	if (file.peek() == EOF) { cout << "Your file is empty!" << endl; exit(1); };
	while (!file.eof()) {
		cord buf;
		file >> buf;
		vec.push_back(buf);
	}
	return vec;
}

void Arr::Print() const {
	cout << "Sorted array is: " << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	cout << endl;
}

Arr::cord Arr::max() const {
	return vec[vec.size() - 1];
}
Arr::cord Arr::min() const {
	return vec[0];
}

double Arr::mean() const {
	return Cmean;
}
double Arr::RMS() const {
	return Crms;
}
int Arr::countLarger() const {
	return k;
}

