#include <iostream>
#include <fstream>
#include "Exception.h"
#include "quanly.h"
using namespace std;

int main() {
	QuanLy ql;
	cout << "Hien thi danh sach sinh vien:" << endl;
	ql.ReadStudent();
	ql.PrintStudent();

	system("pause");
	return 0;
}