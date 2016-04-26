#include <iostream>
#include <fstream>
#include <iomanip>
#include "result.h"

using namespace std;

Result::Result(Result& rs) {
	MaMH = rs.MaMH;
	MaSV = rs.MaSV;
	DQT = rs.DQT;
	DKT = rs.DKT;
}

Result::Result(string mamh, string masv, float dqt, float dkt) {
	this->MaMH = mamh;
	this->MaSV = masv;
	this->DQT = dqt;
	this->DKT = dkt;
}

void Result::Read() {
	if (MaMH == "") {
		cout << "Ma MH: ";
		fflush(stdin);
		cin >> MaMH;
	}
	if (MaSV == "") {
		cout << "Ma SV: ";
		fflush(stdin);
		cin >> MaSV;
	}
	cout << "DQT: ";
	cin >> DQT;
	cout << "DKT: ";
	cin >> DKT;
}

void Result::Display() {
	cout << setw(8) << MaMH << " | ";
	cout << setw(8) << MaSV << " | ";
	cout << fixed;
	cout << setw(4) << setprecision(1) << DQT << " | ";
	cout << setw(4) << setprecision(1) << DKT << " | ";
	cout << setw(4) << setprecision(1) << CalAvg() << endl;
}

void Result::WriteFile(string filename) {
	ofstream file(filename, ios::app);
	file << MaMH << "|" << MaSV << "|" << DQT << "|" << DKT << endl;
	file.close();
}

string Result::GetMaMH() {
	return MaMH;
}

string Result::GetMaSV() {
	return MaSV;
}

float Result::CalAvg() {
	float DTB = ((DQT * (float)0.3) + (DKT * (float)0.7));
	//làm tròn kết quả và trả về:
	int tmp = (int)(DTB * 100);
	if (tmp / 10 >= 5) tmp = tmp + 5;
	tmp = tmp / 10;
	return (int)(tmp) / (float)10;
}