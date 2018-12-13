#include "list.h"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
class TPolynom
{
private:
	TList<int> l;
	string sign;
	string coef;
	string exp_x;
	string exp_y;
	string exp_z;
public:
	TPolynom(){}
	void Create(string a)
	{
		int c;
		int exp;
		int i = 0;
		coef.clear();
		exp_x.clear();
		exp_y.clear();
		exp_z.clear();
		while (a[i] != 'x')
		{
			coef.push_back(a[i]);
			i++;
		}
		i++;
		while (a[i] != 'y')
		{
			exp_x.push_back(a[i]);
			i++;
		}
		i++;
		while (a[i] != 'z')
		{
			exp_y.push_back(a[i]);
			i++;
		}
		i++;
		while (i < a.size())
		{
			if (a[i] == '+' || a[i] == '-')
			{
				sign.push_back(a[i]);
				break;
			}
			exp_z.push_back(a[i]);
			i++;
		}
		c = stoi(coef);
		exp = stoi(exp_x) * 100 + stoi(exp_y) * 10 + stoi(exp_z);
		l.add(c, exp);
		string tmp = a.erase(0, i + 1);
		if (tmp.empty())
			return;
		Create(tmp);
	}
	int getListCoeff(int a)
	{
		return l.getCoeff(a);
	}
	int getListExp(int a)
	{
		return l.getExp(a);
	}
	int getListCount()
	{
		return l.getCount();
	}
	void getPolynom()
	{
		if (getListCount() == 1)
		{
			cout << getListCoeff(1) << "x" << getListExp(1) / 100 << "y" << getListExp(1) / 10 % 10 << "z" << getListExp(1) % 10 % 10 << endl << endl;
		}
		else
			for (int i = 1; i <= getListCount(); i++)
				cout << getListCoeff(i) << "x" << getListExp(i) / 100 << "y" << getListExp(i) / 10 % 10 << "z" << getListExp(i) % 10 % 10 << sign[i - 1];
			cout << endl << endl;
	}
	string getSign()
	{
		return sign;
	}
	TList<int> getList()
	{
		return l;
	}
	/*
	void doPlus(TPolynom &p1, TPolynom &p2)
	{
		if (l.getCount() != 0)
			l.clear();
		for (int i = 1; i <= p1.getListCount(); i++)
			for (int j = 1; j <= p2.getListCount(); j++)
				if (p1.getListExp(i) == p2.getListExp(j))
				{
					l.add(p1.getListCoeff(i) + p2.getListCoeff(j), p1.getListExp(i));
				}
				else
		if(p1.getListCount() != 0)
			for (int i = 1; i <= p1.getListCount(); i++)
				l.add(p1.getListCoeff(i), p1.getListExp(i));
		if(p2.getListCount() != 0)
			for (int i = 1; i <= p2.getListCount(); i++)
				l.add(p2.getListCoeff(i), p2.getListExp(i));
		if (!sign.empty())
			sign.clear();
		sign.push_back('+');
	}
	*/
	int Calculate(int _x, int _y, int _z)
	{
		double tmp = 0;
		for (int i = 1; i <= getListCount(); i++)
			tmp = tmp+getListCoeff(i)*pow(_x, getListExp(i) / 100)*pow(_y, getListExp(i) / 10 % 10)*pow(_z, getListExp(i) % 10 % 10);
		return tmp;
	}
};