#include"MainFunction.h"
void taofolder()
{
	string a;
	cin >> a;
	string c;
	c = a + "\\semester1";
	/*_mkdir(a.c_str());*/
	_mkdir(c.c_str());
	ofstream fileout;
	c = c + "\\20clc10.txt";
	fileout.open(c, ios::out);
	fileout.close();
}
bool checkFileWithFstream(string path) {
	ifstream isf(path);
	return isf.good();
}
void doitenfile()
{
	char oldname[] = "sinhvien//21127194.txt";
	char newname[] = "sinhvien//anhtuan_deptrai.txt";

	/*	Deletes the file if exists */
	if (rename(oldname, newname) != 0)
		perror("Error renaming file");
	else
		cout << "File renamed successfully";
}