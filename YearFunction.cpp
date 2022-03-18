#include "MainFunction.h"
YearCreated* MakeNodeCreateYear(string year)
{
	YearCreated* p = new YearCreated;
	p->year = year;
	p->pnext = NULL;
	p->ppre = NULL;
	return p;
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
void Push1CreatedYear_Tail(YearCreated*& head, string year)
{
	YearCreated* p = MakeNodeCreateYear(year);
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		YearCreated* pCur = head;
		while (pCur->pnext != NULL)
		{
			pCur = pCur->pnext;
		}
		pCur->pnext = p;
		p->ppre = pCur;
	}
}
void Push1CreatedYear_Head(YearCreated*& head, string year)
{
	YearCreated* p = MakeNodeCreateYear(year);
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		p->pnext = head;
		head->ppre = p;
		head = p;
	}
}
void PushArrangeCreatedYear(YearCreated*& head, string year)
{
	if (head == NULL)
	{
		Push1CreatedYear_Head(head, year);
	}
	else if (CutYear(head->year) > CutYear(year))
	{
		Push1CreatedYear_Head(head, year);
	}
	else
	{
		YearCreated* p = MakeNodeCreateYear(year);
		YearCreated* p1 = head;
		YearCreated* p2 = head->pnext;
		while (p2 != NULL && p2->year < year)
		{
			p1 = p1->pnext;
			p2 = p2->pnext;
		}
		p1->pnext = p;
		p->ppre = p1;
		p->pnext = p2;
		if (p2 != NULL)
		{
			p2->ppre = p;
		}
	}

}
void OutputCreatedYear_File(YearCreated*& head)
{
	ofstream fileout;
	YearCreated* pCur = head;
	while (pCur->pnext != NULL)
	{
		pCur = pCur->pnext;
	}
	fileout.open("schoolyear.txt", ios::out);
	for (YearCreated* i = head; i != NULL; i = i->pnext)
	{
		if (i == pCur)
		{
			fileout << i->year;
		}
		else
		{
			fileout << i->year << endl;
		}
	}
	fileout.close();
}
void PushAllCreatedYear_File(YearCreated*& head)
{
	ifstream filein;
	filein.open("schoolyear.txt", ios::in);
	string temp;
	while (!filein.eof())
	{
		filein >> temp;
		Push1CreatedYear_Tail(head, temp);
	}
	//deletetail(listyear);
	filein.close();
}
void DeleteListCreatedYear(YearCreated*& head)
{
	YearCreated* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->pnext;
		if (head != NULL)
		{
			head->ppre = NULL;
		}
		delete temp;
	}
}
void OutputList(YearCreated*& head)
{
	for (YearCreated* i = head; i != NULL; i = i->pnext)
	{
		cout << i->year << endl;
	}
}