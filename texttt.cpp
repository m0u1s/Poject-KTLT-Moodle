#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <string.h>
#include <atlstr.h>
#include <direct.h>
#include <cassert>

using namespace std;
bool FolderExists(const CString& strFolderName)
{
	return GetFileAttributes(strFolderName) != INVALID_FILE_ATTRIBUTES;
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotoxy(int x, int y)
{
	HANDLE hConsoleOuput;
	COORD Cursor_an_Pos = { x ,y };
	hConsoleOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOuput, Cursor_an_Pos);
}
void Setcolor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}
BOOL WINAPI SetConsoleTitle(
	_In_ LPCTSTR lpConsoleTitle
);
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
struct teacher
{
	string theory;
	string practice;
};
struct schedule
{
	string theory;
	string practice;
};
struct semester
{
	string name;
	string start;
	string end;
};
class Course
{
public:
	string semester;
	string Course_Code;
	string Course_Name;
	int credits;
	string Class;
	schedule Schedule;

private:
	teacher Teacher;
};
class person
{
protected:
	string ID;
	string password;
	string name;
	string gender;
	string birth;
	string socialID;
	string address;
	string phone;

public:
	string getpassword()
	{
		return password;
	}
	void changepassword(string newpassword)
	{
		password = newpassword;
	}
	string getID()
	{
		return ID;
	}
	string getname()
	{
		return name;
	}
	string getgender()
	{
		return gender;
	}
	void input()
	{
		cout << "Name: ";
		getline(cin, name);
		cout << "Address: ";
		getline(cin, address);
		cout << "ID: ";
		cin >> ID;
		cout << "social ID: ";
		cin >> socialID;
		cout << "Gender: ";
		cin >> gender;
		cout << "Birth: ";
		cin >> birth;
		cout << "Phone number: ";
		cin >> phone;
		password = "123456";
	}
	void input_file(string path)
	{
		ifstream filein;
		filein.open(path, ios_base::in);
		getline(filein, password);
		getline(filein, name, ',');
		getline(filein, ID, ',');
		getline(filein, gender, ',');
		getline(filein, birth, ',');
		getline(filein, socialID, ',');
		getline(filein, phone, ',');
		getline(filein, address);
		filein.close();
	}
	void output()
	{
		gotoxy(35, 5); cout << "Name : " << name;
		gotoxy(35, 7); cout << "Gender : " << gender;
		gotoxy(35, 9); cout << "ID: " << ID;
		gotoxy(35, 11); cout << "Address: " << address;
		gotoxy(35, 13); cout << "Socail ID: " << socialID;
		gotoxy(35, 15); cout << "Date of birth: " << birth;
		gotoxy(35, 17); cout << "Phone number: " << phone;
		gotoxy(35, 19); cout << "Password: " << password;
	}
	void edit_profile();
};
class student : public person
{
private:
	string CLASS;
public:
	void savefile(string path)
	{
		ofstream fileout;
		fileout.open(path, ios::out);
		fileout << password << endl;
		fileout <<CLASS<<","<< name << "," << ID << "," << gender << "," << birth << "," << socialID << "," << phone << "," << address;
		fileout.close();
	}
	string getclass()
	{
		return CLASS;
	}
	void input()
	{
		ifstream fileinput;
	person::input();
	while (true)
	{
		cout << "Class to add: ";
		cin >> CLASS;
		fileinput.open(CLASS + ".txt", ios::in);
		if (fileinput.fail())
		{
			cout << "There is not this class. Try Again!" << endl;
		}
		else
		{
			fileinput.close();
			break;
		}
		fileinput.close();
	}
	}
	void input_file(string path)
	{
		ifstream filein;
		filein.open(path, ios_base::in);
		getline(filein, password);
		getline(filein, CLASS,',');
		getline(filein, name, ',');
		getline(filein, ID, ',');
		getline(filein, gender, ',');
		getline(filein, birth, ',');
		getline(filein, socialID, ',');
		getline(filein, phone, ',');
		getline(filein, address);
		filein.close();
	}
	void output()
	{
		gotoxy(35, 3); cout << "Class : " << CLASS;
		gotoxy(35, 5); cout << "Name : " << name;
		gotoxy(35, 7); cout << "Gender : " << gender;
		gotoxy(35, 9); cout << "ID: " << ID;
		gotoxy(35, 11); cout << "Address: " << address;
		gotoxy(35, 13); cout << "Socail ID: " << socialID;
		gotoxy(35, 15); cout << "Date of birth: " << birth;
		gotoxy(35, 17); cout << "Phone number: " << phone;
		gotoxy(35, 19); cout << "Password: " << password;
	}
	void class_list(fstream class_list);
	void register_course(fstream course_list, fstream& course_registered);
	void courses_infomation(fstream course_registered);
	void delete_course(fstream& course_registered);
	void view_registered_course(fstream course_registered);
	void view_course_member(fstream course_registered);

private:
	void view_results(fstream result_list); // b/c 1 student only see his/her results other can't
};
class staff: public person
{
public:
	void savefile(string path)
	{
		ofstream fileout;
		fileout.open(path, ios::out);
		fileout << password << endl;
		fileout << name << "," << ID << "," <<gender<<","<< birth << "," << socialID << "," << phone << "," << address;
		fileout.close();
	}
	// When a semester start
	// idea for a semester that we have a file name 2021-2022 then inside we have classes,...
	void create_schoolyear()
	{
		string year;
		cout << "Nhap nam hoc (2021-2022): ";
		cin >> year;
		_mkdir(year.c_str());
		system("cls");
	}
	void add_student()
	{
		student a;
		string year;
		/*do
		{
			cout << "School year (ex: 2021-2022): ";
			cin >> year;
			if (FolderExists(year.c_str()) == false)
			{
				cout << "There is not this school year. Try again!" << endl;
			}
		} while (FolderExists(year.c_str()) == false);
		cin.ignore();*/
		a.input();
		string path = "sinhvien\\" + a.getID()+".txt";
		a.savefile(path);
		fstream fileout;
		fileout.open(a.getclass() + ".txt", ios::out | ios::app);
		fileout << endl;
		fileout << a.getID() << " - " << a.getname() << " - " << a.getgender();
		fileout.close();
	}
	/*void make_class_file(string nameofclass, string year)
	{
		ifstream fileout; ofstream fileout2; string s;
		fileout.open(nameofclass + ".txt", ios::out);
		fileout2.open(year + "\\" + nameofclass + ".txt", ios::out);
		while (!fileout.eof())
		{
			getline(fileout, s);
			if (fileout.eof())
			{
				fileout2 << s;
			}
			else
			{
				fileout2 << s << endl;
			}
		}
		fileout2.close();
		fileout.close();
	}*/
	void create_class()
	{
		string mainanswer;
		string year;
		fstream filein1;
		fstream filein2;
		string lop;
		string path;
		while (true)
		{
			system("cls");
			cout << "1. Create classes: " << endl;
			cout << "2. See list class: " << endl;
			cout << "0. Go back to menu: " << endl << endl;
			cout << "Your choice: ";
			cin >> mainanswer;
			if (mainanswer == "1")
			{
				cout << "If you want to comback, just type 0." << endl;
				do
				{
					cout << "School year (ex: 2021-2022): ";
					cin >> year;
					if (FolderExists(year.c_str()) == false)
					{
						cout << "There is not this school year. Try again!" << endl;
					}
				} while (FolderExists(year.c_str()) == false && year != "0");
				if (year != "0")
				{
					filein2.open(year + "\\class.txt", ios::out | ios::app);
					char  answer;
					do
					{
						cout << "Name of class: ";
						cin >> lop;
						if (lop == "0")break;
						filein1.open(lop + ".txt", ios::in);
						if (filein1.fail())
						{
							cout << "There is not this file class. Try again!" << endl;
							answer = 'Y';
							filein1.close();
							continue;
						}
						else
						{
							filein1.close();
							filein2 << lop <<",";
						}
						cout << "Complete! Do you want to continue ? (Y/N): ";
						cin >> answer;
					} while (answer == 'Y' || answer == 'y');
					filein2.close();
				}
			}
			else if (mainanswer == "2")
			{
				system("cls");
				ifstream filein;
				string a;
				string answer;
				string name;
				string tempp;
				while(true)
				{
					system("cls");
					filein.open("2021-2022\\class.txt", ios::in);
					while (!filein.eof())
					{
						getline(filein, a, ',');
						cout << "\t" << a << endl;
					}
					filein.close();
					cout << "1. View the list student of class." << endl;
					cout << "0. Go back." << endl;
					cout << "Your answer: ";
					cin >> answer;
					if (answer == "1")
					{
						int check = 0;
						while(check == 0)
						{
							cout << "Name of class: ";
							cin >> name;
							ifstream fileinn;
							fileinn.open(name + ".txt", ios::in);
							if (fileinn.fail())
							{
								cout << "Wrong name! Try again." << endl;
								fileinn.close();
							}
							else
							{
								cout << endl;
								while (!fileinn.eof())
								{
									getline(fileinn, tempp);
									if (fileinn.eof())
									{
										cout <<"\t\t" <<  tempp;
									}
									else
									{
										cout << "\t\t" << tempp << endl;
									}
								}
								check = 1;
								cout <<"\n\nENTER TO CONTINUE." << endl;
								system("pause");
							}
							fileinn.close();
						}
					}
					else
					{
						break;
					}
				} 
			}
			else
			{
				system("cls");
				break;
			}
		}
	}
	void create_course(Course course, fstream& Course);
	void create_semester(semester x, fstream& semester);
	void adjust_Courses(fstream& Course);
	void delete_course();
	// End of regis time
	void read_Classlist();
	void read_studentList();
	// End of semester
	void output_Course_Student();
	void adjust_StudentGrades();
	void read_ClassGrades();
};

