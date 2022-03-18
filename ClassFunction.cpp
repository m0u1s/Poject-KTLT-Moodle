#include "MainFunction.h"
using namespace std;
//semester::method
// các hàm đã hoàn thành của semester
using namespace std;
void semester::filein_Cur(date& currentday)
{
	fstream fileincur;
	if (is_emptyy("cursemester.txt") == false)
	{
		fileincur.open("cursemester.txt", ios::in);
		getline(fileincur, SchoolYear, ',');
		getline(fileincur, name);
		fileincur.close();
	}
	if (name != "0")
	{
		fileincur.open(SchoolYear + "\\" + name + ".txt", ios::in);
		fileincur >> start.day; fileincur.seekg(1, 1); fileincur >> start.month;
		fileincur.seekg(1, 1); fileincur >> end.day; fileincur.seekg(1, 1); fileincur >> end.month;
		fileincur >> StartRegCourse.day; fileincur.seekg(1, 1); fileincur >> StartRegCourse.month;
		fileincur.seekg(1, 1); fileincur >> EndRegCourse.day; fileincur.seekg(1, 1); fileincur >> EndRegCourse.month;
		fileincur.close();
	}
	fileincur.open("curday.txt", ios::in);
	fileincur >> currentday.day;
	fileincur.seekg(1, 1);
	fileincur >> currentday.month;
	fileincur.close();
}
void semester::DeleteListCourse()
{
	Course* temppcourse;
	tempStudent* temppstudent;
	while (CreatedCourse != NULL)
	{
		while (CreatedCourse->headStudent != NULL)
		{
			temppstudent = CreatedCourse->headStudent;
			CreatedCourse->headStudent = CreatedCourse->headStudent->pnext;
			delete temppstudent;
		}
		temppcourse = CreatedCourse;
		CreatedCourse = CreatedCourse->pnext;
		delete CreatedCourse;
	}
	CreatedCourse = NULL;
}
semester::~semester() {
	Course* temppcourse;
	tempStudent* temppstudent;
	while (CreatedCourse != NULL)
	{
		while (CreatedCourse->headStudent != NULL)
		{
			temppstudent = CreatedCourse->headStudent;
			CreatedCourse->headStudent = CreatedCourse->headStudent->pnext;
			delete temppstudent;
		}
		temppcourse = CreatedCourse;
		CreatedCourse = CreatedCourse->pnext;
		delete CreatedCourse;
	}
}
//chưa hoàn thành của semester
void semester::PushTailCourse(Course*& a) 
{
	system("cls");
	Course* CurrentCourse = a;
	while (CurrentCourse->pnext != nullptr)
	{
		CurrentCourse = CurrentCourse->pnext;
	}
	if (a == nullptr) {
		a = new Course;
		cout << "Enter the Course-code: ";
		cin >> a->Course_Code;
		cout << "Enter the Course-name: ";
		cin >> a->Course_Name;
		cout << "Enter the Credits: ";
		cin >> a->credits;
		cout << "Enter the Course-teacher: ";
		cin >> a->Teacher;
		cout << "Enter the first day of class in week: ";
		cin >> a->Weekday1;
		cout << "Enter the first day shift of class in week: ";
		cin >> a->shift1;
		cout << "Enter the first day shift of class in week: ";
		cout << "Enter the second day of class in week: ";
		cin >> a->Weekday2;
		cout << "Enter the second day shift of class in week: ";
		cin >> a->shift2;

		tempStudent* Head = new tempStudent;
		tempStudent* Cur = Head;

		int i = 1;
		cout << "Now you will keep entering 50 student into the course!";
		while (i <= 50) {
			if (i == 1 || i == 11 || i == 21 || i == 31 || i == 41) {
				cout << "You are adjust the " << i << "st Student\n";
			}
			else if (i == 2 || i == 12 || i == 22 || i == 32 || i == 42) {
				cout << "You are adjust the " << i << "nd Student\n";
			}
			else if (i == 3 || i == 13 || i == 23 || i == 33 || i == 43) {
				cout << "You are adjust the " << i << "rd Student\n";
			}
			else cout << "You are adjust the " << i << "th Student\n";
			cout << "Enter the sutdent's class: ";
			cin >> Cur->Class;
			cout << "Enter the student's ID: ";
			cin >> Cur->ID;
			cout << "Enter the sutdent's class: ";
			cin >> Cur->name;
			i++;
			Cur = Cur->pnext;
			system("cls");
		}
		cout << "You have finished";
	}
	else {
		cout << "Enter the Course-code: "; 
		cin >> CurrentCourse->Course_Code;
		cout << "Enter the Course-name: ";
		cin >> CurrentCourse->Course_Name;
		cout << "Enter the Credits: ";
		cin >> CurrentCourse->credits;
		cout << "Enter the Course-teacher: ";
		cin >> CurrentCourse->Teacher;
		cout << "Enter the first day of class in week: ";
		cin >> CurrentCourse->Weekday1;
		cout << "Enter the first day shift of class in week: ";
		cin >> CurrentCourse->shift1;
		cout << "Enter the first day shift of class in week: ";
		cout << "Enter the second day of class in week: ";
		cin >> CurrentCourse->Weekday2;
		cout << "Enter the second day shift of class in week: ";
		cin >> CurrentCourse->shift2;
		
		tempStudent* Head = new tempStudent;
		tempStudent* Cur = Head; 
		
		int i = 1; 
		cout << "Now you will keep entering 50 student into the course!"; 
		while (i <= 50) {
			if (i == 1 || i == 11 || i == 21 || i == 31 || i == 41) {
				cout << "You are adjust the " << i << "st Student\n";
			}
			else if (i == 2 || i == 12 || i == 22 || i == 32 || i == 42) {
				cout << "You are adjust the " << i << "nd Student\n";
			}
			else if (i == 3 || i == 13 || i == 23 || i == 33 || i == 43) {
				cout << "You are adjust the " << i << "rd Student\n";
			}
			else cout << "You are adjust the " << i << "th Student\n";
			cout << "Enter the sutdent's class: ";
			cin >> Cur->Class;
			cout << "Enter the student's ID: ";
			cin >> Cur->ID;
			cout << "Enter the sutdent's class: ";
			cin >> Cur->name;
			i++;
			Cur = Cur->pnext;
			system("cls");
		}
		cout << "You have finished"; 
	}
	system("pause");
	system("cls");
}
void semester::DeleteCourse(short Course_code, short Course_Name)
{
	
}
void semester::BangDanhSachCourse()
{
	
}
/////////////////////////////////////////////////////
//person::method
//đã hoàn thành của person
string person::getpassword() {
	return password;
}
string person::getID() {
	return ID;
}
string person::getname() {
	return name;
}
string person::getgender() {
	return gender;
}
string person::getbirth() {
	return birth;
}
void person::changepassword(string newpassword) {
	password = newpassword;
}
void person::input() {
	ifstream file;
	cout << "Name: ";
	getline(cin, name);
	cout << "Address: ";
	getline(cin, address);
	while (true) {
		cout << "ID: ";
		cin >> ID;
		if (FolderExists(("sinhvien\\" + ID).c_str())) cout << "ID exists. Try again!" << endl;
		else break;
	}
	cout << "social ID: ";
	cin >> socialID;
	cout << "Gender: ";
	cin >> gender;
	cin.ignore();
	do {
		cout << "Birth (dd/mm/yyyy): ";
		getline(cin, birth);
		if (checkBirth(birth) == false) cout << "Wrong format! Try again." << endl;
	} while (checkBirth(birth) == false);
	cout << "Phone number: ";
	cin >> phone;
	password = "123456";
}
void person::input_file(string path) {
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
void person::output() {
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
//chưa hoàn thành
void person::edit_profile() {
	Modeptrai();
}
/////////////////////////////////////////////////////
//student::method
//đã hoàn thành
void student::savefile(string path) {
	ofstream fileout;
	fileout.open(path, ios::out);
	fileout << password << endl;
	fileout << CLASS << "," << name << "," << ID << "," << gender << "," << birth << "," << socialID << "," << phone << "," << address;
	fileout.close();
}
string student::getclass() {
	return CLASS;
}
void student::input() {
	ifstream fileinput;
	person::input();
	while (true) {
		cout << "Class to add: ";
		cin >> CLASS;
		fileinput.open(CLASS + ".txt", ios::in);
		if (fileinput.fail()) cout << "There is not this class. Try Again!" << endl;
		else {
			fileinput.close();
			break;
		}
		fileinput.close();
	}
}
void student::input_file(string path) {
	ifstream filein;
	filein.open(path, ios_base::in);
	getline(filein, password);
	getline(filein, CLASS, ',');
	getline(filein, name, ',');
	getline(filein, ID, ',');
	getline(filein, gender, ',');
	getline(filein, birth, ',');
	getline(filein, socialID, ',');
	getline(filein, phone, ',');
	getline(filein, address);
	filein.close();
}
void student::input_file2(ifstream& filein) {
	getline(filein, ID, ',');
	getline(filein, name, ',');
	getline(filein, gender, ',');
	getline(filein, birth);
}
void student::output() {
	gotoxy(45, 3); cout << "Class : " << CLASS;
	person::output();
}
void student::View_Class(string classname) {
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
	while (!filein.eof()) {
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
//chưa hoàn thành 
void student::register_course(fstream course_list, fstream& course_registered){
	Modeptrai();
	}
void student::courses_infomation(fstream course_registered){
	Modeptrai();
	}
void student::delete_course(fstream& course_registered){
	Modeptrai();
	}
void student::view_registered_course(fstream course_registered){
	Modeptrai();
	}
void student::view_course_member(fstream course_registered) {
	Modeptrai();
}
/////////////////////////////////////////////////////
//staff::method
//đã hoàn thành
void staff::savefile(string path)
{
	ofstream fileout;
	fileout.open(path, ios::out);
	fileout << password << endl;
	fileout << name << "," << ID << "," << gender << "," << birth << "," << socialID << "," << phone << "," << address;
	fileout.close();
}
void staff::create_schoolyear(YearCreated*& head, const date& currentday)
{
	if (currentday.day == 1 && currentday.month == 9)
	{
		string year;
		cout << "School year (ex: 2021-2022): ";
		cin >> year;
		PushArrangeCreatedYear(head, year);
		fstream fileout;
		_mkdir(year.c_str());
		fileout.open(year + "\\class.txt", ios::out);
		fileout.close();
		fileout.open(year + "\\semester 1.txt", ios::out);
		fileout.close();
		fileout.open(year + "\\semester 2.txt", ios::out);
		fileout.close();
		fileout.open(year + "\\semester 3.txt", ios::out);
		fileout.close();
		OutputCreatedYear_File(head);
	}
	else
	{
		cout << "Wait until 1/1 to do this." << endl;
		system("pause");
	}
}
void staff::add_student()
{
	student a;
	string year;
	cout << "\tADD STUDENT" << endl;
	cin.ignore(1000, '\n');
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
void staff::View_Class(string classname)
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
void staff::create_class(YearCreated*& head)
{
	string year;
	fstream filein1;
	fstream filein2;
	string lop;
	string path;
	/*cin >> mainanswer;
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
					filein2 << lop << ",";
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
							Push1Something_Tail(ClassInYear, a);
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
									if (CheckNameClassInYear(ClassInYear, name))
									{
										cout << endl;
										View_Class(name);
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
	}*/
	int ythanhsang = 6, y = 5, h = 1;
	while (true) {
		BangTaoLop(35, 5, 1, 50, ythanhsang);
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 80) {
					if (ythanhsang == y + 3 * (h + 1) + 1) ythanhsang = y + 1;
					else ythanhsang += 2;
				}
				else if (c == 72) {
					if (ythanhsang == y + 1) ythanhsang = y + 3 * (h + 1) + 1;
					else ythanhsang -= 2;
				}
			}
			else if (c == 13) {
				system("cls");
				ShowCur(1);
				if (ythanhsang == y + 1)
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
								filein2 << lop << ",";
							}
							cout << "Complete! Do you want to continue ? (Y/N): ";
							cin >> answer;
						} while (answer == 'Y' || answer == 'y');
						filein2.close();
					}
				}
				else if (ythanhsang == y + (h + 1) + 1) {
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
				else if (ythanhsang == y + 2 * (h + 1) + 1)
				{
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
										Push1Something_Tail(ClassInYear, a);
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
												if (CheckNameClassInYear(ClassInYear, name))
												{
													cout << endl;
													View_Class(name);
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
				else if (ythanhsang == y + 3 * (h + 1) + 1) {
					break;
				}
				system("cls");
			}
		}
		ShowCur(0);
	}
}
void staff::create_semester(semester& currentsemester, date& currentday)
{
	ShowCur(1);
	ofstream fileout;
	if ((currentsemester.name == "0" && currentsemester.SchoolYear == "0") ||
		(currentday.day == 1 && (currentday.month == 9 || currentday.month == 1 || currentday.month == 5)))
	{
		if (currentday.month >= 9 && currentday.month <= 12)
		{
			currentsemester.name = "semester 1";
		}
		else if (currentday.month <= 4 && currentday.month >= 1)
		{
			currentsemester.name = "semester 2";
		}
		else
		{
			currentsemester.name = "semester 3";
		}
		cout << currentsemester.name << endl;
		cout << "Start day: "; cin >> currentsemester.start.day;
		cout << "Start month: "; cin >> currentsemester.start.month;
		cout << "End day: "; cin >> currentsemester.end.day;
		cout << "End month: "; cin >> currentsemester.end.month;
		do
		{
			cout << "Choose the school year of semester: ";
			cin >> currentsemester.SchoolYear;
			if (FolderExists(currentsemester.SchoolYear.c_str()) == false)
			{
				cout << "There is not this school year. Try again!" << endl;
			}
		} while (FolderExists(currentsemester.SchoolYear.c_str()) == false);
		system("cls");
		cout << "Course registration session: " << endl;
		cout << "Start day to regist Course: "; cin >> currentsemester.StartRegCourse.day;
		cout << "Start month to regist Course: "; cin >> currentsemester.StartRegCourse.month;
		cout << "End day to regist Course: "; cin >> currentsemester.EndRegCourse.day;
		cout << "End month to regist Course: "; cin >> currentsemester.EndRegCourse.month;
		currentsemester.CheckEndReg = false;
		fileout.open("cursemester.txt", ios::out);
		fileout << currentsemester.SchoolYear << "," << currentsemester.name;
		fileout.close();
		fileout.open(currentsemester.SchoolYear + "\\" + currentsemester.name + ".txt", ios::out);
		fileout << currentsemester.start.day << "," << currentsemester.start.month << ",";
		fileout << currentsemester.end.day << "," << currentsemester.end.month << endl;
		fileout << currentsemester.StartRegCourse.day << "," << currentsemester.StartRegCourse.month << ",";
		fileout << currentsemester.EndRegCourse.day << "," << currentsemester.EndRegCourse.month;
		fileout.close();
		currentday.day++;
		fileout.open("curday.txt", ios::out);
		fileout << currentday.day << "," << currentday.month;
		fileout.close();
		system("pause");
	}
	else
	{
		cout << "Try until 1/9 or 1/1 or 1/5!" << endl;
		system("pause");
	}
}
//chưa hoàn thành 
void staff::create_course(){
	Modeptrai();
}
void staff::adjust_Courses(fstream Course) {
	Modeptrai();
}
void staff::delete_course(){
	Modeptrai();
}
void staff::read_studentList(){
	Modeptrai();
}
void staff::output_Course_Student(){
	Modeptrai();
}
void staff::adjust_StudentGrades(){
	Modeptrai();
}
void staff::read_ClassGrades(){
	Modeptrai();
}
