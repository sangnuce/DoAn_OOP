#include <iostream>
#include <fstream>
#include <cstring>
#include "subject.h"
#include "student.h"

#define max 100

using namespace std;

void ReadStudent(Student** sv, int &soSV) {
	ifstream file;
	file.open("student.txt");
	if (file.fail()) {
		cout << "Cannot open file student.txt!" << endl;
		return;
	}
	soSV = 0;
	while (!file.eof()) {
		string str;
		getline(file, str);
		if (str.length() > 0) {
			string info[5] = { "","","","","" };
			int n = 0;
			for (size_t i = 0; i < str.length(); i++) {
				if (str[i] == '|') {
					n++;
				}
				else {
					info[n] += str[i];
				}
			}
			Student *st = new Student(info[0], info[1], info[2], info[3], info[4]);
			sv[soSV] = *&st; //Gan truc tiep vao o nho duoc tro den.
							 //Neu chi gan dia chi thì se bi loi vi dia chi se duoc giai phong khi ra khoi ham.
			soSV++;
		}
	}
	file.close();
}

void ReadSubject(Subject** mh, int &soMH) {
	ifstream file;
	file.open("subject.txt");
	if (file.fail()) {
		cout << "Cannot open file subject.txt!" << endl;
		return;
	}
	soMH = 0;
	while (!file.eof()) {
		string str;
		getline(file, str);
		if (str.length() > 0) {
			string info[5] = { "","","","","" };
			int n = 0;
			for (size_t i = 0; i < str.length(); i++) {
				if (str[i] == '|') {
					n++;
				}
				else {
					info[n] += str[i];
				}
			}
			Subject *st = new Subject(info[0], info[1], info[2], info[3], stoi(info[4]));
			mh[soMH] = *&st;
			soMH++;
		}
	}
	file.close();
}

void PrintStudent(Student** sv, int soSV) {
	for (int i = 0; i < soSV; i++) {
		sv[i]->Display();
	}
}

void PrintSubject(Subject** mh, int soMH) {
	for (int i = 0; i < soMH; i++) {
		mh[i]->Display();
	}
}

int main() {
	int soSV;
	Student** sv;
	sv = new Student*[max];
	int soMH;
	Subject** mh;
	mh = new Subject*[max];
	ReadStudent(sv, soSV);
	ReadSubject(mh, soMH);
	cout << "Hien thi danh sach sinh vien:" << endl;
	PrintStudent(sv, soSV);
	cout << "Hien thi danh sach mon hoc:" << endl;
	PrintSubject(mh, soMH);
	system("pause");
	return 0;
}