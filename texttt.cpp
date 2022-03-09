#include <iostream>
#include <fstream>
using namespace std;
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
		cout << "School year (2021-2022): ";
		cin >> year;
		_mkdir(year.c_str());
		ofstream fileout;
		fileout.open(year + "\\class.txt", ios::out);
		fileout.close();
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
						a.savefile("sinhvien\\" + a.getID() + "\\" + a.getID() + ".txt");
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
					ShowCur(1);
					b.add_student();
					system("cls");
				}
			}
		}
		ShowCur(0);
		menu_giaovu(x, y, h, w, ythanhsang);
	}


}