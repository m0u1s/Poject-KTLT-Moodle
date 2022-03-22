#include"MainFunction.h"
//Hàm bên ngoài
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
	ifstream filestr;
	string a;
	filestr.open(s, ios::in);
	filestr >> a;
	filestr.close();

	if (a.length() == 0) { return true; }
	else { return false; }
}
bool checkBirth(string birth)
{
	if (birth.length() != 10)
		return false;
	for (int i = 0; i < birth.length(); i++)
	{
		if (i != 2 && i != 5 && isdigit(birth[i]) == 0)
			return false;
		if ((i == 2 || i == 5) && birth[i] != '/')
			return false;
	}
	return true;
}
bool checkFileWithFstream(string path) {
	ifstream isf(path);
	return isf.good();
}