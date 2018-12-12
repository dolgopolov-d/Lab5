#include "polynom.h"
#include <iostream>
#include <locale.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	TPolynom a, b1, b2;
	string in, in1, in2;
	cout << "¬ведите полином вида QxAyBzC" << endl << "где Q-коэффициент, A-степень при х, B-степень при у, C-степнь при z " << endl << "(если какого-то множител€ нет, то его степень равна 0; A, B, C < 10): " << endl;
	cin >> in;
	a.Create(in);
	cout << "¬аш полином: " << endl;
	a.getPolynom();
	/*
	cout << "¬ведите первый полином: " << endl;
	cin >> in1;
	b1.Create(in1);
	cout << "¬ведите второй полином: " << endl;
	cin >> in2;
	b2.Create(in2);
	*/
}