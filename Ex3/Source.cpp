#include "HeaderArr.h"
using namespace std;

int main() {
	Arr v;
	double c;
	string name = "Input.txt";
	v = v.RFF(name);
	v.Print();
	cout << "max element is: " << v.max() << "min element is: " << v.min() << "mean norm is: " << v.mean() << " " << "RMS is: " << v.RMS() << endl;
	cout << "Number of elements larger then const is: " << v.countLarger() << endl;

}