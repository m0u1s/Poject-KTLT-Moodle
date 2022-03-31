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
void Push1Something_Head(Something*& head, string s)
{
	Something* p = MakeNodeSomething(s);
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		p->pnext = head;
		head->prev = p;
		head = p;
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
int CutYear(string year)
{
	for (int i = 0; i < year.length(); i++)
	{
		if (year[i] == '-')
		{
			return atol(year.substr(0, i).c_str());
		}
	}
}
void PushArrangeCreatedYear(Something*& headYear, string year)
{
	if (headYear == NULL)
	{
		Push1Something_Head(headYear, year);
	}
	else if (CutYear(headYear->a) > CutYear(year))
	{
		Push1Something_Head(headYear, year);
	}
	else
	{
		Something* p = MakeNodeSomething(year);
		Something* p1 = headYear;
		Something* p2 = headYear->pnext;
		while (p2 != NULL && p2->a < year)
		{
			p1 = p1->pnext;
			p2 = p2->pnext;
		}
		p1->pnext = p;
		p->prev = p1;
		p->pnext = p2;
		if (p2 != NULL)
		{
			p2->prev = p;
		}
	}

}
void OutputCreatedYear_File(Something*& headYear)
{
	ofstream fileout;
	Something* pCur = headYear;
	while (pCur->pnext != NULL)
	{
		pCur = pCur->pnext;
	}
	fileout.open("schoolyear.txt", ios::out);
	for (Something* i = headYear; i != NULL; i = i->pnext)
	{
		if (i == pCur)
		{
			fileout << i->a;
		}
		else
		{
			fileout << i->a << endl;
		}
	}
	fileout.close();
}
void PushAllCreatedYear_File(Something*& headYear)
{
	ifstream filein;
	filein.open("schoolyear.txt", ios::in);
	string temp;
	while (!filein.eof())
	{
		filein >> temp;
		Push1Something_Tail(headYear, temp);
	}
	filein.close();
}
void DeleteListCreatedYear(Something*& headYear)
{
	Something* temp;
	while (headYear != NULL)
	{
		temp = headYear;
		headYear = headYear->pnext;
		if (headYear != NULL)
		{
			headYear->prev = NULL;
		}
		delete temp;
	}
}
void OutputList(Something*& headYear)
{
	for (Something* i = headYear; i != NULL; i = i->pnext)
	{
		cout << i->a << endl;
	}
}
bool checkyear(string Year)
{
	if (Year.length() != 9) return false;
	int first = 0, second = 0;
	int vt = 0;
	while (vt < Year.length() && Year[vt] != '-')
	{
		first = first * 10 + Year[vt] - '0';
		vt++;
	}
	vt++;
	while (vt < Year.length())
	{
		second = second * 10 + Year[vt] - '0';
		vt++;
	}
	if (second - first == 1) return true;
	return false;
}