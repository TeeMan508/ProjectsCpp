#include <iostream>
class LorentzVector {
private:
	double x, y, z, t;
public:
	LorentzVector() = default;
	LorentzVector(double x_, double y_, double z_, double t_) {
		x = x_;
		y = y_;
		z = z_;
		t = t_;
	};
	friend std::ostream& operator<<(std::ostream& os, const LorentzVector l);
	friend std::istream& operator>>(std::istream& is, LorentzVector& l);
	void operator+=(const LorentzVector& l);
	void operator-=(const LorentzVector& l);
	void operator*=(double a);
	LorentzVector operator+(const LorentzVector& l) const;
	LorentzVector operator-(const LorentzVector& l) const;
	LorentzVector operator*(double a) const;
	friend LorentzVector operator*(double a, const LorentzVector& l);
	double operator*(const LorentzVector& l) const;
	LorentzVector operator-() const;
	double getx() const;
	double gety() const;
	double getz() const;
	double gett() const;
	double norm() const;
	void out();
	LorentzVector in();
	LorentzVector Convert(double b);
};