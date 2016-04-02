#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "quanly.h"

using namespace std;

#define max 100

QuanLy::QuanLy() {
	soSV = 0;
	sv = new Student[max];
	soMH = 0;
	mh = new Subject[max];
	soKQ = 0;
	kq = new Result[max*max];
}

QuanLy::~QuanLy() {
	delete sv;
	delete mh;
	delete kq;
}

vector<vector<string>> QuanLy::ReadFile(string filename) {
	ifstream file;
	file.open(filename);
	vector<vector<string>> info;
	if (file.fail()) {
		cout << "Cannot open file " << filename << endl;
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

void QuanLy::ReadStudent() {
	vector<vector<string>> info = ReadFile("student.txt");
	soSV = info.size();
	for (int i = 0; i < soSV; i++) {
		Student *obj = new Student(info[i][0], info[i][1], info[i][2], info[i][3], info[i][4]);
		sv[i] = *obj;
	}
}

void QuanLy::ReadSubject() {
	vector<vector<string>> info = ReadFile("subject.txt");
	soMH = info.size();
	for (int i = 0; i < soMH; i++) {
		Subject *obj = new Subject(info[i][0], info[i][1], info[i][2], info[i][3], stoi(info[i][4]));
		mh[i] = *obj;
	}
}

void QuanLy::ReadResult() {
	vector<vector<string>> info = ReadFile("result.txt");
	soKQ = info.size();
	for (int i = 0; i < soKQ; i++) {
		Result *obj = new Result(info[i][0], info[i][1], info[i][2], stof(info[i][3]), stof(info[i][4]));
		kq[i] = *obj;
	}
}

void QuanLy::PrintStudent() {
	cout << left << setw(10) << "Ma SV" << " | ";
	cout << left << setw(30) << "Ho ten" << " | ";
	cout << setw(10) << "Ngay sinh" << " | ";
	cout << left << setw(3) << "GT" << " | ";
	cout << left << setw(6) << "Lop QL" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < soSV; i++) {
		sv[i].Display();
	}
	cout << "----------------------------------------------------------------------" << endl;
}

void QuanLy::PrintSubject() {
	for (int i = 0; i < soMH; i++) {
		mh[i].Display();
	}
}

void QuanLy::PrintResult() {
	for (int i = 0; i < soKQ; i++) {
		kq[i].Display();
	}
}

void QuanLy::AddStudent() {
	Student *s = new Student();
	s->Read();
	sv[soSV] = *s;
	sv[soSV].WriteFile();
	soSV++;
}

void QuanLy::AddSubject() {
	Subject *s = new Subject();
	s->Read();
	mh[soMH] = *s;
	mh[soMH].WriteFile();
	soMH++;
}

void QuanLy::AddResult() {
	Result *s = new Result();
	s->Read();
	kq[soKQ] = *s;
	kq[soKQ].WriteFile();
	soKQ++;
}