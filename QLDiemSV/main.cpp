#include <iostream>
#include "quanly.h"
using namespace std;

int main() {
	QuanLy ql;
	cout << "Hien thi danh sach sinh vien:" << endl;
	ql.ReadStudent();
	ql.PrintStudent();
	ql.AddStudent();
	ql.PrintStudent();
/*
	cout << "Hien thi danh sach mon hoc:" << endl;
	ql.ReadSubject();
	ql.PrintSubject();

	cout << "Hien thi danh sach ket qua:" << endl;
	ql.ReadResult();
	ql.PrintResult();*/

	system("pause");
	return 0;
}