#pragma once
#include "class.h"
bool FolderExists(const CString& strFolderName);
void textcolor(int x);
void gotoxy(int x, int y);
void Setcolor(int backgound_color, int text_color);
BOOL WINAPI SetConsoleTitle(
	_In_ LPCTSTR lpConsoleTitle
);
void ShowCur(bool CursorVisibility);
bool is_emptyy(string s);
bool checkBirth(string birth);
bool checkFileWithFstream(string path);
int CutYear(string year);

Something* MakeNodeSomething(string s);
void Push1Something_Tail(Something*& head, string s);
void Push1Something_Head(Something*& head, string s);
void OutputListSomething(Something*& head);
void DeleteListSomething(Something*& head);
bool CheckNameClassInYear(Something*& head, string nameclass);
void PushArrangeCreatedYear(Something*& headYear, string year);
void OutputCreatedYear_File(Something*& headYear);
void OutputList(Something*& head);
void PushAllCreatedYear_File(Something*& headYear);
void DeleteListCreatedYear(Something*& head);

void DeletetempStudent(tempStudent*& head, string &IDstudent);

void Create_Board_Content(int &x, int y, int &h, int &w, string content, int &ythanhsang, int j = 16);
void Create_n_Board_Col(int n, int x, int y, int h, int w);
void BangTaoLop(int x, int y, int h, int w, int ythanhsang);
void BangDangKiLopHoc(int x, int y, int h, int w, int ythanhsang);
void CourseMenu(int x, int y, int h, int w, int ythanhsang);
void ScoreMenuStaff(int x, int y, int h, int w, int ythanhsang);

void Menu_SinhVien(int &x, int &y, int &h, int &w, int &ythanhsang);
void Menu_GiaoVu(int &x, int &y, int &h, int &w, int &ythanhsang);
bool GiaoDienDoiMatKhau_SinhVien(int x, int y, int h, int w, student& student1);
bool GiaoDienDoiMatKhau_GiaoVu(int x, int y, int h, int w, staff& staff1);
bool Login2(int x, int y, int h, int w, bool check, string& path);
void GiaoDienSinhVien(int x, int y, int h, int w, int ythanhsang, string &path, semester& currentsemester, const date& currentday);
void GiaoDienGiaoVu(int x, int y, int h, int w, int ythanhsang, string &path, semester& currentsemester, date& currentday);
void Menu_n_Board(int n, int x, int y, int h, int w);