// cac ham tuong tac trên console

// lien quan den nam

struct yearcreated {
	string year;
	yearcreated* pnext;
	yearcreated* ppre;
};
struct list
{
	yearcreated* head = NULL;
	yearcreated* tail = NULL;
};
yearcreated* makenodecreateyear(string year)
{
	yearcreated* p = new yearcreated;
	p->year = year;
	p->pnext = NULL;
	p->ppre = NULL;
	return p;
}
int cutyear(string year)
{
	for (int i = 0; i < year.length(); i++)
	{
		if (year[i] == '-')
		{
			return atol(year.substr(0, i).c_str());
		}
	}
}
void deletetail(list& listyear)
{
	yearcreated* temp = listyear.tail;
	listyear.tail = listyear.tail->ppre;
	listyear.tail->pnext = NULL;
	delete temp;
}
void push1createdyear_tail(list &listyear, string year)
{
	yearcreated *p = makenodecreateyear(year);
	if (listyear.head == NULL)
	{
		listyear.head = p;
		listyear.tail = p;
	}
	else
	{
		listyear.tail->pnext = p;
		p->ppre = listyear.tail;
		listyear.tail = p;
	}
}
void push1createdyear_head(list& listyear, string year)
{
	yearcreated* p = makenodecreateyear(year);
	if (listyear.head == NULL)
	{
		listyear.head = p;
		listyear.tail = p;
	}
	else
	{
		p->pnext = listyear.head;
		listyear.head->ppre = p;
		listyear.head = p;
	}
}
void pusharrangecreatedyear(list& listyear, string year)
{
	if (listyear.head == NULL)
	{
		push1createdyear_head(listyear, year);
	}
	else if (cutyear(listyear.head->year) > cutyear(year))
	{
		push1createdyear_head(listyear, year);
	}
	else
	{
		yearcreated* p = makenodecreateyear(year);
		yearcreated* p1 = listyear.head;
		yearcreated* p2 = listyear.head->pnext;
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
		else
		{
			listyear.tail = p;
		}
	}

}
void outputcreatedyear_file(list& listyear)
{
	ofstream fileout;
	fileout.open("schoolyear.txt", ios::out);
	for (yearcreated* i = listyear.head; i != NULL; i=i->pnext)
	{
		if (i == listyear.tail)
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
void pushallcreatedyear_file(list &listyear)
{
	ifstream filein;
	filein.open("schoolyear.txt", ios::in);
	string temp;
	while (!filein.eof())
	{
		filein >> temp;
		push1createdyear_tail(listyear, temp);
	}
	//deletetail(listyear);
	filein.close();
}
void deletelistcreatedyear(list& listyear)
{
	yearcreated* temp;
	while (listyear.head != NULL)
	{
		temp = listyear.head;
		listyear.head = listyear.head->pnext;
		if (listyear.head != NULL)
		{
			listyear.head->ppre = NULL;
		}
		delete temp;
	}
}
void outputlist(list& listyear)
{
	for (yearcreated* i = listyear.head; i != NULL; i=i->pnext)
	{
		cout << i->year << " ";
	}
}
// Cac ham lien quan den giao dien chinh
bool login(int, int, int, int, bool, string& );
void create_board(int x, int y, int h, int w)
{
	for (int i = x; i < x + w; i++)
	{
		gotoxy(i, y); cout << "=";
		gotoxy(i, y + h + 1); cout << "=";
	}
	for (int i = y + 1; i <= y + h; i++)
	{
		gotoxy(x, i); cout << char(124);
		gotoxy(x + w - 1, i); cout << char(124);
	}
	gotoxy(0, y + h + 2);
}
void createn_n_board_col(int n, int x, int y, int h, int w)
{
	for (int i = 0; i < n; i++)
	{
		create_board(x, y + (h + 1)*i, h, w);
	}
}
void createn_n_board_row(int n, int x, int y, int h, int w)
{
	for (int i = 0; i < n; i++)
	{
		create_board(x+w*i+1*i, y, h, w);
	}
}
void create_board_content(int x, int y, int h, int w, string content, int ythanhsang)
{
	for (int i = x; i < x + w; i++)
	{
		gotoxy(i, y); cout << "=";
		gotoxy(i, y + h + 1); cout << "=";
	}
	if (y+1 == ythanhsang)
	{
		Setcolor(7, 0); gotoxy(x + 16, y + 1); cout << content; Setcolor(0, 7);
	}
	else
	{
		gotoxy(x + 16, y + 1); cout << content;
	}
	for (int i = y + 1; i <= y + h; i++)
	{
		gotoxy(x, i); cout << char(124);
		gotoxy(x + w - 1, i); cout << char(124);
	}
	gotoxy(0, y + h + 2);
}
void menu_sinhvien(int x, int y, int h, int w, int ythanhsang)
{
	create_board_content(x, y, h, w, "YOUR INFORMATION",ythanhsang);
	create_board_content(x, y+h+1, h, w, "CHANGE PASSWORD",ythanhsang);
	create_board_content(x, y+2*(h+1), h, w, "REGIST COURSE",ythanhsang);
	create_board_content(x, y + 3 * (h + 1), h, w, "SCORE COURSE",ythanhsang);
	create_board_content(x, y + 4 * (h + 1), h, w, "LOG OUT",ythanhsang);
}
void menu_giaovu(int x, int y, int h, int w, int ythanhsang)
{
	create_board_content(x, y, h, w, "YOUR INFORMATION",ythanhsang);
	create_board_content(x, y + h + 1, h, w, "CHANGE PASSWORD",ythanhsang);
	create_board_content(x, y+2*(h+1), h, w, "CREATE SCHOOLYEAR", ythanhsang);
	create_board_content(x, y + 3*(h + 1), h, w, "CREATE CLASS", ythanhsang);
	create_board_content(x, y + 4 * (h + 1), h, w, "CREATE SEMESTER", ythanhsang);
	create_board_content(x, y + 5 * (h + 1), h, w, "CREATE COURSE",ythanhsang);
	create_board_content(x, y + 6 * (h + 1), h, w, "ADD STUDENT", ythanhsang);
	create_board_content(x, y + 7 * (h + 1), h, w, "LOG OUT",ythanhsang);
}
bool giaodiendoimatkhau_sinhvien(int x, int y, int h, int w, student &student1)
{
	ShowCur(1);
	Setcolor(1, 0);
	string d;
	for (int i = y; i <= y + h + 1; i++)
	{
		for (int j = x; j < x + w; j++)
		{
			gotoxy(j, i); cout << " ";
		}
	}
	Setcolor(0, 7);
	Setcolor(11, 0);
	gotoxy(x, y); cout << "                 Change password                  ";
	Setcolor(0, 7);
	gotoxy(x + 1, y + 3); cout << "Current password:";
	gotoxy(x + 1, y + 7); cout << "New password (max 20char):";
	gotoxy(x + 1, y + 11); cout << "New password again:";
	Setcolor(7, 0);
	gotoxy(x + 8, y + 14); cout << "AFTER ENTER TO SAVE CHANGE PLEASE LOG OUT";
	gotoxy(x + 12, y + 15); cout << "ENTER TO SAVE CHANGE";
	for (int i = x + 1; i < x + w - 1; i++)
	{
		gotoxy(i, y + 4); cout << " ";
		gotoxy(i, y + 8); cout << " ";
		gotoxy(i, y + 12); cout << " ";
	}
	char currentpassword[20]; int j = 0;
	gotoxy(x + 1, y + 4);
	while (true)
	{
		char temp = _getch();
		if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') || temp == 32)
		{
			currentpassword[j] = temp;
			++j;
			cout << currentpassword[j - 1];
		}
		if (temp == '\b' && j >= 1)
		{
			cout << "\b \b";
			--j;
		}
		if (temp == '\r')
		{
			if (j > 0)
			{
				currentpassword[j] = '\0';
				d = currentpassword;
				if (d == student1.getpassword())
				{
					Setcolor(1, 0);
					gotoxy(x + 1, y + 2); cout << "                ";
					gotoxy(x + 1, y + 5); cout << "                          ";
					Setcolor(7, 0);
					break;
				}
				else
				{
					gotoxy(x + 1, y + 2); cout << "Wrong password !"; gotoxy(x + j + 1, y + 4);
				}
			}
			else
			{
				Setcolor(0, 4);
				gotoxy(x + 1, y + 5); cout << "You didn't type anything !";
				gotoxy(x + 1, y + 4);
				Setcolor(7, 0);
			}
		}
		if (temp == 27)
		{
			Setcolor(0, 7);
			return false;
		}
	}
	char newpassword[20]; int i = 0;
	gotoxy(x + 1, y + 8);
	while (true)
	{
		char temp = _getch();
		if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') || temp == 32)
		{
			newpassword[i] = temp;
			++i;
			cout << newpassword[i - 1];
		}
		if (temp == '\b' && i >= 1)
		{
			cout << "\b \b";
			--i;
		}
		if (temp == '\r')
		{
			if (i > 0)
			{
				newpassword[i] = '\0';
				d = newpassword;
				Setcolor(1, 0);
				gotoxy(x + 1, y + 9); cout << "                          ";
				Setcolor(7, 0);
				break;
			}
			else
			{
				Setcolor(0, 4);
				gotoxy(x + 1, y + 9); cout << "You didn't type anything !";
				gotoxy(x + 1, y + 8);
				Setcolor(7, 0);
			}
		}
		if (temp == 27)
		{
			Setcolor(0, 7);
			return false;
		}
	}
	char checkpassword[20]; int k = 0;
	gotoxy(x + 1, y + 12);
	while (true)
	{
		char temp = _getch();
		if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') || temp == 32)
		{
			checkpassword[k] = temp;
			++k;
			cout << checkpassword[k - 1];
		}
		if (temp == '\b' && k >= 1)
		{
			cout << "\b \b";
			--k;
		}
		if (temp == '\r')
		{
			if (k > 0)
			{
				checkpassword[k] = '\0';
				string temp = checkpassword;
				if (temp == d)
				{
					student1.changepassword(d);
					break;
				}
				else
				{
					gotoxy(x + 1, y + 10); cout << "Wrong password !"; gotoxy(x + k + 1, y + 12);
				}
			}
			else
			{
				Setcolor(0, 4);
				gotoxy(x + 1, y + 13); cout << "You didn't type anything !";
				gotoxy(x + 1, y + 12);
				Setcolor(7, 0);
			}
		}
		if (temp == 27)
		{
			Setcolor(0, 7);
			return false;
		}
	}
	Setcolor(0, 7);
	gotoxy(0, y + h + 2);
	return true;
}
bool giaodiendoimatkhau_giaovu(int x, int y, int h, int w, staff& staff1)
{
	ShowCur(1);
	Setcolor(1, 0);
	string d;
	for (int i = y; i <= y + h + 1; i++)
	{
		for (int j = x; j < x + w; j++)
		{
			gotoxy(j, i); cout << " ";
		}
	}
	Setcolor(0, 7);
	Setcolor(11, 0);
	gotoxy(x, y); cout << "                 Change password                  ";
	Setcolor(0, 7);
	gotoxy(x + 1, y + 3); cout << "Current password:";
	gotoxy(x + 1, y + 7); cout << "New password (max 20char):";
	gotoxy(x + 1, y + 11); cout << "New password again:";
	Setcolor(7, 0);
	gotoxy(x + 8, y + 14); cout << "AFTER ENTER TO SAVE CHANGE PLEASE LOG OUT";
	gotoxy(x + 12, y + 15); cout << "ENTER to save change";
	for (int i = x + 1; i < x + w - 1; i++)
	{
		gotoxy(i, y + 4); cout << " ";
		gotoxy(i, y + 8); cout << " ";
		gotoxy(i, y + 12); cout << " ";
	}
	char currentpassword[20]; int j = 0;
	gotoxy(x + 1, y + 4);
	while (true)
	{
		char temp = _getch();
		if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') || temp == 32)
		{
			currentpassword[j] = temp;
			++j;
			cout << currentpassword[j - 1];
		}
		if (temp == '\b' && j >= 1)
		{
			cout << "\b \b";
			--j;
		}
		if (temp == '\r')
		{
			if (j > 0)
			{
				currentpassword[j] = '\0';
				d = currentpassword;
				if (d == staff1.getpassword())
				{
					Setcolor(1, 0);
					gotoxy(x + 1, y + 2); cout << "                ";
					gotoxy(x + 1, y + 5); cout << "                          ";
					Setcolor(7, 0);
					break;
				}
				else
				{
					gotoxy(x + 1, y + 2); cout << "Wrong password !"; gotoxy(x + j + 1, y + 4);
				}
			}
			else
			{
				Setcolor(0, 4);
				gotoxy(x + 1, y + 5); cout << "You didn't type anything !";
				gotoxy(x + 1, y + 4);
				Setcolor(7, 0);
			}
		}
		if (temp == 27)
		{
			Setcolor(0, 7);
			return false;
		}
	}
	char newpassword[20]; int i = 0;
	gotoxy(x + 1, y + 8);
	while (true)
	{
		char temp = _getch();
		if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') || temp == 32)
		{
			newpassword[i] = temp;
			++i;
			cout << newpassword[i - 1];
		}
		if (temp == '\b' && i >= 1)
		{
			cout << "\b \b";
			--i;
		}
		if (temp == '\r')
		{
			if (i > 0)
			{
				newpassword[i] = '\0';
				d = newpassword;
				Setcolor(1, 0);
				gotoxy(x + 1, y + 9); cout << "                          ";
				Setcolor(7, 0);
				break;
			}
			else
			{
				Setcolor(0, 4);
				gotoxy(x + 1, y + 9); cout << "You didn't type anything !";
				gotoxy(x + 1, y + 8);
				Setcolor(7, 0);
			}
		}
		if (temp == 27)
		{
			Setcolor(0, 7);
			return false;
		}
	}
	char checkpassword[20]; int k = 0;
	gotoxy(x + 1, y + 12);
	while (true)
	{
		char temp = _getch();
		if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') || temp == 32)
		{
			checkpassword[k] = temp;
			++k;
			cout << checkpassword[k - 1];
		}
		if (temp == '\b' && k >= 1)
		{
			cout << "\b \b";
			--k;
		}
		if (temp == '\r')
		{
			if (k > 0)
			{
				checkpassword[k] = '\0';
				string temp = checkpassword;
				if (temp == d)
				{
					staff1.changepassword(d);
					break;
				}
				else
				{
					gotoxy(x + 1, y + 10); cout << "Wrong password !"; gotoxy(x + k + 1, y + 12);
				}
			}
			else
			{
				Setcolor(0, 4);
				gotoxy(x + 1, y + 13); cout << "You didn't type anything !";
				gotoxy(x + 1, y + 12);
				Setcolor(7, 0);
			}
		}
		if (temp == 27)
		{
			Setcolor(0, 7);
			return false;
		}
	}
	Setcolor(0, 7);
	gotoxy(0, y + h + 2);
	return true;
}
bool login(int x, int y, int h, int w, bool check, string &path)
{
	ifstream filein;
	string matkhau;
	string d;
	Setcolor(1, 0);
	for (int i = y; i <= y + h + 1; i++)
	{
		for (int j = x; j < x + w; j++)
		{
			gotoxy(j, i); cout << " ";
		}
	}
	Setcolor(11, 0);
	if (check)
	{
		gotoxy(x, y); cout << "         SINH VIEN         ";
	}
	else
	{
		gotoxy(x, y); cout << "          GIAO VU          ";
	}
	Setcolor(0, 7);
	gotoxy(x + 1, y + 3); cout << "Username:";
	gotoxy(x + 1, y + 7); cout << "Password: ";
	Setcolor(7, 0);
	for (int i = x + 1; i < x + w - 1; i++)
	{
		gotoxy(i, y + 4); cout << " ";
		gotoxy(i, y + 8); cout << " ";
	}
	gotoxy(x + 6, y + 10); cout << "ENTER to login";
	gotoxy(x + 6, y + 11); cout << "ESC to go back";
	/*Setcolor(0, 7);
	gotoxy(x + 1, y + 7); cout << "Password: ";
	Setcolor(7, 0);*/
	char s[100]; int j = 0;
	gotoxy(x + 1, y + 4);
	while(true)
	{
		char temp = _getch();
		if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') || temp == 32)
		{
			s[j] = temp;
			++j;
			cout << s[j-1];
		}
		if (temp == '\b' && j >= 1)
		{
			cout << "\b \b";
			--j;
		}
		if (temp == '\r')
		{
			if (j > 0)
			{
				s[j] = '\0';
				Setcolor(1, 0);
				gotoxy(x + 1, y + 5); cout << "                     ";
				Setcolor(7, 0);
				d = s;
				if (check)
				{
					d = "sinhvien\\" + d + ".txt";
				}
				else
				{
					d = "giaovu\\" + d + ".txt";
				}
				filein.open(d, ios::in);
				filein >> matkhau;
				gotoxy(0, y + h + 2);
				if (filein.fail())
				{
					gotoxy(x + 6, y + 2);
					cout << "Sai tai khoan.";
					gotoxy(x + 1+j, y + 4);
				}
				else
				{
					Setcolor(1, 0);
					gotoxy(x + 6, y + 2); cout << "              ";
					Setcolor(7, 0);
					break;
				}
			}
			else
			{
				Setcolor(0, 4);
				gotoxy(x + 1, y + 5); cout << "Ban chua nhap gi ca !";
				gotoxy(x + 1, y + 4);
				Setcolor(7, 0);
			}
		}
		if (temp == 27)
		{
			Setcolor(0, 7);
			return false;
		}
	}
	char a[100]; gotoxy(x + 1, y + 8);
	int i = 0;
	while(true)
	{
		char temp = _getch();
		if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') || temp == 32)
		{
			a[i] = temp;
			++i;
			cout << "*";
		}
		if (temp == '\b' && i >= 1)
		{
			cout << "\b \b";
			--i;
		}
		if (temp == '\r' && i > 0)
		{
			a[i] = '\0';
			string mk = a;
			if (matkhau == mk)
			{
				filein.close();
				Setcolor(1, 0);
				gotoxy(x + 6, y + 2); cout << "              ";
				path = d;
				Setcolor(7, 0);
				break;
			}
			else
			{
				gotoxy(x + 6, y + 6);
				cout << "Sai mat khau.";
				gotoxy(x + 1 + i, y + 8);
			}
		}
		if (temp == 27)
		{
			Setcolor(0, 7);
			return false;
		}
	}
	Setcolor(0, 7);
	/*string d = s;
	d = "sinhvien//" + d + ".txt";
	ifstream filein;
	filein.open(d, ios::in);
	gotoxy(0, y + h + 2);
	if (filein.fail())
	{
		gotoxy(x + 2, y + 1);
		cout << "Sai tai khoan hoac mat khau.";
	}
	else
	{
		filein >> s;
		cout << s;
	}*/
	gotoxy(0, y + h + 2);
	return true;
} 
bool login2(int x, int y, int h, int w, bool check, string& path)
{
	ifstream filein;
	string matkhau;
	string d;
	bool checkdone = false;
	bool checkusername = false;
	bool checkpassword = false;
	Setcolor(1, 0);
	for (int i = y; i <= y + h + 1; i++)
	{
		for (int j = x; j < x + w; j++)
		{
			gotoxy(j, i); cout << " ";
		}
	}
	Setcolor(11, 0);
	if (check)
	{
		gotoxy(x, y); cout << "           STUDENT           ";
	}
	else
	{
		gotoxy(x, y); cout << "            STAFF            ";
	}
	Setcolor(0, 7);
	gotoxy(x + 1, y + 3); cout << "Username:";
	gotoxy(x + 1, y + 7); cout << "Password: ";
	Setcolor(7, 0);
	for (int i = x + 1; i < x + w - 1; i++)
	{
		gotoxy(i, y + 4); cout << " ";
		gotoxy(i, y + 8); cout << " ";
	}
	gotoxy(x + 6, y + 10); cout << "ENTER to login";
	gotoxy(x + 6, y + 11); cout << "ESC to go back";
	/*Setcolor(0, 7);
	gotoxy(x + 1, y + 7); cout << "Password: ";
	Setcolor(7, 0);*/
	char s[100]; int j = 0;
	char a[100]; int i = 0;
	do
	{
		gotoxy(x + 1, y + 4);
		while (true)
		{
			char temp = _getch();
			if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') || temp == 32)
			{
				s[j] = temp;
				++j;
				cout << s[j - 1];
			}
			if (temp == '\b' && j >= 1)
			{
				cout << "\b \b";
				--j;
			}
			if (temp == '\r')
			{
				if (j > 0)
				{
					s[j] = '\0';
					Setcolor(1, 0);
					gotoxy(x + 1, y + 5); cout << "                        ";
					Setcolor(7, 0);
					d = s;
					if (check)
					{
						d = "sinhvien\\" + d+ ".txt";
					}
					else
					{
						d = "giaovu\\" + d + ".txt";
					}
					filein.open(d, ios::in);
					if (filein.fail() == false)
					{
						filein >> matkhau;
						checkusername = true;
					}
					break;
				}
				else
				{
					Setcolor(0, 4);
					gotoxy(x + 1, y + 5); cout << "You did't type anything!";
					gotoxy(x + 1, y + 4);
					Setcolor(7, 0);
				}
			}
			if (temp == 27)
			{
				Setcolor(0, 7);
				return false;
			}
		}
		gotoxy(x + 1, y + 8);
		while (true)
		{
			char temp = _getch();
			if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') || temp == 32)
			{
				a[i] = temp;
				++i;
				cout << "*";
			}
			if (temp == '\b' && i >= 1)
			{
				cout << "\b \b";
				--i;
			}
			if (temp == '\r' && i > 0)
			{
				a[i] = '\0';
				string mk = a;
				if (matkhau == mk && checkusername == true)
				{
					filein.close();
					Setcolor(1, 0);
					gotoxy(x + 1, y + 2); cout << "                           ";
					Setcolor(7, 0);
					path = d;
					checkdone = true;
					Setcolor(7, 0);
					break;
				}
				else
				{
					filein.close();
					gotoxy(x + 1, y + 2); cout << "Wrong username or password!";
					gotoxy(x + 1, y + 4); cout << "                           ";
					gotoxy(x + 1, y + 8); cout << "                           ";
					i = 0; j = 0;
					checkusername = false;
					matkhau = " ";
					break;
				}
			}
			if (temp == 27)
			{
				Setcolor(0, 7);
				return false;
			}
		}
	} while (checkdone == false);
	Setcolor(0, 7);
	/*string d = s;
	d = "sinhvien//" + d + ".txt";
	ifstream filein;
	filein.open(d, ios::in);
	gotoxy(0, y + h + 2);
	if (filein.fail())
	{
		gotoxy(x + 2, y + 1);
		cout << "Sai tai khoan hoac mat khau.";
	}
	else
	{
		filein >> s;
		cout << s;
	}*/
	return true;
}
void giaodiensinhvien(int x, int y, int h, int w,int ythanhsang,string path)
{
	student a;
	a.input_file(path);
	bool checkchange = false;
	while (true)
	{
		if (_kbhit()) {
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 80)
				{
					if (ythanhsang == y + 4 * (h + 1) + 1)
					{
						ythanhsang = y+1;
					}
					else
					{
						ythanhsang += 2;
					}
				}
				else if (c == 72)
				{
					if (ythanhsang == y + 1)
					{
						ythanhsang = y + 4 * (h + 1) + 1;
					}
					else
					{
						ythanhsang -= 2;
					}
				}

			}
			else if (c == 13)
			{
				if (ythanhsang == y + 4 * (h + 1) + 1)
				{
					system("cls");
					if (checkchange)
					{
						a.savefile("sinhvien\\" + a.getID() + ".txt");
					}
					break;
				}
				else if (ythanhsang == y + h + 2)
				{
					system("cls");
					if (giaodiendoimatkhau_sinhvien(35, 5, 15, 50, a))
					{
						checkchange = true;
					};
					system("cls");
				}
				else if (ythanhsang == y + 1)
				{
					system("cls");
					while (true)
					{
						if (_kbhit())
						{
							char c = _getch();
							if (c == 27)
								break;
						}
						a.output();
					}
					system("cls");

				}
			}
		}
		ShowCur(0);
		menu_sinhvien(x, y, h, w,ythanhsang);
	}

}
void giaodiengiaovu(int x, int y, int h, int w, int ythanhsang, string path)
{
	staff b;
	b.input_file(path);
	bool checkchange = false;
	while (true)
	{
		if (_kbhit()) {
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 80)
				{
					if (ythanhsang == y + 8 * (h + 1) + 1)
					{
						ythanhsang = y + 1;
					}
					else
					{
						ythanhsang += 2;
					}
				}
				else if (c == 72)
				{
					if (ythanhsang == y + 1)
					{
						ythanhsang = y + 8 * (h + 1) + 1;
					}
					else
					{
						ythanhsang -= 2;
					}
				}
			}
			else if (c == 13)
			{
				if (ythanhsang == y + 7 * (h + 1) + 1)
				{
					system("cls");
					if (checkchange)
					{
						b.savefile("giaovu\\GV" + b.getID() + ".txt");
					}
					break;
				}
				else if (ythanhsang == y + 1)
				{
					system("cls");
					while (true)
					{
						if (_kbhit())
						{
							char c = _getch();
							if (c == 27)
								break;
						}
						b.output();
					}
					system("cls");
				}
				else if (ythanhsang == y + h + 2)
				{
					system("cls");
					if (giaodiendoimatkhau_giaovu(35, 5, 15, 50, b))
					{
						checkchange = true;
					};
					system("cls");
				}
				else if (ythanhsang == y + 2 * (h + 1) + 1)
				{
					ShowCur(1);
					b.create_schoolyear();
				}
				else if (ythanhsang == y + 3 * (h + 1) + 1)
				{
					system("cls");
					ShowCur(1);
					b.create_class();
					system("cls");
				}
				else if (ythanhsang == y + 6 * (h + 1) + 1)
				{
					system("cls");
					b.add_student();
					system("cls");
				}
			}
		}
		ShowCur(0);
		menu_giaovu(x, y, h, w, ythanhsang);
	}


}
//void menunhapnamhoc_lophoc_hocki(int x, int y, int h, int w, int ythanhsang)
//{
//	create_board_content(x, y, h, w, "NHAP NAM HOC",ythanhsang);
//	create_board_content(x, y+h+1, h, w, "THEM LOP HOC VA SINH VIEN",ythanhsang);
//	create_board_content(x, y + 2*(h + 1), h, w, "TAO HOC KI MOI", ythanhsang);
//}
//void giaodiennhapnamhoc_lophoc_hocki(int x, int y, int h, int w, int ythanhsang)
//{
//	ShowCur(0);
//	while (true)
//	{
//		if (_kbhit()) {
//			char c = _getch();
//			if (c == -32)
//			{
//				c = _getch();
//				if (c == 80)
//				{
//					if (ythanhsang == y + 2 * (h + 1) + 1)
//					{
//						ythanhsang = y + 1;
//					}
//					else
//					{
//						ythanhsang += 2;
//					}
//				}
//				else if (c == 72)
//				{
//					if (ythanhsang == y + 1)
//					{
//						ythanhsang = y + 2 * (h + 1) + 1;
//					}
//					else
//					{
//						ythanhsang -= 2;
//					}
//				}
//			}
//			else if (c == 13)
//			{
//				string year;
//				if (ythanhsang == y + 1)
//				{
//					ShowCur(1);
//					cout << "Nhap nam hoc (2021-2022): ";
//					cin >> year;
//					_mkdir(year.c_str());
//					system("cls");
//				}
//				else if (ythanhsang == y + 3)
//				{
//					ofstream fileout;
//					string lop;
//					string path;
//					do
//					{
//						cout << "School year: ";
//						cin >> year;
//						if (FolderExists(year.c_str()) == false)
//						{
//							cout << "There is not this school year. Try again!" << endl;
//						}
//					} while (FolderExists(year.c_str()) == false);
//					char answer;
//					do
//					{
//						cout << "Name of class: ";
//						cin >> lop;
//						path = year + "\\" + lop + ".txt";
//						/*_mkdir(path.c_str());*/
//						fileout.open(path, ios::out);
//						fileout.close();
//						cout << "Complete! Do you want to continious ? (Y/N): ";
//						cin >> answer;
//					} while (answer == 'Y' || answer == 'y');
//					system("cls");
//				}
//				else if (ythanhsang == y + 5)
//				{
//					int semester;
//					cout << "St of semester (1,2,3): ";
//					cin >> semester;
//					cout << "School year: ";
//					cin >> year;
//				}
//			}
//		}
//		ShowCur(0);
//		menunhapnamhoc_lophoc_hocki(x, y, h, w, ythanhsang);
//	}
//}

