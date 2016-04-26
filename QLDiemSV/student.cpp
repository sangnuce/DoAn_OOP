#include <iostream>
#include <fstream>
#include <iomanip>
#include "student.h"

using namespace std;

Student::Student(string masv, string hoten, string ngaysinh, string gioitinh, string lopql) {
	this->MaSV = masv;
	this->HoTen = hoten;
	this->NgaySinh = ngaysinh;
	this->GioiTinh = gioitinh;
	this->LopQL = lopql;
	GPA = 0;
}

Student::Student(Student& sv) {
	MaSV = sv.MaSV;
	HoTen = sv.HoTen;
	NgaySinh = sv.NgaySinh;
	GioiTinh = sv.GioiTinh;
	LopQL = sv.LopQL;
	GPA = sv.GPA;
}
void Student::Read() {
	if (MaSV == "") {
		cout << "Ma SV: ";
		fflush(stdin);
		cin >> MaSV;
	}
	cout << "Ho ten: ";
	cin.ignore();
	getline(cin, HoTen);
	cout << "Ngay sinh: ";
	fflush(stdin);
	cin >> NgaySinh;
	cout << "Gioi tinh: ";
	fflush(stdin);
	cin >> GioiTinh;
	cout << "Lop QL: ";
	fflush(stdin);
	cin >> LopQL;
}
void Student::Display() {
	cout << right << setw(8) << MaSV << " | ";
	cout << left << setw(30) << HoTen << " | ";
	cout << right << setw(10) << NgaySinh << " | ";
	cout << right << setw(3) << GioiTinh << " | ";
	cout << left << setw(6) << LopQL << " | ";
	cout << fixed << setw(4) << setprecision(1) << GPA << endl;
}
void Student::WriteFile(string filename) {
	ofstream file(filename, ios::app);
	file << MaSV << "|" << HoTen << "|" << NgaySinh << "|" << GioiTinh << "|" << LopQL << endl;
	file.close();
}
string Student::GetMaSV() {
	return MaSV;
}
float Student::GetGPA() {
	return GPA;
}
void Student::SetGPA(float gpa) {
	GPA = gpa;
}