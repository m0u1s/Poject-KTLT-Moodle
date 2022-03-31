#include "MainFunction.h"
void DeletetempStudent(tempStudent*& head, string &IDstudent)
{
	tempStudent* pCur = head;
	for (tempStudent* i = head; i != NULL; i=i->pnext)
	{
		if (i->ID == IDstudent)
		{
			if (i == head)
			{
				head = head->pnext;
				delete i;
				break;
			}
			else
			{
				pCur->pnext = i->pnext;
				delete i;
				break;
			}
		}
		pCur = i;
	}
}
void semester::checkendreg(const date& cur)
{
	if (cur.month > EndRegCourse.month || (cur.day == 1 && (cur.month == 9 || cur.month == 1 || cur.month == 5)) || cur.month < StartRegCourse.month)
	{
		CheckEndReg = true;
	}
	else if (cur.month == EndRegCourse.month)
	{
		if (cur.day > EndRegCourse.day || cur.day < StartRegCourse.day)
		{
			CheckEndReg = true;
		}
	}
}
void semester::checkendsemester(const date& cur)
{
	if (cur.month > end.month || (cur.day == 1 && (cur.month == 9 || cur.month == 1 || cur.month == 5)) || cur.month < start.month)
	{
		checkEndSemester = true;
	}
	else if (cur.month == end.month)
	{
		if (cur.day > end.day)
		{
			checkEndSemester = true;
		}
	}
}
void semester::PushTailCourse(Course*& a) 
{
	if (CreatedCourse == NULL)
	{
		CreatedCourse = a;
	}
	else
	{
		Course* pCur = CreatedCourse;
		while (pCur->pnext != NULL)
		{
			pCur = pCur->pnext;
		}
		pCur->pnext = a;
	}
}
void semester::PushTailStudent(Course*& a, tempStudent*& b)
{
	if (a->headStudent == NULL)
	{
		a->headStudent = b;
	}
	else
	{
		tempStudent* pCur = a->headStudent;
		while (pCur->pnext != NULL)
		{
			pCur = pCur->pnext;
		}
		pCur->pnext = b;
	}
}
void semester::Ouput_file()
{
	ofstream fileout;
	fileout.open(SchoolYear + "\\" + name + ".txt", ios::out);
	fileout << start.day << "," << start.month << "," << end.day << "," << end.month << endl;
	fileout << StartRegCourse.day << "," << StartRegCourse.month << "," << EndRegCourse.day << "," << EndRegCourse.month;
	if (CreatedCourse != NULL)
	{
		for (Course* i = CreatedCourse; i != NULL; i = i->pnext)
		{
			fileout << endl;
			fileout << i->Course_Code << "," << i->Course_Name << "," << i->credits << "," << i->Maxstudent << "," << i->Weekday1 << "," << i->shift1 << "," << i->Weekday2 << "," << i->shift2 <<"," << i->Room<< "," << i->Teacher;
		}
	}
	fileout.close();
}
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
		if (fileincur.eof() == false)
		{
			string c;
			getline(fileincur, c);
			Course* d;
			ifstream fileinstu;
			while (!fileincur.eof())
			{
				d = new Course;
				getline(fileincur, d->Course_Code, ',');
				getline(fileincur, d->Course_Name, ',');
				fileincur >> d->credits;
				fileincur.seekg(1, 1);
				fileincur >> d->Maxstudent;
				fileincur.seekg(1, 1);
				getline(fileincur, d->Weekday1, ',');
				fileincur >> d->shift1;
				fileincur.seekg(1, 1);
				getline(fileincur, d->Weekday2, ',');
				fileincur >> d->shift2;
				fileincur.seekg(1, 1);
				getline(fileincur, d->Room,',');
				getline(fileincur, d->Teacher);
				tempStudent* temppp;
				if (is_emptyy(SchoolYear + "\\" + d->Course_Code + "_" + d->Course_Name + "_" + name + ".txt") == false)
				{
					ifstream fileinStu;
					fileinStu.open(SchoolYear + "\\" + d->Course_Code + "_" + d->Course_Name + "_" + name + ".txt", ios::in);
					while (!fileinStu.eof())
					{
						d->CurNumStudent++;
						temppp = new tempStudent;
						getline(fileinStu, temppp->Class, ',');
						getline(fileinStu, temppp->name, ',');
						getline(fileinStu, temppp->ID);
						PushTailStudent(d, temppp);
					}
					fileinStu.close();
				}
				PushTailCourse(d);
			}
		}
		fileincur.close();
	}
	fileincur.open("curday.txt", ios::in);
	fileincur >> currentday.day;
	fileincur.seekg(1, 1);
	fileincur >> currentday.month;
	fileincur.close();
}
bool semester::DeleteCourse(string Course_code, string Course_Name)// Xóa course,tham số truyền vào là id course, tên course cần xóa
{
	Course* Cur = CreatedCourse;
	tempStudent* temppstudent;
	for (Course* i = CreatedCourse; i != NULL; i = i->pnext)
	{
		if (i->Course_Code == Course_code && i->Course_Name == Course_Name)
		{
			if (i == CreatedCourse)
			{
				CreatedCourse = CreatedCourse->pnext;
				while (i->headStudent != NULL)
				{
					temppstudent = i->headStudent;
					i->headStudent = i->headStudent->pnext;
					delete temppstudent;
				}
				delete i;
			}
			else
			{
				Cur->pnext = i->pnext;
				while (i->headStudent != NULL)
				{
					temppstudent = i->headStudent;
					i->headStudent = i->headStudent->pnext;
					delete temppstudent;
				}
				delete i;
			}
			remove((SchoolYear + "\\" + Course_code + "_" + Course_Name + "_" + name + ".txt").c_str());
			Ouput_file();
			return true;
		}
		Cur = i;
	}
	return false;
}
void semester::InsertCourse(Course*& a)
{
	PushTailCourse(a);
	fstream fileoutt;
	fileoutt.open(SchoolYear + "\\" + a->Course_Code + "_" + a->Course_Name + "_" + name + ".txt", ios::out);
	fileoutt.close();
	fileoutt.open(SchoolYear + "\\" + name + ".txt", ios::out | ios::app);
	fileoutt << endl;
	fileoutt << a->Course_Code << "," << a->Course_Name << "," << a->credits << "," << a->Maxstudent << "," << a->Weekday1 << "," << a->shift1 << "," << a->Weekday2 << "," << a->shift2 << "," << a->Room << "," << a->Teacher;
	fileoutt.close();
}
void semester::BangDanhSachCourse()
{
	cout << "\t\t\t\t(1) 7h30   (2) 9h30   (3) 13h30   (4) 15h30" << endl << endl;
	cout << setw(11) << left << "  ID";
	cout << setw(14) << left << "Course_name";		// độ rộng 5 ký tự, canh trái ID
	cout << setw(9) << left << "Credit";	// độ rộng 30 ký tự, canh trái Name
	cout << setw(6) << left << "Max";	// độ rộng 20 ký tự, canh phải Address
	cout << setw(12) << left << "Session 1";
	cout << setw(12) << left << "Session 2";
	cout << setw(27) << left << "Teacher";
	cout << setw(7) << left << "Room";
	cout << setw(6) << left << "Current student" << endl;
	cout << setfill('-');		// set fill bằng ký tự '-' thay vì ' '
	cout << setw(115) << "-" << endl;	// fill 55 ký tự '-'
	cout << setfill(' ');
	for (Course* i = CreatedCourse; i != NULL; i=i->pnext)
	{
		cout << setw(11) << left << i->Course_Code;
		cout << setw(14) << left << i->Course_Name;		// độ rộng 5 ký tự, canh trái ID
		cout << setw(9) << left << i->credits;	// độ rộng 30 ký tự, canh trái Name
		cout << setw(6) << left << i->Maxstudent;	// độ rộng 20 ký tự, canh phải Address
		cout << setw(12) << left << i->Weekday1 + " (" + to_string(i->shift1) + ")";
		cout << setw(12) << left << i->Weekday2 + " (" + to_string(i->shift2) + ")";
		cout << setw(27) << left << i->Teacher;
		cout << setw(10) << left << i->Room;
		cout << setw(6) << left << i->CurNumStudent << endl;
	}
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
		delete temppcourse;
	}
	CreatedCourse = NULL;
}
semester::~semester()
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
		delete temppcourse;
	}
}
//
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
//
bool student::CheckCourse(string CourseID, semester& a)
{
	Course* Cur = a.CreatedCourse;
	bool check = false;
	while (Cur != NULL) {
		if (Cur->Course_Code == CourseID) {
			check = true;
			break;
		}
		Cur = Cur->pnext;
	}
	if (check == false) return false;
	if (Cur->CurNumStudent >= Cur->Maxstudent)
	{
		cout << "This course has been full of students" << endl;
		return false;
	}
	if (this->NumCourse >= 5)
	{
		cout << "You has registered 5 courses" << endl;
		return false;
	}
	// Hiện tại đã có class Cur check đã trùng với cái đăng kí chưa
	for (Course_Result* k = this->RegistedCoursee; k != NULL; k = k->pnext1) {
		if (Cur->Weekday1 == k->Weekday1)
			if (Cur->shift1 == k->shift1)
			{
				cout << "This course has the same session with the one you registered" << endl;
				return false;
			}
		if (Cur->Weekday1 == k->Weekday2)
			if (Cur->shift1 == k->shift2)
			{
					cout << "This course has the same session with the one you registered" << endl;
					return false;
			}

		if (Cur->Weekday2 == k->Weekday1)
			if (Cur->shift2 == k->shift1)
			{
				cout << "This course has the same session with the one you registered" << endl;
				return false;
			}

		if (Cur->Weekday2 == k->Weekday2)
			if (Cur->shift2 == k->shift2)
			{
				cout << "This course has the same session with the one you registered" << endl;
				return false;
			}
	}
	return true;
}
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
void student::output() {
	gotoxy(45, 3); cout << "Class : " << CLASS;
	person::output();
}
void student::View_Class(string classname) {
	tempStudent a; string b, c;
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
		getline(filein, a.ID, ',');
		getline(filein, a.name, ',');
		getline(filein, b, ',');
		getline(filein, c);
		cout << setw(6) << left << i + 1;
		cout << setw(10) << left << a.ID;
		cout << setw(30) << left << a.name;
		cout << setw(20) << left << b;
		cout << setw(11) << left << c << endl;
		i++;
	}
	filein.close();
}
void student::InsertRegCoursetoList(string &CourseID, semester& a)
{
	ofstream fileout;
	if (is_emptyy("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + ".txt"))
	{
		fileout.open("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + ".txt", ios::out);
		fileout << CourseID;
		fileout.close();
	}
	else
	{
		fileout.open("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + ".txt", ios::out | ios::app);
		fileout << endl;
		fileout << CourseID;
		fileout.close();
	}
	for (Course* i = a.CreatedCourse; i != NULL; i=i->pnext)
	{
		if (i->Course_Code == CourseID)
		{
			fileout.open(a.SchoolYear + "//" + CourseID + "_" + i->Course_Name + "_" + a.name + ".txt", ios::out | ios::app);
			if (is_emptyy(a.SchoolYear + "//" + CourseID + "_" + i->Course_Name + "_" + a.name + ".txt"))
			{
				fileout << CLASS << "," << name << "," << ID;
				fileout.close();
			}
			else
			{
				fileout << endl;
				fileout << CLASS << "," << name << "," << ID;
				fileout.close();
			}
			Course_Result* tempp = new Course_Result;
			tempStudent* newstu = new tempStudent;
			newstu->Class = CLASS;
			newstu->ID = ID;
			newstu->name = name;
			tempp->Course_Code = CourseID;
			tempp->Course_Name = i->Course_Name;
			tempp->credits = i->credits;
			tempp->CurNumStudent = i->CurNumStudent;
			tempp->Maxstudent = i->Maxstudent;
			tempp->Room = i->Room;
			tempp->Teacher = i->Teacher;
			tempp->Weekday1 = i->Weekday1;
			tempp->Weekday2 = i->Weekday2;
			tempp->shift1 = i->shift1;
			tempp->shift2 = i->shift2;
			if (RegistedCoursee == NULL)
			{
				RegistedCoursee = tempp;
			}
			else
			{
				
				tempp->pnext1 = RegistedCoursee;
				RegistedCoursee = tempp;
			}
			if (i->headStudent == NULL)
			{
				i->headStudent = newstu;
			}
			else
			{
				
				newstu->pnext = i->headStudent;
				i->headStudent = newstu;
			}
			i->CurNumStudent++;
			tempp->CurNumStudent++;
			break;
		}
	}
	NumCourse++;
}
void student::InputRegCoursetoList_file(semester & a)
{
	if (checkFileWithFstream("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + ".txt"))
	{
		ifstream fileinn;
		Course_Result* tempp;
		if (is_emptyy("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + "_Score.txt") == false)
		{
			fileinn.open("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + "_Score.txt", ios::in);
			while (!fileinn.eof())
			{
				tempp = new Course_Result;
				string s;
				getline(fileinn,s,',');
				fileinn >> tempp->midTerm_point; fileinn.seekg(1, 1);
				fileinn >> tempp->endTerm_point; fileinn.seekg(1, 1);
				fileinn >> tempp->other_point; fileinn.seekg(1, 1); fileinn >> tempp->final_grade;
				AverScore += tempp->final_grade;
				fileinn.ignore();
				for (Course* i = a.CreatedCourse; i != NULL; i = i->pnext)
				{
					if (i->Course_Code == s)
					{
						tempp->Course_Code = s;
						tempp->Course_Name = i->Course_Name;
						tempp->credits = i->credits;
						tempp->CurNumStudent = i->CurNumStudent;
						tempp->Maxstudent = i->Maxstudent;
						tempp->Room = i->Room;
						tempp->Teacher = i->Teacher;
						tempp->Weekday1 = i->Weekday1;
						tempp->Weekday2 = i->Weekday2;
						tempp->shift1 = i->shift1;
						tempp->shift2 = i->shift2;
						Sumcredit += i->credits;
						if (RegistedCoursee == NULL)
						{
							RegistedCoursee = tempp;
						}
						else
						{
							tempp->pnext1 = RegistedCoursee;
							RegistedCoursee = tempp;
						}
						NumCourse++;
						break;
					}
				}
			}
			AverScore = AverScore / NumCourse;
		}
		else
		{
			if (is_emptyy("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + ".txt") == false)
			{
				fileinn.open("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + ".txt", ios::in);
				while (!fileinn.eof())
				{
					string s;
					fileinn >> s;
					tempp = new Course_Result;
					for (Course* i = a.CreatedCourse; i != NULL; i = i->pnext)
					{
						if (i->Course_Code == s)
						{
							tempp->Course_Code = s;
							tempp->Course_Name = i->Course_Name;
							tempp->credits = i->credits;
							tempp->CurNumStudent = i->CurNumStudent;
							tempp->Maxstudent = i->Maxstudent;
							tempp->Room = i->Room;
							tempp->Teacher = i->Teacher;
							tempp->Weekday1 = i->Weekday1;
							tempp->Weekday2 = i->Weekday2;
							tempp->shift1 = i->shift1;
							tempp->shift2 = i->shift2;
							if (RegistedCoursee == NULL)
							{
								RegistedCoursee = tempp;
							}
							else
							{
								tempp->pnext1 = RegistedCoursee;
								RegistedCoursee = tempp;
							}
							NumCourse++;
							break;
						}
					}
				}
			}
		}
		fileinn.close();
	}
	else
	{
		ofstream fileout;
		fileout.open("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + ".txt", ios::out);
		fileout.close();
		fileout.open("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + "Score.txt", ios::out);
		fileout.close();
	}
}
void student::register_course(semester &a) {
	int ythanhsang = 8, y = 7, h = 1;
	system("cls");
	while (true)
	{
		BangDangKiLopHoc(35, y, h, 50, ythanhsang);
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 80) {
					if (ythanhsang == y + 2 * (h + 1) + 1) ythanhsang = y + 1;
					else ythanhsang += 2;
				}
				else if (c == 72) {
					if (ythanhsang == y + 1) ythanhsang = y + 2 * (h + 1) + 1;
					else ythanhsang -= 2;
				}
			}
			else if (c == 13) {
				system("cls");
				if (ythanhsang == y + 1) {
					if (a.CheckEndReg == false)
					{
						string answer;
						while (true)
						{
							system("cls");
							view_notregistered_course(a);
							view_registered_course(a);
							ShowCur(1);
							cout << "1. Register Course." << endl;
							cout << "2. Delete Course." << endl;
							cout << "0. Go back." << endl << endl;
							cout << "Your Choice: ";
							cin >> answer;
							if (answer == "1")
							{
								string CourseID;
								cout << "ID of Course you want to register :";
								cin >> CourseID;
								if (CheckCourse(CourseID, a) == false)
								{
									cout << "Enter to continue" << endl;
									system("pause");
									continue;
								}
								InsertRegCoursetoList(CourseID, a);
							}
							else if (answer == "2")
							{
								string CourseID;
								cout << "ID of Course you want to register :";
								cin >> CourseID;
								delete_course(CourseID, a);
							}
							else
							{
								break;
							}
						}
					}
					else
					{
						cout << "The time for registering course is over. Enter to go back" << endl;
						system("pause");
					}
				}
				else if (ythanhsang == y + (h + 1) + 1) {
					if (RegistedCoursee == NULL)
					{
						cout << "You did not regist to any course" << endl;
					}
					else
					{
						cout << "\t\t\t\t(1) 7h30   (2) 9h30   (3) 13h30   (4) 15h30" << endl << endl;
						view_registered_course(a);
					}
					system("pause");
				}
				else {
					break;
				}
				system("cls");
			}
		}
		ShowCur(0);
	}
}
void student::courses_infomation(fstream course_registered) {
}
void student::delete_course(string &CourseID,semester &a) {
	Course_Result* pCur = RegistedCoursee;
	for (Course_Result* i = RegistedCoursee; i != NULL; i=i->pnext1)
	{
		if (i->Course_Code == CourseID)
		{
			if (i == RegistedCoursee)
			{
				RegistedCoursee = RegistedCoursee->pnext1;
				delete i;
			}
			else
			{
				pCur->pnext1 = i->pnext1;
				delete i;
			}
			ofstream fileout;
			fileout.open("sinhvien//" + ID + "//" + a.SchoolYear + "_" + a.name + ".txt", ios::out);
			for (Course_Result* j = RegistedCoursee; j != NULL; j=j->pnext1)
			{
				if (j->pnext1 != NULL)
				{
					fileout << j->Course_Code << endl;
				}
				else
				{
					fileout << j->Course_Code;
				}
			}
			fileout.close();
			for (Course* k = a.CreatedCourse; k != NULL; k=k->pnext)
			{
				if (k->Course_Code == CourseID)
				{
					fileout.open(a.SchoolYear + "//" + k->Course_Code + "_" + k->Course_Name + "_" + a.name + ".txt", ios::out);
					tempStudent* pCur = k->headStudent;
					tempStudent* n = k->headStudent;
					while(n!=NULL)
					{
						if (n->ID == ID)
						{
							if (n == k->headStudent)
							{
								k->headStudent = k->headStudent->pnext;
								delete n;
								n = k->headStudent;
							}
							else
							{
								pCur->pnext = n->pnext;
								delete n;
								n = pCur->pnext;
							}
						}
						else
						{
							if (n->pnext != NULL)
							{
								fileout << n->Class << "," << n->name << "," << n->ID << endl;
							}
							else
							{
								fileout << n->Class << "," << n->name << "," << n->ID;
							}
							pCur = n;
							n = n->pnext;
						}
					}
					k->CurNumStudent--;
					break;
				}
			}
			NumCourse--;
			break;
		}
		pCur = i;
	}
}
void student::view_registered_course(semester &a) {
	cout << endl << endl;
	cout << "\t\t\t\t\tCourse you registered" << endl << endl;
	cout << setw(11) << left << "  ID";
	cout << setw(14) << left << "Course_name";		// độ rộng 5 ký tự, canh trái ID
	cout << setw(9) << left << "Credit";	// độ rộng 30 ký tự, canh trái Name
	cout << setw(6) << left << "Max";	// độ rộng 20 ký tự, canh phải Address
	cout << setw(12) << left << "Session 1";
	cout << setw(12) << left << "Session 2";
	cout << setw(27) << left << "Teacher";
	cout << setw(7) << left << "Room";
	cout << setw(6) << left << "Current student" << endl;
	cout << setfill('-');		// set fill bằng ký tự '-' thay vì ' '
	cout << setw(115) << "-" << endl;	// fill 55 ký tự '-'
	cout << setfill(' ');
		for (Course_Result* j = RegistedCoursee; j != NULL; j = j->pnext1)
		{
				cout << setw(11) << left << j->Course_Code;
				cout << setw(14) << left << j->Course_Name;		// độ rộng 5 ký tự, canh trái ID
				cout << setw(9) << left << j->credits;	// độ rộng 30 ký tự, canh trái Name
				cout << setw(6) << left << j->Maxstudent;	// độ rộng 20 ký tự, canh phải Address
				cout << setw(12) << left << j->Weekday1 + " (" + to_string(j->shift1) + ")";
				cout << setw(12) << left << j->Weekday2 + " (" + to_string(j->shift2) + ")";
				cout << setw(27) << left << j->Teacher;
				cout << setw(10) << left << j->Room;
				cout << setw(6) << left << j->CurNumStudent << endl;
		}
	cout << endl << endl;
}
void student::view_notregistered_course(semester& a)
{
	cout << "\t\t\t\t(1) 7h30   (2) 9h30   (3) 13h30   (4) 15h30" << endl << endl;
	cout << "\t\t\t\t\tCourse you did not register" << endl << endl;
	cout << setw(11) << left << "  ID";
	cout << setw(14) << left << "Course_name";		// độ rộng 5 ký tự, canh trái ID
	cout << setw(9) << left << "Credit";	// độ rộng 30 ký tự, canh trái Name
	cout << setw(6) << left << "Max";	// độ rộng 20 ký tự, canh phải Address
	cout << setw(12) << left << "Session 1";
	cout << setw(12) << left << "Session 2";
	cout << setw(27) << left << "Teacher";
	cout << setw(7) << left << "Room";
	cout << setw(6) << left << "Current student" << endl;
	cout << setfill('-');		// set fill bằng ký tự '-' thay vì ' '
	cout << setw(115) << "-" << endl;	// fill 55 ký tự '-'
	cout << setfill(' ');
	bool check;
	for (Course* j = a.CreatedCourse; j != NULL; j = j->pnext)
	{
		check = true;
		for (Course_Result* i = RegistedCoursee; i != NULL; i = i->pnext1)
		{
			if (i->Course_Code == j->Course_Code)
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			cout << setw(11) << left << j->Course_Code;
			cout << setw(14) << left << j->Course_Name;		// độ rộng 5 ký tự, canh trái ID
			cout << setw(9) << left << j->credits;	// độ rộng 30 ký tự, canh trái Name
			cout << setw(6) << left << j->Maxstudent;	// độ rộng 20 ký tự, canh phải Address
			cout << setw(12) << left << j->Weekday1 + " (" + to_string(j->shift1) + ")";
			cout << setw(12) << left << j->Weekday2 + " (" + to_string(j->shift2) + ")";
			cout << setw(27) << left << j->Teacher;
			cout << setw(10) << left << j->Room;
			cout << setw(6) << left << j->CurNumStudent << endl;
		}
	}
}
void student::view_course_member(fstream course_registered) {
}
void student::View_Score(semester &a)
{
	short b = 1;
	cout << "\t\t\t\t\t\t" << a.SchoolYear << endl;
	cout << "\t\t\t\t\t\t" << a.name << endl << endl;
	cout << setw(6) << left << "No";
	cout << setw(11) << left << "ID";		// độ rộng 5 ký tự, canh trái ID
	cout << setw(17) << left << "Course's name";
	cout << setw(10) << left << "Credit";	// độ rộng 30 ký tự, canh trái Name
	cout << setw(17) << left << "Midterm Mark";	// độ rộng 20 ký tự, canh phải Address
	cout << setw(16) << left << "Final Mark";
	cout << setw(16) << left << "Other Mark";
	cout << setw(14) << left << "Total Mark" << endl;
	cout << setfill('-');		// set fill bằng ký tự '-' thay vì ' '
	cout << setw(115) << "-" << endl;	// fill 55 ký tự '-'
	cout << setfill(' ');
	for (Course_Result* i = RegistedCoursee; i != NULL; i=i->pnext1)
	{
		cout << setw(6) << left << b++;
		cout << setw(11) << left << i->Course_Code;
		cout << setw(20) << left << i->Course_Name;
		cout << setw(11) << left << i->credits;
		cout << setw(17) << left << i->midTerm_point;
		cout << setw(16) << left << i->endTerm_point;
		cout << setw(16) << left << i->other_point;
		cout << setw(14) << left << i->final_grade << endl;
	}
	cout << endl;
	cout << "Average score of semester: " << AverScore << endl;
	cout << "Sum of creadit: " << Sumcredit << endl;
	cout << "Number of course: " << NumCourse << endl;
}
student::~student()
{
	Course_Result* tempp;
	while (RegistedCoursee != NULL)
	{
		tempp = RegistedCoursee;
		RegistedCoursee = RegistedCoursee->pnext1;
		delete tempp;
	}
	int NumCourse = 0;
}
//
void staff::savefile(string path)
{
	ofstream fileout;
	fileout.open(path, ios::out);
	fileout << password << endl;
	fileout << name << "," << ID << "," << gender << "," << birth << "," << socialID << "," << phone << "," << address;
	fileout.close();
}
void staff::create_schoolyear(Something*& headYear, const date& currentday)
{
	if (currentday.day == 1 && currentday.month == 9)
	{
		string year;
		bool check = true;
		while(true)
		{
			cout << "School year (ex: 2021-2022): ";
			cin >> year;
			if (checkyear(year))
			{
				break;
			}
			else
			{
				cout << "Wrong format. Try again!" << endl;
			}
		}
		PushArrangeCreatedYear(headYear, year);
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
		OutputCreatedYear_File(headYear);
	}
	else
	{
		cout << "Wait until 1/9 to do this." << endl;
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
	tempStudent a; string b, c;
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
		getline(filein, a.ID, ',');
		getline(filein, a.name, ',');
		getline(filein, b, ',');
		getline(filein, c);
		cout << setw(6) << left << i + 1;
		cout << setw(10) << left << a.ID;
		cout << setw(30) << left << a.name;
		cout << setw(20) << left << b;
		cout << setw(11) << left << c << endl;
		i++;
	}
	filein.close();
}
void staff::create_class(Something*& headYear)
{
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
					string year;
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
						fstream filein1;
						fstream filein2;
						string lop;
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
				}
				else if (ythanhsang == y + 2 * (h + 1) + 1)
				{
					if (headYear == NULL)
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
							OutputList(headYear);
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
		currentsemester.DeleteListCourse();
		fileout.open("curday.txt", ios::out);
		fileout << currentday.day << "," << currentday.month;
		fileout.close();
		system("pause");
	}
	else
	{
		cout << "Wait until 1/9 or 1/1 or 1/5 to do this" << endl;
			system("pause");
	}
}
void staff::create_course(semester &a) {
	Course *tempppp;
	string answer;
	if (a.name != "0")
	{
			int y = 8, h = 1;
			int ythanhsang = y + 1;
			while (true) {
				ShowCur(0);
				CourseMenu(35, 8, 1, 50, ythanhsang);
				if (_kbhit()) {
					char c = _getch();
					if (c == -32) {
						c = _getch();
						if (c == 80) {
							if (ythanhsang == y + 4 * (h + 1) + 1) ythanhsang = y + 1;
							else ythanhsang += 2;
						}
						else if (c == 72) {
							if (ythanhsang == y + 1) ythanhsang = y + 4 * (h + 1) + 1;
							else ythanhsang -= 2;
						}
					}
					else if (c == 13) {
						system("cls");
						if (ythanhsang == y + 1) {
							ShowCur(1);
							while (true)
							{
								system("cls");
								a.BangDanhSachCourse();
								cout << endl << endl;
								cout << "1. Create Course." << endl;
								cout << "0. Go Back." << endl << endl;
								cout << "Your choice: ";
								cin >> answer;
								if (answer == "1")
								{
									tempppp = new Course;
									cout << "Name of Course: "; cin.ignore(); getline(cin, tempppp->Course_Name);
									cout << "ID Course: "; getline(cin, tempppp->Course_Code);
									cout << "Credit: "; cin >> tempppp->credits;
									cout << "Max student in the course: "; cin >> tempppp->Maxstudent;
									cout << "Weekday of session 1 (Mon/Tue/Wed/Thu/Fri/Sat) : "; cin >> tempppp->Weekday1;
									cout << "Shift of session 1: "; cin >> tempppp->shift1;
									cout << "Weekday of session 2 (Mon/Tue/Wed/Thu/Fri/Sat) : "; cin >> tempppp->Weekday2;
									cout << "Shift of session 2: "; cin >> tempppp->shift2;
									cout << "Room : "; cin >> tempppp->Room;
									cout << "Name of Teacher: ";
									cin.ignore();
									getline(cin, tempppp->Teacher);
									a.InsertCourse(tempppp);
								}
								else
								{
									system("cls");
									break;
								}
							}
						}
						else if (ythanhsang == y + 1 * (h + 1) + 1) {
							system("cls");
							ShowCur(1);
							while (true)
							{
								system("cls");
								a.BangDanhSachCourse();
								cout << endl << endl;
								cout << "1. View list student in the course. " << endl;
								cout << "0. Go back." << endl;
								cout << "Your choice: ";
								cin >> answer;
								if (answer == "1")
								{
									string courseName, courseID;
									cin.ignore();
									cout << "Enter course ID: ";
									getline(cin, courseID);
									cout << "Enter course name: ";
									getline(cin, courseName);
									Course* courseCheck = nullptr;
									for (courseCheck = a.CreatedCourse; courseCheck != nullptr; courseCheck = courseCheck->pnext)
									{
										if (courseCheck->Course_Code == courseID && courseCheck->Course_Name == courseName)
										{
											system("cls");
											cout << courseCheck->Course_Code << " - " << courseCheck->Course_Name << " - " << courseCheck->Teacher << endl << endl;
											cout << "Current Student Number: " << courseCheck->CurNumStudent << endl;
											if (courseCheck->CurNumStudent > 0)
											{
												cout << setfill('_');
												cout << setw(71) << "_" << endl;
												cout << setfill(' ');
												cout << setw(10) << left << "|No";
												cout << setw(10) << left << "|ID";
												cout << setw(30) << left << "|Name";
												cout << setw(20) << left << "|Class";
												cout << setw(1) << "|" << endl;
												cout << setw(1) << "|";
												cout << setfill('-');
												cout << setw(9) << "-";
												cout << setw(1) << "|";
												cout << setw(9) << "-";
												cout << setw(1) << "|";
												cout << setw(29) << "-";
												cout << setw(1) << "|";
												cout << setw(19) << "-";
												cout << setw(1) << "|" << endl;
												cout << setfill(' ');
												int i = 0;
												for (tempStudent* stu = courseCheck->headStudent; stu != nullptr; stu = stu->pnext)
												{
													i++;
													cout << "|" << setw(9) << left << i;
													cout << "|" << setw(9) << left << stu->ID;
													cout << "|" << setw(29) << left << stu->name;
													cout << "|" << setw(19) << left << stu->Class;
													cout << setw(1) << left << "|" << endl;
												}
												cout << setw(1) << "|";
												cout << setfill('_');
												cout << setw(9) << "_";
												cout << setw(1) << "|";
												cout << setw(9) << "_";
												cout << setw(1) << "|";
												cout << setw(29) << "_";
												cout << setw(1) << "|";
												cout << setw(19) << "_";
												cout << setw(1) << "|" << endl << endl;
												cout << setfill(' ');
											}
											else
												cout << "There is no student in this course" << endl << endl;
											system("pause");
											break;
										}
									}
									if (courseCheck == nullptr)
									{
										cout << "No course has name or ID like that" << endl;
										system("pause");
									}
								}
								else
								{
									system("cls");
									break;
								}
							}
							system("cls");
						}
						else if (ythanhsang == y + 2 * (h + 1) + 1) {
							delete_course(a);
						}
						else if (ythanhsang == y + 3 * (h + 1) + 1) {
							adjust_Courses(a);
						}
						else if (ythanhsang == y + 4 * (h + 1) + 1) {
							break;
						}
					}
				}
			}
	}
	else
	{
		cout << "You did not create a current semester so you can't do this right now." << endl;
		system("pause");
	}
}
void staff::adjust_Courses(semester &a) {
	string answer;
	while (true)
	{
		ShowCur(1);
		system("cls");
		a.BangDanhSachCourse();
		cout << endl << endl;
		cout << "1. Change information of course." << endl;
		cout << "0. Go Back." << endl << endl;
		cout << "Your choice: ";
		cin >> answer;
		if (answer == "1")
		{
			string Course_name, Course_code; bool check = true;
			while (check)
			{
				cout << "Name of course (Current name of that course) : "; cin.ignore(); getline(cin, Course_name);
				cout << "ID of course (Current ID of that course): "; cin >> Course_code;
				for (Course* i = a.CreatedCourse; i != NULL; i = i->pnext)
				{
					if (i->Course_Name == Course_name && i->Course_Code == Course_code)
					{
						string tempname=i->Course_Name, tempid= i->Course_Code;
						cout << "\t Update information" << endl;
						cout << "Name of Course: "; cin.ignore(); getline(cin, i->Course_Name);
						cout << "ID Course: "; getline(cin, i->Course_Code);
						cout << "Credit: "; cin >> i->credits;
						cout << "Max student in the course: "; cin >> i->Maxstudent;
						cout << "Weekday of session 1 (Mon/Tue/Wed/Thu/Fri/Sat) : "; cin >> i->Weekday1;
						cout << "Shift of session 1: "; cin >> i->shift1;
						cout << "Weekday of session 2 (Mon/Tue/Wed/Thu/Fri/Sat) : "; cin >> i->Weekday2;
						cout << "Shift of session 2: "; cin >> i->shift2;
						cout << "Room : "; cin >> i->Room;
						cout << "Name of Teacher: ";
						cin.ignore();
						getline(cin, i->Teacher);
						if (tempname != i->Course_Name || tempid != i->Course_Code)
						{
							string oldname = a.SchoolYear + "//" + tempid +"_" +tempname + "_" + a.name+".txt";
							string newname = a.SchoolYear + "//" + i->Course_Code + "_" + i->Course_Name + "_" + a.name + ".txt";
							rename(oldname.c_str(), newname.c_str());
						}
						a.Ouput_file();
						check = false;
						break;
					}
				}
				if (check)
				{
					cout << "There is not this course. Try again !" << endl;
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
void staff::delete_course(semester& a) {
	string answer;
		while (true)
		{
			ShowCur(1);
			system("cls");
			a.BangDanhSachCourse();
			cout << endl << endl;
			cout << "1. Remove course." << endl;
			cout << "0. Go Back." << endl << endl;
			cout << "Your choice: ";
			cin >> answer;
			if (answer == "1")
			{
				bool check = true;
				string Course_name, Course_code;
				do
				{
					cout << "Name of course: "; cin.ignore(); getline(cin, Course_name);
					cout << "ID of course: "; cin >> Course_code;
					if (a.DeleteCourse(Course_code, Course_name) == false)
					{
						cout << "There is not this course. Try again." << endl;
						check = false;
					}
					else
					{
						check = true;
					}
				} while ( Course_name != "0" && Course_code != "0" && check == false);

			}
			else
			{
				system("cls");
				break;
			}
		}
}
void staff::Score(semester& a)
{
	int y = 8, h = 1;
	int ythanhsang = y + 1;
	while (true) {
		ShowCur(0);
		ScoreMenuStaff(35, 8, 1, 50, ythanhsang);
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 80) {
					if (ythanhsang == y + 4 * (h + 1) + 1) ythanhsang = y + 1;
					else ythanhsang += 2;
				}
				else if (c == 72) {
					if (ythanhsang == y + 1) ythanhsang = y + 4 * (h + 1) + 1;
					else ythanhsang -= 2;
				}
			}
			else if (c == 13) {
				system("cls");
				if (ythanhsang == y + 1)
				{
					system("cls");
					create_FileScoreboard(a);
					cout << "Complete ! Enter to comback." << endl;
					system("pause");
				}
				else if (ythanhsang == y + 1 * (h + 1) + 1)
				{
					system("cls");
					update_ScoreStudent(a);
					cout << "Complete ! Enter to comback." << endl;
					system("pause");
				}
				else if (ythanhsang == y + 2 * (h + 1) + 1) {

				}
				else if (ythanhsang == y + 3 * (h + 1) + 1) {
					ShowCur(1);
					string answer;
					while (true)
					{
						system("cls");
						a.BangDanhSachCourse();
						cout << endl << endl;
						cout << "1. View score course. " << endl;
						cout << "0. Go back." << endl;
						cout << "Your choice: ";
						cin >> answer;
						if (answer == "1")
						{
							string courseName, courseID;
							cin.ignore();
							cout << "Enter course ID: ";
							getline(cin, courseID);
							view_ScoreCourse(courseID, a);
							system("pause");
						}
						else
						{
							break;
						}
					}
				}
				else if (ythanhsang == y + 4 * (h + 1) + 1) {
					break;
				}
				system("cls");
			}
		}
	}
}
void staff::create_FileScoreboard(semester& a)
{
	ofstream fileout;
	short j;
	for (Course* i = a.CreatedCourse; i != NULL; i = i->pnext)
	{
		j = 1;
		fileout.open(i->Course_Code + "_" + a.SchoolYear + "_" + a.name + "_Score.txt", ios::out);
		fileout << "No, Student ID, Student Full Name, Midterm Mark, Final Mark, Other Mark, Total Mark" << endl;
		for (tempStudent* k = i->headStudent; k != NULL; k = k->pnext)
		{
			if (k->pnext != NULL)
			{
				fileout << j << "," << k->ID << "," << k->name << endl;
			}
			else
			{
				fileout << j << "," << k->ID << "," << k->name;
			}
			j++;
		}
		fileout.close();
	}
}
void staff::view_ScoreCourse(string& CourseID, semester& a)
{
	ifstream filein;
	tempStudent b; float no, m, n, p, q;
	if (checkFileWithFstream(CourseID + "_" + a.SchoolYear + "_" + a.name + "_Score.txt"))
	{
		filein.open(CourseID + "_" + a.SchoolYear + "_" + a.name + "_Score.txt", ios::in);
		string s; getline(filein, s);
		cout << setw(6) << left << "No";
		cout << setw(11) << left << "ID";		// độ rộng 5 ký tự, canh trái ID
		cout << setw(30) << left << "Full Name";	// độ rộng 30 ký tự, canh trái Name
		cout << setw(17) << left << "Midterm Mark";	// độ rộng 20 ký tự, canh phải Address
		cout << setw(16) << left << "Final Mark";
		cout << setw(16) << left << "Other Mark";
		cout << setw(14) << left << "Total Mark" << endl;
		cout << setfill('-');		// set fill bằng ký tự '-' thay vì ' '
		cout << setw(115) << "-" << endl;	// fill 55 ký tự '-'
		cout << setfill(' ');
		while (!filein.eof())
		{
			filein >> no; filein.seekg(1, 1);
			getline(filein, b.ID, ',');
			getline(filein, b.name, ',');
			filein >> m; filein.seekg(1, 1);
			filein >> n; filein.seekg(1, 1);
			filein >> p; filein.seekg(1, 1);
			filein >> q;
			cout << setw(6) << left << no;
			cout << setw(11) << left << b.ID;
			cout << setw(34) << left << b.name;
			cout << setw(17) << left << m;
			cout << setw(16) << left << n;
			cout << setw(16) << left << p;
			cout << setw(14) << left << q << endl;
		}
		filein.close();
	}
	else
	{
		cout << "The teacher hasn't score." << endl;
	}
}
void staff::update_ScoreStudent(semester& a)
{
	ifstream filein1; string tempp; short no, m, n, p, q; tempStudent b; ofstream fileout1;
	for (Course* i = a.CreatedCourse; i != NULL; i=i->pnext)
	{
		filein1.open(i->Course_Code + "_" + a.SchoolYear + "_" + a.name + "_Score.txt", ios::in);
		getline(filein1, tempp);
		while (!filein1.eof())
		{
			filein1 >> no;
			filein1.seekg(1, 1);
			getline(filein1, b.ID, ',');
			getline(filein1, b.name, ',');
			filein1 >> m;
			filein1.seekg(1, 1);
			filein1 >> n;
			filein1.seekg(1, 1);
			filein1 >> p;
			filein1.seekg(1, 1);
			filein1 >> q;
			fileout1.open("sinhvien//" + b.ID + "//" + a.SchoolYear + "_" + a.name + "_Score.txt", ios::out | ios::app);
			if (is_emptyy("sinhvien//" + b.ID + "//" + a.SchoolYear + "_" + a.name + "_Score.txt"))
			{
				fileout1 << i->Course_Code << "," << m << "," << n << "," << p << "," << q;
				fileout1.close();
			}
			else
			{
				fileout1 << endl;
				fileout1 << i->Course_Code << "," << m << "," << n << "," << p << "," << q;
				fileout1.close();
			}
		}
		filein1.close();
	}

}
void staff::read_studentList() {
}
void staff::output_Course_Student() {
}
void staff::adjust_StudentGrades() {
}
void staff::read_ClassGrades() {
}
