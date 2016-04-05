#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Exception.h"
#include "quanly.h"

using namespace std;

#define MAX 100

QuanLy::QuanLy() {
	soSV = 0;
	sv = new Student[MAX];
	soMH = 0;
	mh = new Subject[MAX];
	soKQ = 0;
	kq = new Result[MAX*MAX];
}

QuanLy::~QuanLy() {
	delete[] sv;
	delete[] mh;
	delete[] kq;
}

vector<vector<string>> QuanLy::ReadFile(string filename) {
	ifstream file(filename);
	vector<vector<string>> info;
	if (file.fail()) {
		throw Exception("Khong the mo file " + filename + "\n");
		return info;
	}
	while (!file.eof()) {
		string str;
		getline(file, str);
		if (str.length() > 0) {
			vector<string> vt;
			string data = "";
			for (size_t i = 0; i < str.length(); i++) {
				if (str[i] == '|') {
					vt.push_back(data);
					data = "";
				}
				else {
					data += str[i];
				}
			}
			vt.push_back(data);
			info.push_back(vt);
		}
	}
	file.close();
	return info;
}

void QuanLy::ClearFile(string filename) {
	ofstream file(filename);
	file.clear();
	file.close();
}

void QuanLy::ReadStudent(string filename) {
	try {
		vector<vector<string>> info = ReadFile(filename);
		soSV = 0;
		for (size_t i = 0; i < info.size(); i++) {
			if (info[i].size() != 5) {
				throw Exception("Cau truc du lieu trong file " + filename + " khong hop le! (Dong " + to_string(i + 1) + ")\n");
			}
			else {
				soSV++;
				Student	*obj = new Student(info[i][0], info[i][1], info[i][2], info[i][3], info[i][4]);
				sv[i] = *obj;
			}
		}
	}
	catch (Exception &ex) {
		cout << ex.ToString();
	}
}

void QuanLy::ReadSubject(string filename) {
	try {
		vector<vector<string>> info = ReadFile(filename);
		soMH = 0;
		for (size_t i = 0; i < info.size(); i++) {
			if (info[i].size() != 5) {
				throw Exception("Cau truc du lieu trong file " + filename + " khong hop le! (Dong " + to_string(i + 1) + ")\n");
			}
			else {
				soMH++;
				Subject *obj = new Subject(info[i][0], info[i][1], info[i][2], info[i][3], stoi(info[i][4]));
				mh[i] = *obj;
			}
		}
	}
	catch (Exception &ex) {
		cout << ex.ToString();
	}
}

void QuanLy::ReadResult(string filename) {
	try {
		vector<vector<string>> info = ReadFile(filename);
		soKQ = 0;
		for (size_t i = 0; i < info.size(); i++) {
			if (info[i].size() != 5) {
				throw Exception("Cau truc du lieu trong file " + filename + " khong hop le! (Dong " + to_string(i + 1) + ")\n");
			}
			else {
				soKQ++;
				Result *obj = new Result(info[i][0], info[i][1], info[i][2], stof(info[i][3]), stof(info[i][4]));
				kq[i] = *obj;
			}
		}
	}
	catch (Exception &ex) {
		cout << ex.ToString();
	}
}

void QuanLy::PrintStudent() {
	cout << left << setw(8) << "Ma SV" << " | ";
	cout << left << setw(30) << "Ho ten" << " | ";
	cout << left << setw(10) << "Ngay sinh" << " | ";
	cout << left << setw(3) << "GT" << " | ";
	cout << left << setw(6) << "Lop QL" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < soSV; i++) {
		sv[i].Display();
	}
	cout << "----------------------------------------------------------------------" << endl;
}

void QuanLy::PrintSubject() {
	cout << left << setw(8) << "Ma MH" << " | ";
	cout << left << setw(50) << "Ten MH" << " | ";
	cout << left << setw(7) << "Nhom MH" << " | ";
	cout << left << setw(6) << "Hoc ky" << " | ";
	cout << left << setw(3) << "So TC" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < soMH; i++) {
		mh[i].Display();
	}
	cout << "-----------------------------------------------------------------------------------------" << endl;
}

void QuanLy::PrintResult() {
	cout << left << setw(6) << "Hoc ky" << " | ";
	cout << left << setw(8) << "Ma MH" << " | ";
	cout << left << setw(8) << "Ma SV" << " | ";
	cout << right << setw(4) << "DQT" << " | ";
	cout << right << setw(4) << "DKT" << endl;
	cout << "-------------------------------------------" << endl;
	for (int i = 0; i < soKQ; i++) {
		kq[i].Display();
	}
	cout << "-------------------------------------------" << endl;
}

void QuanLy::AddStudent() {
	Student *s = new Student();
	s->Read();
	sv[soSV] = *s;
	//sv[soSV].WriteFile("student.txt");
	soSV++;
}

void QuanLy::AddSubject() {
	Subject *s = new Subject();
	s->Read();
	mh[soMH] = *s;
	//mh[soMH].WriteFile("subject.txt");
	soMH++;
}

void QuanLy::AddResult() {
	Result *s = new Result();
	s->Read();
	kq[soKQ] = *s;
	//kq[soKQ].WriteFile("result.txt");
	soKQ++;
}

void QuanLy::WriteStudent(string filename) {
	ClearFile(filename);
	for (int i = 0; i < soSV; i++) {
		sv[i].WriteFile(filename);
	}
}

void QuanLy::WriteSubject(string filename) {
	ClearFile(filename);
	for (int i = 0; i < soMH; i++) {
		mh[i].WriteFile(filename);
	}
}

void QuanLy::WriteResult(string filename) {
	ClearFile(filename);
	for (int i = 0; i < soKQ; i++) {
		kq[i].WriteFile(filename);
	}
}