#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "subject.h"
#include "student.h"
#include "result.h"

#define max 100

using namespace std;

vector<vector<string>> ReadFile(string filename) {
	ifstream file;
	file.open(filename);
	vector<vector<string>> info;
	if (file.fail()) {
		cout << "Cannot open file "<< filename << endl;
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
				} else {
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

void ReadStudent(Student** data, int &n) {
	vector<vector<string>> info = ReadFile("student.txt");
	n = info.size();
	for (int i = 0; i < n; i++) {
		Student *obj = new Student(info[i][0], info[i][1], info[i][2], info[i][3], info[i][4]);
		data[i] = *&obj;
	}
}

void ReadSubject(Subject** data, int &n) {
	vector<vector<string>> info = ReadFile("subject.txt");
	n = info.size();
	for (int i = 0; i < n; i++) {
		Subject *obj = new Subject(info[i][0], info[i][1], info[i][2], info[i][3], stoi(info[i][4]));
		data[i] = *&obj;
	}
}

void ReadResult(Result** data, int &n) {
	vector<vector<string>> info = ReadFile("result.txt");
	n = info.size();
	for (int i = 0; i < n; i++) {
		Result *obj = new Result(info[i][0], info[i][1], info[i][2], stof(info[i][3]), stof(info[i][4]));
		data[i] = *&obj;
	}
}

void PrintStudent(Student** sv, int soSV) {
	cout << "| ";
	cout << left << setw(10) << "Ma SV" << " | ";
	cout << left << setw(30) << "Ho ten" << " | ";
	cout << setw(10) << "Ngay sinh" << " | ";
	cout << left << setw(3) << "GT" << " | ";
	cout << left << setw(6) << "Lop QL" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (int i = 0; i < soSV; i++) {
		cout << "| ";
		sv[i]->Display();
	}
	cout << "-------------------------------------------------------------------------" << endl;
}

void PrintSubject(Subject** mh, int soMH) {
	for (int i = 0; i < soMH; i++) {
		mh[i]->Display();
	}
}

void PrintResult(Result** kq, int soKQ) {
	for (int i = 0; i < soKQ; i++) {
		kq[i]->Display();
	}
}

int main() {
	int soSV;
	Student** sv;
	sv = new Student*[max];
	ReadStudent(sv, soSV);
	cout << "Hien thi danh sach sinh vien:" << endl;
	PrintStudent(sv, soSV);
	int soMH;
	Subject** mh;
	mh = new Subject*[max];
	ReadSubject(mh, soMH);
	cout << "Hien thi danh sach mon hoc:" << endl;
	PrintSubject(mh, soMH);
	int soKQ;
	Result** kq;
	kq = new Result*[max];
	ReadResult(kq, soKQ);
	cout << "Hien thi danh sach ket qua:" << endl;
	PrintResult(kq, soKQ);
	system("pause");
	return 0;
}