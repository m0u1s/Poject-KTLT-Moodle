#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
class Course_Result : public Course
{
public:
	float midTerm_point;
	float endTerm_point;
	float final_grade;
};
class person
{
private:
	string ID;
	string password;
	string name;
	string gender;
	string birth;
	string socialID;
	string address;
	string phone;

public:
	void input();
	void input_file();
	void output();
	void edit_profile();
};
void person::input()
{
}
void person::input_file()
{
}
void person::output()
{
}
void person::edit_profile()
{
}
class student : public person
{
public:
	void class_list(fstream class_list);
	void register_course(fstream course_list, fstream &course_registered);
	void courses_infomation(fstream course_registered);
	void delete_course(fstream &course_registered);
	void view_registered_course(fstream course_registered);
	void view_course_member(fstream course_registered);

private:
	void view_results(fstream result_list); // b/c 1 student only see his/her results other can't
};
void student::class_list(fstream class_list)
{

	// view class list by output to the screen the info in the "class_list.txt"
}
void student::register_course(fstream course_list, fstream &course_registered)
{
	// Must have course list for student know which course to regis maybe use a "course_list.txt"
	// Must have a list of registered course so student can not regis it again in same semester
}
void student::courses_infomation(fstream course_registered)
{
	// Must have a list of registered course so student can see courses that registered
}
void student::delete_course(fstream &course_registered)
{
	// Must have a list of registered course so student so there can delete
}

void student::view_results(fstream result_list)
{
	// result list is the list that academic staff or teacher will bring
}
class staff : public person
{
public:
	// When a semester start
	// idea for a semester that we have a file name 2021-2022 then inside we have classes,...
	void create_schoolyear(fstream &schoolyear);
	void add_student(student x, fstream &classes);
	void create_class(fstream &Class);
	void create_course(Course course, fstream &Course);
	void create_semester(semester x, fstream &semester);
	void adjust_Courses(fstream &Course);
	void delete_course();
	// End of regis time
	void read_Classlist();
	void read_studentList();
	// End of semester
	void output_Course_Student();
	void adjust_StudentGrades();
	void read_ClassGrades();
};
void staff::create_schoolyear(fstream &schoolyear)
{
}
void staff::add_student(student x, fstream &classes)
{
}
void staff::create_class(fstream &Class)
{
}
void staff::create_course(Course course, fstream &Course)
{
}
void staff::create_semester(semester x, fstream &semester)
{
}
void staff::adjust_Courses(fstream &Course)
{
}
void staff::read_studentList()
{
}
void staff::read_Classlist()
{
}
void staff::output_Course_Student()
{
}
void staff::adjust_StudentGrades()
{
}
void staff::read_ClassGrades()
{
}

int main()
{

	return 0;
}