// day la ham ma se thao tac het tat ca 
void menu_n_board(int n, int x, int y, int h, int w)
{
	ShowCur(0);//tắt con trỏ nhấp nháy
	int ythanhsang = y + 1;// thanh sáng
	bool check = true;// check true thì la sinhvien, false la giaovu
	list listyear;
	string path; // khi đăng nhập vào thành công thì path này sẽ lưu đường dẫn đến file txt của giáo vụ đó hoặc sinh viên đó.
	while (true)
	{
		//begin : day se la noi hien thi ra thanh sang cua menu sinhvien, giaovu (luu y day la hien thi chứ chưa cử động nha)
		if (ythanhsang == y + 1) // lúc này thanh sáng ở vị trí sinhvien, cập nhật check = true
		{
			Setcolor(7, 0);
			gotoxy(x + 1, y + 1); cout << "STUDENT";
			Setcolor(0, 7);
			gotoxy(x + 1, y + 3); cout << "STAFF";
			check = true;
		}
		else if (ythanhsang == y + 3)//lúc này thanh sáng ở vị trí giáo vụ, cập nhật check = false
		{
			gotoxy(x + 1, y + 1); cout << "STUDENT";
			Setcolor(7, 0);
			gotoxy(x + 1, y + 3); cout << "STAFF";
			Setcolor(0, 7);
			check = false;
		}
		/// end
		// begin: đây mới là nơi để điểu khiển thanh sáng, hàm _kbhit() sẽ bắt sự kiện nếu có dấu hiệu người dùng nhập bàn phím thì hàm này return true;
		// hàm _getch() để bắt xem phím nào đã được nhập (lưu ở dạng char) (vd: 80 là khi nhập mũi tên đ xuống. 72 là khi nhập mũi tên đi lên, enter là 13)
		// khúc bên dưới này sẽ là nơi điều khiển thanh sáng menu sinhvien, giaovu thật sự, thật chất là sẽ thay đổi vị trí thanh sáng để code ở trên hiện thị ra màn hình console. bởi vậy mới nói code ở trên là để hiện thị
		if (_kbhit()) {
			char c = _getch(); 
			if (c == -32) // bắt sự kiện phím mũi tên
			{
				c = _getch();
				if (c == 80 && ythanhsang < y + 3) // nếu mũi tên đi xuống
				{
					ythanhsang += 2; // thanhsang thay đổi vị trí xuống dưới
				}
				else if (c == 72 && ythanhsang > y + 1)// nếu mũi tên đi lên
				{
					ythanhsang -= 2;// thanh sang thay đổi vị trí đi lên
				}
			}
			else if (c == 13)// nếu nhấn enter
			{
				system("cls");// xóa giao diện menu chọn snhvien, giaovu  để hiển thị giao diện login
				while (true)// while true này để thực hiện các menu bên trong
				{
					ShowCur(1);// làm hiển thị con trỏ nhấp nháy lại
					if (login2(x, y, 12, 29,check,path) == false) // khúc này sẽ display ra giao diện login, nếu login thất bại thì
						// sẽ xóa giao diện login đi và break hàm while true này và sau đó sẽ quay lại giao diện menu chọn giaovu, sinhvien 
					{
						system("cls");
						break;
					}
					// nếu login thành công thì sẽ xóa giao diện login đi
					system("cls");
					ShowCur(0);// xóa con trỏ nhấp nháy
					if (check) // ở lúc đầu khi ở giao diện menu chon sinhvien, giaovu có biến check để check đăng nhập vs tư cách sinh viên hay giao vụ
						// khúc này nếu check = true tức là đăng nhập vs tư cách sinh viên nên sẽ vào hàm giaodiensinhvien để thao tác tiếp
					{
						giaodiensinhvien(35, 5, 1, 50, 6,path);
					}
					else
					{
						// khúc này nếu check = false tức là đăng nhập vs tư cách giao vu nên sẽ vào hàm giaodiengiaovu để thao tác tiếp
							giaodiengiaovu(35, 5, 1, 50, 6,path);

					}
				}
			}
		}
		// đây là khi chẳng có sự kiện phím nào cả thì nó sẽ in ra giao diện menu chọn sinhvien, giaovu như bình thường
		ShowCur(0);
		createn_n_board_col(n, x, y, h, w);
	}
}
void taofolder()
{
	string a;
	cin >> a;
	string c;
	c = a + "\\semester1";
	/*_mkdir(a.c_str());*/
	_mkdir(c.c_str());
	ofstream fileout;
	c = c + "\\20clc10.txt";
	fileout.open(c, ios::out);
	fileout.close();
}
bool checkFileWithFstream(string path) {
	ifstream isf(path);
	return isf.good();
}
void doitenfile()
{
	char oldname[] = "sinhvien//21127194.txt";
	char newname[] = "sinhvien//anhtuan_deptrai.txt";

	/*	Deletes the file if exists */
	if (rename(oldname, newname) != 0)
		perror("Error renaming file");
	else
		cout << "File renamed successfully";
}
//bool is_emptyy(ifstream& filestr, string s)
//{
//	string a;
//	filestr.open(s, ios::in);
//	filestr >> a;
//	filestr.close(); // close your file
//
//	if (a.length() == 0) { return true; }
//	else { return false; }
//}

int main()
{
	

	menu_n_board(2, 50, 10, 1, 20);


	return 0;
}