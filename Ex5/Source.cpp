#include "Figures.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;



int main() {

	//Создание гетерогенного списка
	triangle t(10, 2, 1.5, 4, 5, 7);
	circle c(3,2,1);
	circle c2(3, 3, 3);
	
	//vec.push_back(c,t)
	//vector<figure*> Figs(2);
	//Figs[0] = &t;
	//Figs[1] = &c;

	//Вывод параметров геометрических фигур

	t.print_parameters();
	t.Triangle_print_results();
	c.print_parameters();
	c.Circle_print_results();
	c2.print_parameters();
	c2.Circle_print_results();
	cout << endl;
    
	vector<figure*> list;
	list.push_back(&t);
	list.push_back(&c2);
	list.push_back(&c);
	//сортировка по периметру
	cout << "perimeter sort" << endl;
	figure* temp_p;
	for (int i = 0; i < list.size()-1; i++) {
		for (int j = 0; j < list.size() - 1 - i; j++) {
			if (list[j]->perimeter() > list[j + 1]->perimeter()) {
				temp_p = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp_p;
			}
		}
	}
	for (int it = 0; it < 3; it++) {
		list[it]->print_parameters();
	}
	cout << endl;
	//сортировка по площади
	cout<<"area sort" << endl;
	figure* temp_a;
	for (int i = 0; i < list.size() - 1; i++) {
		for (int j = 0; j < list.size() - 1 - i; j++) {
			if (list[j]->area() > list[j + 1]->area()) {
				temp_a = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp_a;
			}
		}
	}
	for (int it = 0; it < 3; it++) {
		list[it]->print_parameters();
	}
}
