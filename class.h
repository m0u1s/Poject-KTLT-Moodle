//C++ library
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
//function needed
bool FolderExists(const CString& strFolderName);
void textcolor(int x);
void gotoxy(int x, int y);
void Setcolor(int backgound_color, int text_color);
BOOL WINAPI SetConsoleTitle(
	_In_ LPCTSTR lpConsoleTitle
);
void ShowCur(bool CursorVisibility);
void resizeConsole(int width, int height);
bool is_emptyy(string s);
//
struct YearCreated {
	string year;
	YearCreated* pnext;
	YearCreated* ppre;
};
struct Something
{
	string a;
	Something* pnext;
	Something* prev;
};
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
	string getpassword();
	string getID();
	string getname();
	string getgender();
	string getbirth();
	void changepassword(string newpassword);
	void input();
	void input_file(string path);
	void output();
	void edit_profile();
};
class student : public person
{
private:
	string CLASS;
public:
	void savefile(string path);
	string getclass();
	void input();
	void input_file(string path);
	void input_file2(ifstream& filein);
	void output();
	/*void class_list(fstream class_list);*/
	void View_Class(string classname);
	void register_course(fstream course_list, fstream& course_registered);
	void courses_infomation(fstream course_registered);
	void delete_course(fstream& course_registered);
	void view_registered_course(fstream course_registered);
	void view_course_member(fstream course_registered);

private:
	void view_results(fstream result_list); // b/c 1 student only see his/her results other can't
};
class staff : public person
{
public:
	void savefile(string path);
	void create_schoolyear(YearCreated*& head);
	// When a semester start
	// idea for a semester that we have a file name 2021-2022 then inside we have classes,...
	void add_student();
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
	void create_class(YearCreated*& head);
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