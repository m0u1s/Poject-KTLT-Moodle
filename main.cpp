#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <atlstr.h>
#include <direct.h>
#include <cassert>
#include <iomanip>
//Header file
#include "MainFunction.h"
using namespace std;

//void menunhapnamhoc_lophoc_hocki(int x, int y, int h, int w, int ythanhsang)
//{
//	create_board_content(x, y, h, w, "NHAP NAM HOC",ythanhsang);
//	create_board_content(x, y+h+1, h, w, "THEM LOP HOC VA SINH VIEN",ythanhsang);
//	create_board_content(x, y + 2*(h + 1), h, w, "TAO HOC KI MOI", ythanhsang);
//}
//void giaodiennhapnamhoc_lophoc_hocki(int x, int y, int h, int w, int ythanhsang)
//{
//	ShowCur(0);
//	while (true)
//	{
//		if (_kbhit()) {
//			char c = _getch();
//			if (c == -32)
//			{
//				c = _getch();
//				if (c == 80)
//				{
//					if (ythanhsang == y + 2 * (h + 1) + 1)
//					{
//						ythanhsang = y + 1;
//					}
//					else
//					{
//						ythanhsang += 2;
//					}
//				}
//				else if (c == 72)
//				{
//					if (ythanhsang == y + 1)
//					{
//						ythanhsang = y + 2 * (h + 1) + 1;
//					}
//					else
//					{
//						ythanhsang -= 2;
//					}
//				}
//			}
//			else if (c == 13)
//			{
//				string year;
//				if (ythanhsang == y + 1)
//				{
//					ShowCur(1);
//					cout << "Nhap nam hoc (2021-2022): ";
//					cin >> year;
//					_mkdir(year.c_str());
//					system("cls");
//				}
//				else if (ythanhsang == y + 3)
//				{
//					ofstream fileout;
//					string lop;
//					string path;
//					do
//					{
//						cout << "School year: ";
//						cin >> year;
//						if (FolderExists(year.c_str()) == false)
//						{
//							cout << "There is not this school year. Try again!" << endl;
//						}
//					} while (FolderExists(year.c_str()) == false);
//					char answer;
//					do
//					{
//						cout << "Name of class: ";
//						cin >> lop;
//						path = year + "\\" + lop + ".txt";
//						/*_mkdir(path.c_str());*/
//						fileout.open(path, ios::out);
//						fileout.close();
//						cout << "Complete! Do you want to continious ? (Y/N): ";
//						cin >> answer;
//					} while (answer == 'Y' || answer == 'y');
//					system("cls");
//				}
//				else if (ythanhsang == y + 5)
//				{
//					int semester;
//					cout << "St of semester (1,2,3): ";
//					cin >> semester;
//					cout << "School year: ";
//					cin >> year;
//				}
//			}
//		}
//		ShowCur(0);
//		menunhapnamhoc_lophoc_hocki(x, y, h, w, ythanhsang);
//	}
//}
// day la ham ma se thao tac het tat ca 
void Menu_n_Board(int n, int x, int y, int h, int w)
{
	ShowCur(0);//tắt con trỏ nhấp nháy
	int ythanhsang = y + 1;// thanh sáng
	bool check = true;// check true thì la sinhvien, false la giaovu
	string path; // khi đăng nhập vào thành công thì path này sẽ lưu đường dẫn đến file txt của giáo vụ đó hoặc sinh viên đó.
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
					if (Login2(x, y, 12, 29, check, path) == false) // khúc này sẽ display ra giao diện login, nếu login thất bại thì
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
						GiaoDienSinhVien(35, 5, 1, 50, 6, path);
					}
					else
					{
						// khúc này nếu check = false tức là đăng nhập vs tư cách giao vu nên sẽ vào hàm giaodiengiaovu để thao tác tiếp
						GiaoDienGiaoVu(35, 5, 1, 50, 6, path);

					}
				}
			}
		}
		// đây là khi chẳng có sự kiện phím nào cả thì nó sẽ in ra giao diện menu chọn sinhvien, giaovu như bình thường
		ShowCur(0);
		Create_n_Board_Col(n, x, y, h, w);
	}
}

int main()
{
	Menu_n_Board(2, 50, 10, 1, 20);
	return 0;
}