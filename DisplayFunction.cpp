#include"MainFunction.h"
using namespace std;
//Modeptrai
void Modeptrai() {
	system("cls");
	cout << "Mo dep trai";
	system("pause");
	system("cls");
}
//Giao diện 
void Create_Board_Content(int x, int y, int h, int w, string content, int ythanhsang, int j)
{
	for (int i = x; i < x + w; i++)
	{
		gotoxy(i, y); cout << "=";
		gotoxy(i, y + h + 1); cout << "=";
	}
	if (y + 1 == ythanhsang)
	{
		Setcolor(7, 0); gotoxy(x + j, y + 1); cout << content; Setcolor(0, 7);
	}
	else
	{
		gotoxy(x + j, y + 1); cout << content;
	}
	for (int i = y + 1; i <= y + h; i++)
	{
		gotoxy(x, i); cout << char(124);
		gotoxy(x + w - 1, i); cout << char(124);
	}
	gotoxy(0, y + h + 2);
}
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
		Create_Board(x, y + (h + 1) * i, h, w);
	}
}
void Create_n_Board_Row(int n, int x, int y, int h, int w)
{
	for (int i = 0; i < n; i++)
	{
		Create_Board(x + w * i + 1 * i, y, h, w);
	}
}
void BangTaoLop(int x, int y, int h, int w, int ythanhsang) {
	Create_Board_Content(x, y, h, w, "CREATE CLASSES FROM FILE", ythanhsang);
	Create_Board_Content(x, y + h + 1, 1, 50, "CREATE CLASSES", ythanhsang);
	Create_Board_Content(x, y + 2 * (h + 1), 1, 50, "SEE LIST CLASS", ythanhsang);
	Create_Board_Content(x, y + 3 * (h + 1), 1, 50, "GO BACK TO MENU", ythanhsang);
}
void BangDangKiLopHoc(int x, int y, int h, int w, int ythanhsang) {
	Create_Board_Content(x, y, h, w, "REGIST COURSE", ythanhsang);
	Create_Board_Content(x, y + h + 1, 1, 50, "VIEW REGISTED COURSE", ythanhsang);
	Create_Board_Content(x, y + 2 * (h + 1), 1, 50, "GO BACK TO MENU", ythanhsang);
}
//Hàm liên quan đến giao diện chính
bool checkendreg(date& start, date& end, date cur)
{
	if (cur.month > end.month || (cur.day == 1 && (cur.month == 9 || cur.month == 1 || cur.month == 5)) || cur.month < start.month)
	{
		return true;
	}
	else if (cur.month == end.month)
	{
		if (cur.day > end.day || cur.day < start.day)
		{
			return true;
		}
	}
	return false;
}
bool checkbeginreg(date& start, date& end, date cur)
{
	if (cur.month < start.month)
		return false;
	else if (cur.month == start.month)
	{
		if (cur.day < start.day)
		{
			return false;
		}
	}
	return true;
}
void Menu_SinhVien(int x, int y, int h, int w, int ythanhsang)
{
	Create_Board_Content(x, y, h, w, "YOUR INFORMATION", ythanhsang);
	Create_Board_Content(x, y + h + 1, h, w, "CHANGE PASSWORD", ythanhsang);
	Create_Board_Content(x, y + 2 * (h + 1), h, w, "VIEW MEMBER IN YOUR CLASS", ythanhsang);
	Create_Board_Content(x, y + 3 * (h + 1), h, w, "REGIST COURSE", ythanhsang);
	Create_Board_Content(x, y + 4 * (h + 1), h, w, "SCORE COURSE", ythanhsang);
	Create_Board_Content(x, y + 5 * (h + 1), h, w, "LOG OUT", ythanhsang);
}
void Menu_GiaoVu(int x, int y, int h, int w, int ythanhsang)
{
	Create_Board_Content(x, y, h, w, "YOUR INFORMATION", ythanhsang);
	Create_Board_Content(x, y + h + 1, h, w, "CHANGE PASSWORD", ythanhsang);
	Create_Board_Content(x, y + 2 * (h + 1), h, w, "CREATE SCHOOLYEAR", ythanhsang);
	Create_Board_Content(x, y + 3 * (h + 1), h, w, "CREATE CLASS", ythanhsang);
	Create_Board_Content(x, y + 4 * (h + 1), h, w, "CREATE SEMESTER", ythanhsang);
	Create_Board_Content(x, y + 5 * (h + 1), h, w, "CREATE COURSE", ythanhsang);
	Create_Board_Content(x, y + 6 * (h + 1), h, w, "ADD STUDENT", ythanhsang);
	Create_Board_Content(x, y + 7 * (h + 1), h, w, "LOG OUT", ythanhsang);
}
bool GiaoDienDoiMatKhau_SinhVien(int x, int y, int h, int w, student& student1)
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
	char currentpassword[30]; int j = 0;
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
	char newpassword[30]; int i = 0;
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
	char checkpassword[30]; int k = 0;
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
	char currentpassword[30]; int j = 0;
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
	char newpassword[30]; int i = 0;
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
	char checkpassword[30]; int k = 0;
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
	char s[30]; int j = 0;
	char a[30]; int i = 0;
	do
	{
		gotoxy(x + 1, y + 4);
		while (true)
		{
			char temp = _getch();
			if (((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9')) && j <= 25)
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
void GiaoDienSinhVien(int x, int y, int h, int w, int ythanhsang, string path, semester& currentsemester, const date& currentday)
{
	student a;
	a.input_file(path);
	bool checkchange = false;
	while (true)
	{
		if (currentsemester.name != "0" && currentsemester.SchoolYear != "0")
		{
			gotoxy(55, 1); cout << currentsemester.SchoolYear;
			gotoxy(49, 2); cout << currentsemester.name << " (" << currentsemester.start.day << "/" << currentsemester.start.month << "-" << currentsemester.end.day << "/" << currentsemester.end.month << ")";
			if (currentday.day == 1 && (currentday.month == 9 || currentday.month == 1 || currentday.month == 5))
			{
				cout << " END";
			}
			if (currentsemester.CheckEndReg == false)
			{
				gotoxy(46, 3); cout << "Course registration session (" << currentsemester.StartRegCourse.day << "/" << currentsemester.StartRegCourse.month << "-" << currentsemester.EndRegCourse.day << "/" << currentsemester.EndRegCourse.month << ")";
			}
			else
			{
				gotoxy(48, 3); cout << "End Course registration";
			}
		}
		if (_kbhit()) {
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 80)
				{
					if (ythanhsang == y + 5 * (h + 1) + 1)
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
				else if (ythanhsang == y + 2 * (h + 1) + 1)
				{
					system("cls");
					cout << "Class : " << a.getclass() << endl << endl;
					a.View_Class(a.getclass());
					cout << endl;
					cout << "ENTER TO GO BACK MENU" << endl;
					system("pause");
					system("cls");
				}
				else if (ythanhsang == y + 3 * (h + 1) + 1) {
					//
					fstream course_registered, course_list;
					a.register_course(course_list,course_registered);
					//
					system("cls");
				}
			}
		}
		ShowCur(0);
		Menu_SinhVien(x, y, h, w, ythanhsang);
	}

}
void GiaoDienGiaoVu(int x, int y, int h, int w, int ythanhsang, string path, semester& currentsemester, date& currentday)
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
		if (currentsemester.name != "0" && currentsemester.SchoolYear != "0")
		{
			gotoxy(55, 1); cout << currentsemester.SchoolYear;
			gotoxy(50, 3); cout << currentsemester.name << " (" << currentsemester.start.day << "/" << currentsemester.start.month << "-" << currentsemester.end.day << "/" << currentsemester.end.month << ")";
			if (currentday.day == 1 && (currentday.month == 9 || currentday.month == 1 || currentday.month == 5))
			{
				cout << " END";
			}
		}
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
					system("cls");
					ShowCur(1);
					b.create_schoolyear(head, currentday);
					system("cls");
				}
				else if (ythanhsang == y + 3 * (h + 1) + 1)
				{
					system("cls");
					ShowCur(1);
					b.create_class(head);
					system("cls");
				}
				else if (ythanhsang == y + 4 * (h + 1) + 1)
				{
					system("cls");
					b.create_semester(currentsemester, currentday);
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
//Hàm thao tác tất cả
void Menu_n_Board(int n, int x, int y, int h, int w)
{
	ShowCur(0);//tắt con trỏ nhấp nháy
	int ythanhsang = y + 1;// thanh sáng
	bool check = true;// check true thì la sinhvien, false la giaovu
	string path; // khi đăng nhập vào thành công thì path này sẽ lưu đường dẫn đến file txt của giáo vụ đó hoặc sinh viên đó.
	semester currentsemester;
	date currentday;
	currentsemester.filein_Cur(currentday);
	currentsemester.CheckEndReg = checkendreg(currentsemester.StartRegCourse, currentsemester.EndRegCourse, currentday);
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
					if (Login2(45, 8, 12, 29, check, path) == false) // khúc này sẽ display ra giao diện login, nếu login thất bại thì
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
						GiaoDienSinhVien(35, 5, 1, 50, 6, path, currentsemester, currentday);
					}
					else
					{
						// khúc này nếu check = false tức là đăng nhập vs tư cách giao vu nên sẽ vào hàm giaodiengiaovu để thao tác tiếp
						GiaoDienGiaoVu(35, 5, 1, 50, 6, path, currentsemester, currentday);

					}
				}
			}
			else if (c == 27)
			{
				system("cls");
				break;
			}
		}
		// đây là khi chẳng có sự kiện phím nào cả thì nó sẽ in ra giao diện menu chọn sinhvien, giaovu như bình thường
		ShowCur(0);
		Create_n_Board_Col(n, x, y, h, w);
	}
	cout << "ENTER TO EXIT" << endl;
}
