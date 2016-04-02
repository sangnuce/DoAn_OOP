#include <iostream>
#include <iomanip>
#include "result.h"

using namespace std;

Result::Result() {
	HocKy = "";
	MaMH = "";
	MaSV = "";
	DQT = 0;
	DKT = 0;
	TrangThai = 0;
}
Result::Result(Result& rs) {
	HocKy = rs.HocKy;
	MaMH = rs.MaMH;
	MaSV = rs.MaSV;
	DQT = rs.DQT;
	DKT = rs.DKT;
	TrangThai = rs.TrangThai;
}
Result::Result(string hocky, string mamh, string masv, float dqt, float dkt) {
	this->HocKy = hocky;
	this->MaMH = mamh;
	this->MaSV = masv;
	this->DQT = dqt;
	this->DKT = dkt;
	this->TrangThai = 1;
}
void Result::Read() {
	cout << "Hoc ky: ";
	fflush(stdin);
	cin >> HocKy;
	cout << "Ma MH: ";
	fflush(stdin);
	cin >> MaMH;
	cout << "Ma SV: ";
	fflush(stdin);
	cin >> MaSV;
	cout << "DQT: ";
	cin >> DQT;
	cout << "DKT: ";
	cin >> DKT;
}
void Result::Display() {
	cout << fixed;
	cout << setw(6) << HocKy << " | ";
	cout << left << setw(10) << MaMH << " | ";
	cout << left << setw(10) << MaSV << " | ";
	cout << setw(5) << setprecision(1) << DQT << " | ";
	cout << setw(5) << setprecision(1) << DKT << endl;
}
void Result::Delete() {
	this->TrangThai = 0;
}