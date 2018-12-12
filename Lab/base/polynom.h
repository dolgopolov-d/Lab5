#include "list.h"
#include <string>
#include <iostream>
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
	void doPlus(TList<int> l1, TList<int> l2)
	{
		for (int i = 1; i <= l1.getCount(); i++)
			for (int j = 1; j <= l2.getCount(); j++)
				if (l1.getExp(i) == l2.getExp(j))
				{
					l.add(l1.getCoeff(i) + l2.getCoeff(j), l1.getExp(i));
					l1.del(i);
					l2.del(j);
				}
		for (int i = 1; i <= l1.getCount(); i++)
			l.add(l1.getCoeff(i), l1.getExp(i));
		for (int i = 1; i <= l2.getCount(); i++)
			l.add(l2.getCoeff(i), l2.getExp(i));
	}
	*/
};