/*
#include "list.h"
#include "polynom.h"
#include <iostream>
using namespace std;

void main()
{
	TList<int> a;
	TPolynom b;
	a.add(2, 2);
	a.add(3, 3);
	a.add(4, 4);
	for (int i = 1; i <= a.getCount(); i++)
		cout << a.getCount() << endl << a.getCoeff(i) << endl << a.getExp(i) << endl << endl;
	b.Create("10x0y0z9+10000x1y1z8-8x2y2z7");
	string signs = b.getSign();
	for (int i = 1; i <= b.getListCount(); i++)
		cout << "op" << endl << b.getListCoeff(i) << endl << b.getListExp(i) << endl << endl;
	cout << "10x0y0z9+10000x1y1z8-8x2y2z7" << endl;
	cout << "a teper' soberem: " << endl;
	for (int i = 1; i <= b.getListCount(); i++)
		cout << b.getListCoeff(i) << "x" << b.getListExp(i) / 100 << "y" << b.getListExp(i) / 10 % 10 << "z" << b.getListExp(i) % 10 % 10 << signs[i - 1];
	cout << endl << endl;
	b.getPolynom();
}
*/