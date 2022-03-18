#include "MainFunction.h"
Something* MakeNodeSomething(string s)
{
	Something* p;
	p = new Something;
	p->a = s;
	p->pnext = NULL;
	p->prev = NULL;
	return p;
}
void Push1Something_Tail(Something*& head, string s)
{
	Something* p = MakeNodeSomething(s);
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		Something* pCur = head;
		while (pCur->pnext != NULL)
		{
			pCur = pCur->pnext;
		}
		pCur->pnext = p;
		p->prev = pCur;
	}
}
void OutputListSomething(Something*& head)
{
	for (Something* i = head; i != NULL; i = i->pnext)
	{
		cout << "\t" << i->a << endl;
	}
}
void DeleteListSomething(Something*& head)
{
	Something* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->pnext;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		delete temp;
	}
}
bool CheckNameClassInYear(Something*& head, string nameclass)
{
	for (Something* i = head; i != NULL; i = i->pnext)
	{
		if (i->a == nameclass)
			return true;
	}
	return false;
}
