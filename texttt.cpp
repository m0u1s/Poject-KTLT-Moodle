#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <atlstr.h>
#include <direct.h>
#include <cassert>
#include <iomanip>

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
bool is_emptyy(string s)
{
	fstream filestr;
	string a;
	filestr.open(s, ios::in);
	filestr >> a;
	filestr.close();

	if (a.length() == 0) { return true; }
	else { return false; }
}
// lien quan den nam
struct YearCreated {
	string year;
	YearCreated* pnext;
	YearCreated* ppre;
};
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
void Push1CreatedYear_Tail(YearCreated *&head, string year)
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
void Push1CreatedYear_Head(YearCreated *&head, string year)
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
void OutputCreatedYear_File(YearCreated *&head)
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
void PushAllCreatedYear_File(YearCreated *&head)
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
void DeleteListCreatedYear(YearCreated *&head)
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
struct Something
{
	string a;
	Something* pnext;
	Something* prev;
};
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
		cout <<"\t" << i->a << endl;
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
	for (Something* i = head; i != NULL; i=i->pnext)
	{
		if (i->a == nameclass)
			return true;
	}
	return false;
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
	string getbirth()
	{
		return birth;
	}
	void changepassword(string newpassword)
	{
		password = newpassword;
	}
	void input()
	{
		ifstream file;
		cout << "Name: ";
		getline(cin, name);
		cout << "Address: ";
		getline(cin, address);
		while (true)
		{
			cout << "ID: ";
			cin >> ID;
			if (FolderExists(("sinhvien\\" + ID).c_str()))
			{
				cout << "ID exists. Try again!" << endl;
			}
			else
			{
				break;
			}
		}
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
		gotoxy(45, 5); cout << "Name : " << name;
		gotoxy(45, 7); cout << "Gender : " << gender;
		gotoxy(45, 9); cout << "ID: " << ID;
		gotoxy(45, 11); cout << "Address: " << address;
		gotoxy(45, 13); cout << "Socail ID: " << socialID;
		gotoxy(45, 15); cout << "Date of birth: " << birth;
		gotoxy(45, 17); cout << "Phone number: " << phone;
		gotoxy(45, 19); cout << "Password: " << password;
		Setcolor(7, 0);
		gotoxy(45, 21); cout << "ESC TO GO BACK. ";
		Setcolor(0, 7);
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
	void input_file2(ifstream& filein);
	void output()
	{
		gotoxy(45, 3); cout << "Class : " << CLASS;
		person::output();
	}
	/*void class_list(fstream class_list);*/
	void View_Class(string classname)
	{
		student a;
		cout << setw(6) << left << "STT";
		cout << setw(10) << left << "ID";		// độ rộng 5 ký tự, canh trái ID
		cout << setw(30) << left << "Name";	// độ rộng 30 ký tự, canh trái Name
		cout << setw(20) << left << "Gender";	// độ rộng 20 ký tự, canh phải Address
		cout << setw(11) << left << "birth" << endl;
		cout << setfill('-');		// set fill bằng ký tự '-' thay vì ' '
		cout << setw(77) << "-" << endl;	// fill 55 ký tự '-'
		cout << setfill(' ');
		ifstream filein;
		filein.open(classname + ".txt", ios::in);
		int i = 0;
		while (!filein.eof())
		{
			a.input_file2(filein);
			cout << setw(6) << left << i + 1;
			cout << setw(10) << left << a.getID();
			cout << setw(30) << left << a.getname();
			cout << setw(20) << left << a.getgender();
			cout << setw(11) << left << a.getbirth() << endl;
			i++;
		}
		filein.close();
	}
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
	void create_schoolyear(YearCreated*& head)
	{
		string year;
		cout << "School year (ex: 2021-2022): ";
		cin >> year;
		PushArrangeCreatedYear(head, year);
		fstream fileout;
		_mkdir(year.c_str());
		fileout.open(year + "\\class.txt", ios::out);
		fileout.close();
		OutputCreatedYear_File(head);
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
		string path = "sinhvien\\" + a.getID();
		_mkdir(path.c_str());
		path = path + "\\" + a.getID() + ".txt";
		a.savefile(path);
		fstream fileout;
		fileout.open(a.getclass() + ".txt", ios::out | ios::app);
		fileout << endl;
		fileout << a.getID() << "," << a.getname() << "," << a.getgender() << "," << a.getbirth();
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
	void View_Class(string classname);
	void create_class(YearCreated*& head)
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
			cout << "1. Create classes from file txt" << endl;
			cout << "2. Create classes" << endl;
			cout << "3. See list class " << endl;
			cout << "0. Go back to menu " << endl << endl;
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
				cout << endl;
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
								filein2 << lop << ",";
							}
							cout << "Complete! Do you want to continue ? (Y/N): ";
							cin >> answer;
						} while (answer == 'Y' || answer == 'y');
						filein2.close();
					}
			}
			else if (mainanswer == "3")
			{
				system("cls");
				if (head == NULL)
				{
					cout << "Currently there is no schoolyear. So that there are not any class. Please create year, create class to continue." << endl;
					cout << "ENTER TO CONTINUE" << endl;
					system("pause");
				}
				else
				{
					string year1;
					while (true)
					{
						system("cls");
						OutputList(head);
						cout << endl;
						cout << "If you want to go back just type 0" << endl;
						cout << "School year you want to see list class (ex 2021-2022): ";
						cin >> year1;
						if (year1 == "0")
						{
							break;
						}
						if (FolderExists(year1.c_str()))
						{
							if (is_emptyy(year1 + "\\class.txt"))
							{
								cout << "This school year has no class. please add more to view list class." << endl;
								cout << "ENTER TO CONTINUE." << endl;
								system("pause");
							}
							else
							{
								ifstream filein;
								string a;
								string answer;
								string name;
								Something* ClassInYear = NULL;
								filein.open(year1 + "\\class.txt", ios::in);
								while (!filein.eof())
								{
									getline(filein, a, ',');
									Push1Something_Tail(ClassInYear,a);
								}
								filein.close();
								while (true)
								{
									system("cls");
									OutputListSomething(ClassInYear);
									cout << "1. View the list student of class." << endl;
									cout << "0. Go back." << endl;
									cout << "Your answer: ";
									cin >> answer;
									if (answer == "1")
									{
										int check = 0;
										while (check == 0)
										{
											cout << "Name of class: ";
											cin >> name;
											if (CheckNameClassInYear(ClassInYear,name))
											{
												cout << endl;
												/*View_Class(name);*/
												check = 1;
												cout << "\n\nENTER TO CONTINUE." << endl;
												system("pause");
											}
											else
											{
												cout << "There is not this class in this school year. Try again!" << endl;
											}
										}
									}
									else
									{
										break;
									}
								}
								DeleteListSomething(ClassInYear);
							}
						}
						else
						{
							cout << "There is not this school year. Create it or try again." << endl;
							cout << "ENTER TO CONTINUE." << endl;
							system("pause");
						}
					}
				}
			}
			else
			{
				system("cls");
				break;
			}
		}
		cin.ignore();
	}
	void create_course(Course course, fstream& Course);
	void create_semester(semester x, fstream& semester);
	void adjust_Courses(fstream& Course);
	void delete_course();
	// End of regis time
	/*void read_Classlist();*/
	void read_studentList();
	// End of semester
	void output_Course_Student();
	void adjust_StudentGrades();
	void read_ClassGrades();
};
// Cac ham lien quan den giao dien chinh
bool Login(int, int, int, int, bool, string& );
void Create_Board(int x, int y, int h, int w)
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
void Create_n_Board_Col(int n, int x, int y, int h, int w)
{
	for (int i = 0; i < n; i++)
	{
		Create_Board(x, y + (h + 1)*i, h, w);
	}
}
void Create_n_Board_Row(int n, int x, int y, int h, int w)
{
	for (int i = 0; i < n; i++)
	{
		Create_Board(x+w*i+1*i, y, h, w);
	}
}
void Create_Board_Content(int x, int y, int h, int w, string content, int ythanhsang)
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
void Menu_SinhVien(int x, int y, int h, int w, int ythanhsang)
{
	Create_Board_Content(x, y, h, w, "YOUR INFORMATION",ythanhsang);
	Create_Board_Content(x, y+h+1, h, w, "CHANGE PASSWORD",ythanhsang);
	Create_Board_Content(x, y + 2*(h + 1), h, w, "VIEW MEMBER IN YOUR CLASS", ythanhsang);
	Create_Board_Content(x, y+3*(h+1), h, w, "REGIST COURSE",ythanhsang);
	Create_Board_Content(x, y + 4 * (h + 1), h, w, "SCORE COURSE",ythanhsang);
	Create_Board_Content(x, y + 5 * (h + 1), h, w, "LOG OUT",ythanhsang);
}
void Menu_GiaoVu(int x, int y, int h, int w, int ythanhsang)
{
	Create_Board_Content(x, y, h, w, "YOUR INFORMATION",ythanhsang);
	Create_Board_Content(x, y + h + 1, h, w, "CHANGE PASSWORD",ythanhsang);
	Create_Board_Content(x, y+2*(h+1), h, w, "CREATE SCHOOLYEAR", ythanhsang);
	Create_Board_Content(x, y + 3*(h + 1), h, w, "CREATE CLASS", ythanhsang);
	Create_Board_Content(x, y + 4 * (h + 1), h, w, "CREATE SEMESTER", ythanhsang);
	Create_Board_Content(x, y + 5 * (h + 1), h, w, "CREATE COURSE",ythanhsang);
	Create_Board_Content(x, y + 6 * (h + 1), h, w, "ADD STUDENT", ythanhsang);
	Create_Board_Content(x, y + 7 * (h + 1), h, w, "LOG OUT",ythanhsang);
}
bool GiaoDienDoiMatKhau_SinhVien(int x, int y, int h, int w, student &student1)
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
	gotoxy(x + 1, y + 7); cout << "New password (max 25char):";
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
	char currentpassword[100]; int j = 0;
	gotoxy(x + 1, y + 4);
	while (true)
	{
		char temp = _getch();
		if (((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9')) && j <= 25)
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
	char newpassword[100]; int i = 0;
	gotoxy(x + 1, y + 8);
	while (true)
	{
		char temp = _getch();
		if (((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9')) && i <= 25)
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
	char checkpassword[100]; int k = 0;
	gotoxy(x + 1, y + 12);
	while (true)
	{
		char temp = _getch();
		if (((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9')) && k <= 25)
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
bool GiaoDienDoiMatKhau_GiaoVu(int x, int y, int h, int w, staff& staff1)
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
	gotoxy(x + 1, y + 7); cout << "New password (max 25char):";
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
	char currentpassword[100]; int j = 0;
	gotoxy(x + 1, y + 4);
	while (true)
	{
		char temp = _getch();
		if (((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9')) && j <= 25)
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
	char newpassword[100]; int i = 0;
	gotoxy(x + 1, y + 8);
	while (true)
	{
		char temp = _getch();
		if (((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9')) && i <= 25)
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
	char checkpassword[100]; int k = 0;
	gotoxy(x + 1, y + 12);
	while (true)
	{
		char temp = _getch();
		if (((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9')) && k <= 25)
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
bool Login(int x, int y, int h, int w, bool check, string &path)
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
bool Login2(int x, int y, int h, int w, bool check, string& path)
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
			if (((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9')) && j <=25)
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
						d = "sinhvien\\" + d + "\\" + d + ".txt";
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
			if (((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9')) && i <= 25)
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
void GiaoDienSinhVien(int x, int y, int h, int w,int ythanhsang,string path)
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
					if (ythanhsang == y + 5 * (h + 1) + 1)
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
						ythanhsang = y + 5 * (h + 1) + 1;
					}
					else
					{
						ythanhsang -= 2;
					}
				}

			}
			else if (c == 13)
			{
				if (ythanhsang == y + 5 * (h + 1) + 1)
				{
					system("cls");
					if (checkchange)
					{
						a.savefile("sinhvien\\" + a.getID() + "\\" + a.getID() + ".txt");
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
						a.output();
					}
					system("cls");

				}
				else if (ythanhsang == y + h + 2)
				{
					system("cls");
					if (GiaoDienDoiMatKhau_SinhVien(35, 5, 15, 50, a))
					{
						checkchange = true;
					};
					system("cls");
				}
			}
		}
		ShowCur(0);
		Menu_SinhVien(x, y, h, w,ythanhsang);
	}

}
void GiaoDienGiaoVu(int x, int y, int h, int w, int ythanhsang, string path)
{
	staff b;
	b.input_file(path);
	bool checkchange = false;
	YearCreated* head = NULL;
	if (is_emptyy("schoolyear.txt") == false)
	{
		PushAllCreatedYear_File(head);
	}
	while (true)
	{
		if (_kbhit()) {
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 80)
				{
					if (ythanhsang == y + 7 * (h + 1) + 1)
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
						ythanhsang = y + 7 * (h + 1) + 1;
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
					DeleteListCreatedYear(head);
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
					if (GiaoDienDoiMatKhau_GiaoVu(35, 5, 15, 50, b))
					{
						checkchange = true;
					};
					system("cls");
				}
				else if (ythanhsang == y + 2 * (h + 1) + 1)
				{
					ShowCur(1);
					b.create_schoolyear(head);
				}
				else if (ythanhsang == y + 3 * (h + 1) + 1)
				{
					system("cls");
					ShowCur(1);
					b.create_class(head);
					system("cls");
				}
				else if (ythanhsang == y + 6 * (h + 1) + 1)
				{
					system("cls");
					ShowCur(1);
					b.add_student();
					system("cls");
				}
			}
		}
		ShowCur(0);
		Menu_GiaoVu(x, y, h, w, ythanhsang);
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
void Menu_n_Board(int n, int x, int y, int h, int w)
{
	ShowCur(0);//tắt con trỏ nhấp nháy
	int ythanhsang = y + 1;// thanh sáng
	bool check = true;// check true thì la sinhvien, false la giaovu
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
					if (Login2(x, y, 12, 29,check,path) == false) // khúc này sẽ display ra giao diện login, nếu login thất bại thì
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
						GiaoDienSinhVien(35, 5, 1, 50, 6,path);
					}
					else
					{
						// khúc này nếu check = false tức là đăng nhập vs tư cách giao vu nên sẽ vào hàm giaodiengiaovu để thao tác tiếp
						GiaoDienGiaoVu(35, 5, 1, 50, 6,path);

					}
				}
			}
		}
		// đây là khi chẳng có sự kiện phím nào cả thì nó sẽ in ra giao diện menu chọn sinhvien, giaovu như bình thường
		ShowCur(0);
		Create_n_Board_Col(n, x, y, h, w);
	}
}
// các hàm bên ngoài
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
int main()
{
	

	Menu_n_Board(2, 50, 10, 1, 20);
	return 0;
}