#include "polynom.h"
#include <iostream>
#include <locale.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	TPolynom a, b1, b2;
	string in, in1, in2;
	cout << "������� ������� ���� QxAyBzC" << endl << "��� Q-�����������, A-������� ��� �, B-������� ��� �, C-������ ��� z " << endl << "(���� ������-�� ��������� ���, �� ��� ������� ����� 0; A, B, C < 10): " << endl;
	cin >> in;
	a.Create(in);
	cout << "��� �������: " << endl;
	a.getPolynom();
	/*
	cout << "������� ������ �������: " << endl;
	cin >> in1;
	b1.Create(in1);
	cout << "������� ������ �������: " << endl;
	cin >> in2;
	b2.Create(in2);
	*/
}