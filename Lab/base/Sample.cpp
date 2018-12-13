#include "polynom.h"
#include <iostream>
#include <locale.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int x, y, z;
	TPolynom a, b1, b2;
	string in, in1, in2;
	cout << "¬ведите полином вида QxAyBzC" << endl << "где Q-коэффициент, A-степень при х, B-степень при у, C-степнь при z " << endl << "(если какого-то множител€ нет, то его степень равна 0; A, B, C < 10): " << endl;
	cin >> in;
	a.Create(in);
	cout << "¬аш полином: " << endl;
	a.getPolynom();
	cout << "¬ведите значение х: " << endl;
	cin >> x;
	cout << "¬ведите значение y: " << endl;
	cin >> y;
	cout << "¬ведите значение z: " << endl;
	cin >> z;
	cout << "–езультат: " << a.Calculate(x, y, z) << endl;
	/*
	cout << "¬ведите первый полином: " << endl;
	cin >> in1;
	b1.Create(in1);
	cout << "¬ведите второй полином: " << endl;
	cin >> in2;
	b2.Create(in2);
	cout << "—кладываютс€ полиномы: " << endl;
	b1.getPolynom();
	b2.getPolynom();
	TPolynom res;
	res.doPlus(b1, b2);
	res.getPolynom();
	*/
}