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
	TPolynom operator=(TPolynom &p)
	{
		this->l = p.l;
		this->sign = p.sign;
		return *this;
	}
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
		if (getListCount() == 0)
			cout << '0' << endl;
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
	void doPlus(TPolynom &p1, TPolynom &p2)
	{
		int flag = 0;
		TList<int> l1(p1.getList());
		TList<int> l2(p2.getList());
		sign.clear();
		sign = p1.getSign() + p2.getSign();
		l.add(l1.getCoeff(1), l1.getExp(1));
		if (l1.getCount() > 1)
			for (int i = 2; i <= l1.getCount(); i++)
			{
				if (sign[i - 2] == '-')
				{
					l.add((-1)*l1.getCoeff(i), l1.getExp(i));
					sign[i-2] = '+';
				}
				if (sign[i - 2] == '+')
					l.add(l1.getCoeff(i), l1.getExp(i));
			}
		l.add(l2.getCoeff(1), l2.getExp(1));
		if (l2.getCount() > 1)
			for (int i = 2; i <= l2.getCount(); i++)
			{
				if (sign[i + p1.getSign().size() - 2] == '-')
				{
					l.add((-1)*l2.getCoeff(i), l2.getExp(i));
					sign[i - 2] = '+';
				}
				if (sign[i + p1.getSign().size() - 2] == '+')
					l.add(l2.getCoeff(i), l2.getExp(i));
			}
		for (int i = 1; i < l.getCount(); i++)
			for (int j = i + 1; j <= l.getCount(); j++)
				if (l.getExp(i) == l.getExp(j))
				{
					flag = 1;
					l.add(l.getCoeff(i) + l.getCoeff(j), l.getExp(i));
					l.del(j);
					l.del(i);
				}
		if (flag == 0)
		{
			sign.clear();
			for (int i = 1; i < l.getCount(); i++)
				sign.push_back('+');
		}
		return;
	}
	void Correct()
	{
		int flag = 0;
		if(l.getCoeff(1) == 0)
			l.del(1);
		for (int i = 2; i < l.getCount(); i++)
			if (l.getCoeff(i) == 0)
			{
				l.del(i);
				sign.erase(i - 2);
			}
		for (int i = 2; i <= l.getCount(); i++)
			if (sign[i - 2] == '-')
			{
				l.add((-1)*l.getCoeff(i), l.getExp(i));
				l.del(i);
				sign[i - 2] = '+';
			}
		for (int i = 1; i < l.getCount(); i++)
			for (int j = i + 1; j <= l.getCount(); j++)
				if (l.getExp(i) == l.getExp(j))
				{
					if (sign[j - 2] == '-')
						l.add(l.getCoeff(i) - l.getCoeff(j), l.getExp(i));
					if (sign[j - 2] == '+')
						l.add(l.getCoeff(i) + l.getCoeff(j), l.getExp(i));
					l.del(j);
					l.del(i);
					flag = 1;
				}
				else
					continue;
		if (l.getCoeff(1) == 0)
			l.del(1);
		for (int i = 2; i < l.getCount(); i++)
			if (l.getCoeff(i) == 0)
			{
				l.del(i);
				sign.erase(i - 2);
			}
		if (flag == 0)
			return;
		if(!sign.empty())
			sign.pop_back();
	}
	int Calculate(int _x, int _y, int _z)
	{
		int tmp = 0;
		tmp = tmp + getListCoeff(1)*pow(_x, getListExp(1) / 100)*pow(_y, getListExp(1) / 10 % 10)*pow(_z, getListExp(1) % 10 % 10);
		for (int i = 2; i <= getListCount(); i++)
		{
			if (sign[i - 2] == '+')
				tmp = tmp + getListCoeff(i)*pow(_x, getListExp(i) / 100)*pow(_y, getListExp(i) / 10 % 10)*pow(_z, getListExp(i) % 10 % 10);
			else
				if (sign[i - 2] == '-')
					tmp = tmp - getListCoeff(i)*pow(_x, getListExp(i) / 100)*pow(_y, getListExp(i) / 10 % 10)*pow(_z, getListExp(i) % 10 % 10);
		}
		return tmp;
	}
};