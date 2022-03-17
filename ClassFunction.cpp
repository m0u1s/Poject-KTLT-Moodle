#include "MainFunction.h"
//Hàm mô đẹp trai để test
void MoDepTrai() {
	cout << "Mo dep trai\n";
	system("pause");
	system("cls");
}
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
//person::method
string person::getpassword() {
	return password;
}
string person::getID()
{
	return ID;
}
string person::getname()
{
	return name;
}
string person::getgender()
{
	return gender;
}
string person::getbirth()
{
	return birth;
}
void person::changepassword(string newpassword)
{
	password = newpassword;
}
void person::input()
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
void person::input_file(string path)
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
void person::output()
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
void person::edit_profile() {
	cout << "Mo dep trai";
}
//student::method
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
void student::input()
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
	cout << "Mo dep trai";
}
void student::output(){
	gotoxy(45, 3); cout << "Class : " << CLASS;
	person::output();
}
void student::View_Class(string classname)
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
void student::register_course(fstream course_list, fstream& course_registered) {
	cout << "Mo dep trai";
}
void student::courses_infomation(fstream course_registered) {
	cout << "Mo dep trai";
}
void student::delete_course(fstream& course_registered) {
	cout << "Mo dep trai";
}
void student::view_registered_course(fstream course_registered) {
	cout << "Mo dep trai";
}
void student::view_course_member(fstream course_registered) {
	cout << "Mo dep trai";
}
void student::view_results(fstream result_list) {
	cout << "Mo dep trai";
}
//staff::method
void staff::create_schoolyear(YearCreated*& head) {
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
void staff::add_student()
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
void staff::savefile(string path) {
	ofstream fileout;
	fileout.open(path, ios::out);
	fileout << password << endl;
	fileout << name << "," << ID << "," << gender << "," << birth << "," << socialID << "," << phone << "," << address;
	fileout.close();
}
void staff::create_class(YearCreated*& head) {
	int x = 35, y = 5, h = 1, w = 50, ythanhsang = 6;
	while (true) {
		BangTaoLop(x, y, h, w, ythanhsang);
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
				if (ythanhsang == y + 1) MoDepTrai();
				else if (ythanhsang == y + (h + 1) + 1) {
					system("cls");
					cout << "Mo Ngu\n";
					system("pause");
					system("cls");
				}
				else if (ythanhsang == y + 2 * (h + 1) + 1) MoDepTrai();
				else if (ythanhsang == y + 3 * (h + 1) + 1) break;
			}
		}
		ShowCur(0);
	}
}

