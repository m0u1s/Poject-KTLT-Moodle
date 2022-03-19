﻿//C++ library
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
//struct
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
struct tempStudent
{
	string name;
	string ID;
	string Class;
	tempStudent* pnext = NULL;
};
struct Course
{
	string Course_Code;
	string Course_Name;
	short credits;
	short Maxstudent = 50;
	string Weekday1;
	short shift1;
	string Weekday2;
	short shift2;
	string Teacher;
	tempStudent* headStudent = NULL;// danh sách liên kết student trong course;
	Course* pnext = NULL; // liên kết với phần tử course tiếp theo
};
//class
class semester {
public:
	string SchoolYear = "0";
	string name = "0";
	date start;
	date end;
	date StartRegCourse;
	date EndRegCourse;
	bool CheckEndReg = false;
	Course* CreatedCourse = NULL;// danh sach liên kết các Course đã tạo;
	void filein_Cur(date& currentday);
	void PushTailCourse(Course*& a);// tham số là một course đã sao chép đầy đủ thông tin, các hs trong course từ file txt bây giờ thêm vào cuối danh sách liên kết CreatedCourse
	void DeleteCourse(short Course_code, short Course_Name);// Xóa course,tham số truyền vào là id course, tên course cần xóa
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
	void edit_profile();
};
class student : public person {
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
	void register_course(fstream& course_list, fstream& course_registered);
	void courses_infomation(fstream course_registered);
	void delete_course(fstream& course_registered);
	void view_registered_course(fstream course_registered);
	void view_course_member(fstream course_registered);

private:
	void view_results(fstream result_list); // b/c 1 student only see his/her results other can't
};
class staff : public person {
public:
	void savefile(string path);

	// When a semester start
	// idea for a semester that we have a file name 2021-2022 then inside we have classes,...
	void create_schoolyear(YearCreated*& head, const date& currentday);
	void add_student();
	void View_Class(string classname);
	void create_class(YearCreated*& head);
	void create_course();
	void create_semester(semester& currentsemester, date& currentday);
	void adjust_Courses(fstream Course);
	void delete_course();
	// End of regis time
	/*void read_Classlist();*/
	void read_studentList();
	// End of semester
	void output_Course_Student();
	void adjust_StudentGrades();
	void read_ClassGrades();
};