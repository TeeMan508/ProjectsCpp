#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
class Arr {
	struct cord {
		double x;
		double y;
		double z;
	};
private:
	std::vector<cord> vec;
	double Cmean, Crms;
	int k;
public:
	Arr() = default;
	Arr(std::vector<cord> vec_);
	friend std::ostream& operator << (std::ostream& os, const cord& v);
	friend std::istream& operator >> (std::istream& is, cord& v);
	friend bool operator < (const cord& v1, const cord& v2);
	Arr RFF(const std::string& name) const;
	void Print() const;
	cord max() const;
	cord min() const;
	double mean() const;
	double RMS() const;
	int countLarger() const;
};