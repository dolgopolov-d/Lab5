#ifndef __LIST_H__
#define __LIST_H__
template <typename T> class TList
{
private:
	struct Node
	{
		Node *pNext;
		T c;
		T e;
	};
	Node *pFirst;
	int count;
public:
	TList() : pFirst(nullptr), count(0) {}
	~TList()
	{
		Node *current = pFirst;
		Node *del = pFirst;
		while (del != nullptr)
		{
			current = current->pNext;
			delete del;
			del = current;
		}
		pFirst = nullptr;
		count = 0;
	}
	int getCount()
	{
		return count;
	}
	void add(T _c, T _e)
	{
		Node *add = new Node;
		add->pNext = nullptr;
		add->c = _c;
		add->e = _e;
		if (pFirst == nullptr) 
			pFirst = add;
		else
		{
			Node *current;
			for (current = pFirst; current->pNext != 0; current = current->pNext);
			current->pNext = add;
		}
		count++;
	}
	void del(int a)
	{
		if (a > count)
			throw;
		Node *del = pFirst;
		if (a == 1) 
		{
			pFirst = pFirst->pNext;
			delete del;
		}
		else
		{
			Node *current = pFirst;
			for (int i = 1; i < a - 1; i++)
				current = current->pNext;
			del = current->pNext;
			current->pNext = current->pNext->pNext;
			delete del;
		}
		count--;
	}
	void clear()
	{
		Node *current = pFirst;
		Node *del = pFirst;
		while (del != nullptr)
		{
			current = current->pNext;
			delete del;
			del = current;
		}
		pFirst = nullptr;
		count = 0;
	}
	T getCoeff(int a)
	{
		Node *current;
		for (current = pFirst; a > 1; a--)
			current = current->pNext;
		if (current == nullptr)
			throw;
		return current->c;
	}
	T getExp(int a)
	{
		Node *current;
		for (current = pFirst; a > 1; a--)
			current = current->pNext;
		if (current == nullptr)
			throw;
		return current->e;
	}
};
#endif