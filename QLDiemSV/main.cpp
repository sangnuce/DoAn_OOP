﻿#include <iostream>
#include <iomanip>
#include "quanly.h"
using namespace std;

char strtoupper(char ch) {
	if (97 <= ch && ch <= 122)
		ch -= 32;
	return ch;
}

int main() {
	QuanLy ql;
	ql.ReadStudent("student.txt");
	ql.ReadSubject("subject.txt");
	ql.ReadResult("result.txt");
	do {
		cout << left;
		cout << setw(30) << "1.  Hien danh sach sinh vien";
		cout << setw(30) << "2.  Hien danh sach mon hoc";
		cout << setw(30) << "3.  Hien danh sach ket qua" << endl;
		cout << setw(30) << "4.  Them moi sinh vien";
		cout << setw(30) << "5.  Them moi mon hoc";
		cout << setw(30) << "6.  Them moi ket qua" << endl;
		cout << setw(30) << "7.  Sua sinh vien";
		cout << setw(30) << "8.  Sua mon hoc";
		cout << setw(30) << "9.  Sua ket qua" << endl;
		cout << setw(30) << "10. Xoa sinh vien";
		cout << setw(30) << "11. Xoa mon hoc";
		cout << setw(30) << "12. Xoa ket qua" << endl;
		cout << setw(30) << "13. Luu danh sach sinh vien";
		cout << setw(30) << "14. Luu danh sach mon hoc";
		cout << setw(30) << "15. Luu danh sach ket qua" << endl;
		int chuc_nang = 0;
		cout << "Chon chuc nang: ";
		cin >> chuc_nang;
		switch (chuc_nang)
		{
		case 1:
			ql.PrintStudent();
			break;
		case 2:
			ql.PrintSubject();
			break;
		case 3:
			ql.PrintResult();
			break;
		case 4:
			ql.AddStudent();
			break;
		case 5:
			ql.AddSubject();
			break;
		case 6:
			ql.AddResult();
			break;
		case 7:
			ql.EditStudent();
			break;
		case 8:
			ql.EditSubject();
			break;
		case 9:
			ql.EditResult();
			break;
		case 10:
			ql.RemoveStudent();
			break;
		case 11:
			ql.RemoveSubject();
			break;
		case 12:
			ql.RemoveResult();
			break;
		case 13:
			ql.WriteStudent("student.txt");
			break;
		case 14:
			ql.WriteSubject("subject.txt");
			break;
		case 15:
			ql.WriteStudent("result.txt");
			break;
		default:
			break;
		}
		cout << "Tiep tuc chon chuc nang? (Y/N)" << endl;
		cin.ignore();
	} while (strtoupper(getchar()) == 'Y');

	system("pause");
	return 0;
}