#include <iostream>
#include <fstream>
#include <iomanip>
#include "subject.h"

using namespace std;

Subject::Subject() {
	MaMH = "";
	TenMH = "";
	NhomMH = "";
	HocKy = "";
	SoTC = 0;
}
Subject::Subject(Subject& mh) {
	MaMH = mh.MaMH;
	TenMH = mh.TenMH;
	NhomMH = mh.NhomMH;
	HocKy = mh.HocKy;
	SoTC = mh.SoTC;
}
Subject::Subject(string mamh, string tenmh, string nhommh, string hocky, int sotc) {
	this->MaMH = mamh;
	this->TenMH = tenmh;
	this->NhomMH = nhommh;
	this->HocKy = hocky;
	this->SoTC = sotc;
}
void Subject::Read() {
	cout << "Ma MH: ";
	fflush(stdin);
	cin >> MaMH;
	cout << "Ten MH: ";
	fflush(stdin);
	cin >> TenMH;
	cout << "Nhom MH: ";
	fflush(stdin);
	cin >> NhomMH;
	cout << "Hoc ky: ";
	fflush(stdin);
	cin >> HocKy;
	cout << "So tin chi: ";
	cin >> SoTC;
}
void Subject::Display() {
	cout << left << setw(10) << MaMH << " | ";
	cout << left << setw(50) << TenMH << " | ";
	cout << setw(6) << NhomMH << " | ";
	cout << setw(6) << HocKy << " | ";
	cout << setw(3) << SoTC << endl;
}
void Subject::WriteFile() {
	ofstream file("subject.txt", ios::app);
	file << MaMH << "|" << TenMH << "|" << NhomMH << "|" << HocKy << "|" << SoTC << endl;
}