#include <iostream>
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
	char ch;
	do {
		cout << left;
		cout << setw(30) << "1. Hien danh sach sinh vien";
		cout << setw(30) << "2. Hien danh sach mon hoc";
		cout << setw(30) << "3. Hien danh sach ket qua" << endl;
		cout << setw(30) << "4. Them moi sinh vien";
		cout << setw(30) << "5. Them moi mon hoc";
		cout << setw(30) << "6. Them moi ket qua" << endl;
		cout << setw(30) << "7. Luu danh sach sinh vien";
		cout << setw(30) << "8. Luu danh sach mon hoc";
		cout << setw(30) << "9. Luu danh sach ket qua" << endl;
		int chuc_nang = 0;
		cout << "Chon chuc nang: ";
		cin >> chuc_nang;
		switch (chuc_nang)
		{
		case 1:
			cout << "Danh sach sinh vien:" << endl;
			ql.PrintStudent();
			break;
		case 2:
			cout << "Danh sach mon hoc:" << endl;
			ql.PrintSubject();
			break;
		case 3:
			cout << "Danh sach ket qua:" << endl;
			ql.PrintResult();
			break;
		case 4:
			cout << "Them moi sinh vien:" << endl;
			ql.AddStudent();
			break;
		case 5:
			cout << "Them moi mon hoc:" << endl;
			ql.AddSubject();
			break;
		case 6:
			cout << "Them moi ket qua:" << endl;
			ql.AddResult();
			break;
		case 7:
			ql.WriteStudent("student.txt");
			cout << "Da luu lai danh sach sinh vien!" << endl;
			break;
		case 8:
			ql.WriteSubject("subject.txt");
			cout << "Da luu lai danh sach mon hoc!" << endl;
			break;
		case 9:
			ql.WriteStudent("result.txt");
			cout << "Da luu lai danh sach ket qua!" << endl;
			break;
		default:
			break;
		}
		cout << "Tiep tuc chon chuc nang? (Y/N)" << endl;
		fflush(stdin);
		cin >> ch;
	} while (strtoupper(ch) == 'Y');

	system("pause");
	return 0;
}