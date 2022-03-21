#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
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
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
class Course_Result : public Course
{
public:
	float midTerm_point;
	float endTerm_point;
	float final_grade;
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
	void input();
	void input_file(string path);
	void output();
	void edit_profile();

	string GetPassword();
	string GetID();
	string GetName();
	string GetGender();
	string GetBirth();
	void ChangePassword(string NewPassword);
};
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
    //Setcolor(7, 0);
    gotoxy(45, 21); cout << "ESC TO GO BACK. ";
    //Setcolor(0, 7);

}
void person::edit_profile()
{
}

string person::GetPassword()
{
    return password;
}
string person::GetID()
{
    return ID;
}
string person::GetName()
{
    return name;
}
string person::GetGender()
{
    return gender;
}
string person::GetBirth()
{
    return birth;
}
void person::ChangePassword(string NewPassword)
{
    password = NewPassword;
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
	void SaveFile(string path);
	string GetClass();
	void Input();
    void Input_File(string path);
    void Input_File2(ifstream &filein);
    void Output();

private:
	void view_results(fstream result_list); // b/c 1 student only see his/her results other can't
	string CLASS;
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
void student::SaveFile(string path)
{
    ofstream fileout;
    fileout.open(path, ios::out);
    fileout << password << endl;
    fileout <<CLASS<<","<< name << "," << ID << "," << gender << "," <<  birth << "," << socialID << "," << phone << "," << address;
    fileout.close();
}
string student::GetClass()
{
    return CLASS;
}
void student::Input()
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
void student::Input_File(string path)
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
void student::Input_File2(ifstream &filein)
{

}
void student::Output()
{
    gotoxy(45, 3); cout << "Class : " << CLASS;
    person::output();
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
	//
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
bool CheckYear(string Year)
{
    if (Year.length() != 9) return false;
    int first = 0, second = 0;
    int vt = 0;
    while (vt < Year.length() && Year[vt] != '-')
    {
        first = first * 10 + Year[vt] - '0';
        vt++;
    }
    vt++;
    while (vt < Year.legnth())
    {
        second = second * 10 + Year[vt] - '0';
        vt++;
    }
    if (second - first == 1) return true;
    return false;
}
bool CheckClass(string Class)
{
    if (Class.length() != 7) return false;
    if (Class[0] < 48 || Class[0] > 57 || Class[1] < 48 || Class[1] > 57)
        return false;
    int year = 0, vt = 0;
    while (vt < 2)
    {
        year = Class[vt] - '0' + year * 10;
        vt++;
    }
    string pr = "";
    while (vt < 5)
    {
        pr = pr + Class[vt];
        vt++;
    }
    if (pr != "clc" && pr != "CLC") return false;
    int cs = 0;
    while (vt < 9)
    {
        cs = Class[vt] - '0' + cs * 10;
        vt++;
    }
    if (cs > 10 || cs < 1) return false;
    return true;
}
bool CheckClass_Year(string Class, string Year)
{
    if ((!CheckClass(Class)) || (!CheckYear(Year))) return false;
    if (Class[0] == Year[2] && Class[1] == Year[3]) return true;
    return false;
}
int main()
{

	return 0;
}
