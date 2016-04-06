#include <iostream>
#include <fstream>
#include <iomanip>
#include "student.h"

using namespace std;

Student::Student() {
	MaSV = "";
	HoTen = "";
	NgaySinh = "";
	GioiTinh = "";
	LopQL = "";
}
Student::Student(Student& sv) {
	MaSV = sv.MaSV;
	HoTen = sv.HoTen;
	NgaySinh = sv.NgaySinh;
	GioiTinh = sv.GioiTinh;
	LopQL = sv.LopQL;
}
Student::Student(string masv, string hoten, string ngaysinh, string gioitinh, string lopql) {
	this->MaSV = masv;
	this->HoTen = hoten;
	this->NgaySinh = ngaysinh;
	this->GioiTinh = gioitinh;
	this->LopQL = lopql;
}
void Student::Read() {
	cout << "Ma SV: ";
	fflush(stdin);
	cin >> MaSV;
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
	cout << left << setw(6) << LopQL << endl;
}
void Student::WriteFile(string filename) {
	ofstream file(filename, ios::app);
	file << MaSV << "|" << HoTen << "|" << NgaySinh << "|" << GioiTinh << "|" << LopQL << endl;
	file.close();
}