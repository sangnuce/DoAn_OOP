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
	getline(cin, MaSV);
	cout << "Ho ten: ";
	getline(cin, HoTen);
	cout << "Ngay sinh: ";
	getline(cin, NgaySinh);
	cout << "Gioi tinh: ";
	getline(cin, GioiTinh);
	cout << "Lop QL: ";
	getline(cin, LopQL);
}
void Student::Display() {
	cout << left << setw(8) << MaSV << " | ";
	cout << left << setw(30) << HoTen << " | ";
	cout << right << setw(10) << NgaySinh << " | ";
	cout << right << setw(3) << GioiTinh << " | ";
	cout << right << setw(6) << LopQL << endl;
}
void Student::WriteFile(string filename) {
	ofstream file(filename, ios::app);
	file << MaSV << "|" << HoTen << "|" << NgaySinh << "|" << GioiTinh << "|" << LopQL << endl;
}