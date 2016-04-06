#include <iostream>
#include <fstream>
#include <iomanip>
#include "result.h"

using namespace std;

Result::Result() {
	HocKy = "";
	MaMH = "";
	MaSV = "";
	DQT = 0;
	DKT = 0;
}
Result::Result(Result& rs) {
	HocKy = rs.HocKy;
	MaMH = rs.MaMH;
	MaSV = rs.MaSV;
	DQT = rs.DQT;
	DKT = rs.DKT;
}
Result::Result(string hocky, string mamh, string masv, float dqt, float dkt) {
	this->HocKy = hocky;
	this->MaMH = mamh;
	this->MaSV = masv;
	this->DQT = dqt;
	this->DKT = dkt;
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
	cout << setw(6) << HocKy << " | ";
	cout << setw(8) << MaMH << " | ";
	cout << setw(8) << MaSV << " | ";
	cout << fixed;
	cout << setw(4) << setprecision(1) << DQT << " | ";
	cout << setw(4) << setprecision(1) << DKT << endl;
}
void Result::WriteFile(string filename) {
	ofstream file(filename, ios::app);
	file << HocKy << "|" << MaMH << "|" << MaSV << "|" << DQT << "|" << DKT << endl;
	file.close();
}