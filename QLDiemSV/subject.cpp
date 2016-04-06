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
	cin.ignore();
	getline(cin, TenMH);
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
	cout << right << setw(8) << MaMH << " | ";
	cout << left << setw(50) << TenMH << " | ";
	cout << left << setw(7) << NhomMH << " | ";
	cout << right << setw(6) << HocKy << " | ";
	cout << right << setw(3) << SoTC << endl;
}
void Subject::WriteFile(string filename) {
	ofstream file(filename, ios::app);
	file << MaMH << "|" << TenMH << "|" << NhomMH << "|" << HocKy << "|" << SoTC << endl;
	file.close();
}