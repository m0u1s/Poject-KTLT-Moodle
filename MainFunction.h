#include "class.h"
//Hàm liên quan đến năm
YearCreated* MakeNodeCreateYear(string year);
int CutYear(string year);
void Push1CreatedYear_Tail(YearCreated*& head, string year);
void Push1CreatedYear_Head(YearCreated*& head, string year);
void PushArrangeCreatedYear(YearCreated*& head, string year);
void OutputCreatedYear_File(YearCreated*& head);
void PushAllCreatedYear_File(YearCreated*& head);
void DeleteListCreatedYear(YearCreated*& head);
void OutputList(YearCreated*& head);
//Hàm liên quan đến hàm chính

//Something gì đó của Tuấn
Something* MakeNodeSomething(string s);
void Push1Something_Tail(Something*& head, string s);
void OutputListSomething(Something*& head);
void DeleteListSomething(Something*& head);
bool CheckNameClassInYear(Something*& head, string nameclass);
//Ham Giao dien
void Create_Board(int x, int y, int h, int w);
void Create_n_Board_Col(int n, int x, int y, int h, int w);
void Create_n_Board_Row(int n, int x, int y, int h, int w);
void Create_Board_Content(int x, int y, int h, int w, string content, int ythanhsang);
void Menu_SinhVien(int x, int y, int h, int w, int ythanhsang);
void Menu_GiaoVu(int x, int y, int h, int w, int ythanhsang);
bool GiaoDienDoiMatKhau_SinhVien(int x, int y, int h, int w, student& student1);
bool GiaoDienDoiMatKhau_GiaoVu(int x, int y, int h, int w, staff& staff1);
bool Login(int x, int y, int h, int w, bool check, string& path);
bool Login2(int x, int y, int h, int w, bool check, string& path);
void GiaoDienSinhVien(int x, int y, int h, int w, int ythanhsang, string path);
void GiaoDienGiaoVu(int x, int y, int h, int w, int ythanhsang, string path);
void BangTaoLop(int x, int y, int h, int w, int ythanhsang);
//Hàm bên ngoài
void taofolder();
bool checkFileWithFstream(string path);
void doitenfile();
//Hàm Mô đẹp trai dùng để test
void MoDepTrai();
