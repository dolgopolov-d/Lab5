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
	int f;
	g:cout << "1. Вычислить полином\n2. Сложить полином\n3. Вычесть полином\n";
	cin >> f;
	if (f > 3 || f < 1)
	{
		cout << "Неверный выбор" << endl;
		goto g;
	}
	switch (f)
	{
	case 1:
	{
		cout << "Введите полином из мономов вида QxAyBzC" << endl << "где Q-коэффициент, A-степень при х, B-степень при у, C-степeнь при z " << endl << "(если какого-то множителя нет, то его степень равна 0; A, B, C < 10): " << endl;
		cin >> in;
		a.Create(in);
		cout << "Ваш полином: " << endl;
		a.getPolynom();
		cout << "Введите значение х: " << endl;
		cin >> x;
		cout << "Введите значение y: " << endl;
		cin >> y;
		cout << "Введите значение z: " << endl;
		cin >> z;
		cout << "Результат: " << a.Calculate(x, y, z) << endl;
		break;
	}
	case 2:
	{
		cout << "Введите первый полином: " << endl;
		cin >> in1;
		b1.Create(in1);
		cout << "Введите второй полином: " << endl;
		cin >> in2;
		b2.Create(in2);
		cout << "Складываются полиномы: " << endl;
		b1.getPolynom();
		b2.getPolynom();
		TPolynom res;
		res.doPlus(b1, b2);
		res.getPolynom();
		break;
	}
	case 3:
	{
		cout << "Введите первый полином: " << endl;
		cin >> in1;
		b1.Create(in1);
		cout << "Введите второй полином: " << endl;
		cin >> in2;
		b2.Create(in2);
		cout << "Вычитаются полиномы: " << endl;
		b1.getPolynom();
		b2.getPolynom();
		TPolynom res;
		res.doMinus(b1, b2);
		res.getPolynom();
		break;
	}
	}
}