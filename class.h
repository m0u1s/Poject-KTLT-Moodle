#pragma once
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
struct Something
{
	string a;
	Something* pnext;
	Something* prev;
};
struct YearCreated {
	string year;
	YearCreated* pnext;
	YearCreated* ppre;
};
struct date
{
	short day, month;
};
class tempStudent
{
public:
	string name;
	string ID;
	string Class;
	tempStudent* pnext = NULL;
};
class Course
{
public:
	string Course_Code;
	string Course_Name;
	short credits;
	short Maxstudent = 50;
	string Weekday1;
	short shift1;
	string Weekday2;
	short shift2;
	string Teacher;
	short CurNumStudent = 0;
	string Room;
	tempStudent* headStudent = NULL;// danh sách liên kết student trong course;
	Course* pnext = NULL; // liên kết với phần tử course tiếp theo
};
class Course_Result : public Course
{
public:
	float midTerm_point;
	float endTerm_point;
	float other_point;
	float final_grade;
	Course_Result* pnext1 = NULL;
};
class semester {
public:
	string SchoolYear = "0";
	string name = "0";
	date start;
	date end;
	date StartRegCourse;
	date EndRegCourse;
	bool CheckEndReg = false;
	bool checkEndSemester = false;
	Course* CreatedCourse = NULL;
	void checkendreg(const date& cur);
	void checkendsemester(const date& cur);
	void PushTailCourse(Course*& a);
	void PushTailStudent(Course*& a, tempStudent*& b);
	void filein_Cur(date& currentday);
	void Ouput_file();
	bool DeleteCourse(string Course_code, string Course_Name);
	void InsertCourse(Course*& a);
	void BangDanhSachCourse();
	void DeleteListCourse();
	~semester();
};
class person {
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
	void input_file(string path);
	void input();
	void output();
	void View_Class(string classname);
};
class student : public person {
private:
	string CLASS; short Sumcredit = 0; float AverScore = 0;
public:
	int NumCourse = 0;
	Course_Result* RegistedCoursee = NULL;
	bool CheckCourse(string CourseID, semester& a);
	void InputRegCoursetoList_file(semester& a);
	void savefile(string path);
	string getclass();
	void input();
	void input_file(string path);
	void output();
	void register_course(semester& a);
	void delete_course(string& CourseID, semester& a);
	void view_registered_course(semester& a);
	void view_notregistered_course(semester& a);
	void InsertRegCoursetoList(string& CourseID, semester& a);
	void View_Score(semester& a);
	void Edit_Profile();
	~student();
};
class staff : public person {
public:
	void savefile(string path);
	void create_schoolyear(YearCreated*& headYear, const date& currentday);
	void add_student();
	void create_class(YearCreated*& head);
	void create_course(semester& a);
	void create_semester(semester& currentsemester, date& currentday);
	void adjust_Courses(semester& a);
	void delete_course(semester& a);
	void Score(semester& a, const date& currentday);
	void create_FileScoreboard(semester& a);
	void view_ScoreCourse(semester& a);
	void update_ScoreStudent(semester& a);
	void view_ScoreClass(semester& a);
	void Edit_Profile();
};
