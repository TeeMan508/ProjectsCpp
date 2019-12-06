#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

class BraceChecker{
private:

public:
	BraceChecker() = delete;
	static bool isBalanced(const string name){
		stack <int> brack;
		for (int i = 0; i < name.length(); i++){
			if (name[i] != '(' && name[i] != '[' && name[i] != '{' && name[i] != ')' && name[i] != ']' && name[i] != '}') continue;
			if (name[i] == '(') { brack.push('('); }
			if (name[i] == '[') { brack.push('['); }
			if (name[i] == '{') { brack.push('{'); }
			if (name[i] == ')') {
				if (!brack.empty()) if (brack.top() == '(')  brack.pop();
				else return false; else return false;

			}
			if (name[i] == ']') {
				if (!brack.empty()) if (brack.top() == '[') brack.pop();
				else return false; else return false;

			}
			if (name[i] == '}') {
				if (!brack.empty()) if (brack.top() == '{') brack.pop();
				else return false; else return false;

			}

		}
		if (brack.empty()) return true; else return false;
	}
};
int main(){
	string name;
	string fname;
	cout << "Enter file adress: " << endl;
	getline(cin,fname);
	ifstream file(fname);
	if (file.peek() == EOF) { cout << "Your file is empty!" << endl; exit(1); };
	if (!file.good()) {
		cout << "Error.Can't open file!" << endl;
		exit(1);
	}
	getline(file, name);
	cout << name << endl;
	if (BraceChecker::isBalanced(name)) cout << "Balanced"; else cout << "Not balanced" << endl;
	

}