#include <iostream>
#include <fstream>
#include <iomanip>
#include "subject.h"

using namespace std;

Subject::Subject(Subject& mh) {
	MaMH = mh.MaMH;
	TenMH = mh.TenMH;
	SoTC = mh.SoTC;
}

Subject::Subject(string mamh, string tenmh, int sotc) {
	this->MaMH = mamh;
	this->TenMH = tenmh;
	this->SoTC = sotc;
}

void Subject::Read() {
	if (MaMH == "") {
		cout << "Ma MH: ";
		fflush(stdin);
		cin >> MaMH;
	}
	cout << "Ten MH: ";
	cin.ignore();
	getline(cin, TenMH);
	cout << "So tin chi: ";
	cin >> SoTC;
}
void Subject::Display() {
	cout << right << setw(8) << MaMH << " | ";
	cout << left << setw(50) << TenMH << " | ";
	cout << right << setw(3) << SoTC << endl;
}
void Subject::WriteFile(string filename) {
	ofstream file(filename, ios::app);
	file << MaMH << "|" << TenMH << "|" << SoTC << endl;
	file.close();
}
string Subject::GetMaMH() {
	return MaMH;
}
int Subject::GetSoTC() {
	return SoTC;
}