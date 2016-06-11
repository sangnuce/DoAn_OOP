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
		throw ExFileNotFound("Khong the mo file " + filename + "\n");
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

void QuanLy::Init() {
	ReadStudent("student.txt");
	ReadSubject("subject.txt");
	ReadResult("result.txt");
	CalGPA();
}


void QuanLy::ClearFile(string filename) {
	ofstream file(filename);
	file.clear();
	file.close();
}

void QuanLy::ReadStudent(string filename) {
	vector<vector<string>> info = ReadFile(filename);
	soSV = 0;
	for (size_t i = 0; i < info.size(); i++) {
		if (info[i].size() != 5) {
			throw ExReadFileError("Cau truc du lieu trong file " + filename + " khong hop le! (Dong " + to_string(i + 1) + ")\n");
		}
		else {
			soSV++;
			Student	obj(info[i][0], info[i][1], info[i][2], info[i][3], info[i][4]);
			sv[i] = obj;
		}
	}
}

void QuanLy::ReadSubject(string filename) {
	vector<vector<string>> info = ReadFile(filename);
	soMH = 0;
	for (size_t i = 0; i < info.size(); i++) {
		if (info[i].size() != 3) {
			throw ExReadFileError("Cau truc du lieu trong file " + filename + " khong hop le! (Dong " + to_string(i + 1) + ")\n");
		}
		else {
			soMH++;
			Subject obj(info[i][0], info[i][1], stoi(info[i][2]));
			mh[i] = obj;
		}
	}
}

void QuanLy::ReadResult(string filename) {
	vector<vector<string>> info = ReadFile(filename);
	soKQ = 0;
	for (size_t i = 0; i < info.size(); i++) {
		if (info[i].size() != 4) {
			throw ExReadFileError("Cau truc du lieu trong file " + filename + " khong hop le! (Dong " + to_string(i + 1) + ")\n");
		}
		else {
			soKQ++;
			Result obj(info[i][0], info[i][1], stof(info[i][2]), stof(info[i][3]));
			kq[i] = obj;
		}
	}
}

void QuanLy::PrintStudent() {
	cout << "Danh sach sinh vien:" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << right << setw(8) << "Ma SV" << " | ";
	cout << left << setw(30) << "Ho ten" << " | ";
	cout << right << setw(10) << "Ngay sinh" << " | ";
	cout << right << setw(3) << "GT" << " | ";
	cout << left << "Lop QL" << " | ";
	cout << setw(4) << "DTB" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	if (soSV == 0) cout << "\tKhong co du lieu" << endl;
	else {
		for (int i = 0; i < soSV; i++) {
			sv[i].Display();
		}
	}
	cout << "-----------------------------------------------------------------------------" << endl;
}

void QuanLy::PrintSubject() {
	cout << "Danh sach mon hoc:" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << right << setw(8) << "Ma MH" << " | ";
	cout << left << setw(50) << "Ten MH" << " | ";
	cout << "So TC" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	if (soMH == 0) cout << "\tKhong co du lieu" << endl;
	else {
		for (int i = 0; i < soMH; i++) {
			mh[i].Display();
		}
	}
	cout << "----------------------------------------------------------------------" << endl;
}

void QuanLy::PrintResult() {
	cout << "Danh sach ket qua:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << setw(8) << "Ma MH" << " | ";
	cout << setw(8) << "Ma SV" << " | ";
	cout << setw(4) << "DQT" << " | ";
	cout << setw(4) << "DKT" << " | ";
	cout << setw(4) << "DTB" << endl;
	cout << "-----------------------------------------" << endl;
	if (soKQ == 0) cout << "\tKhong co du lieu" << endl;
	else {
		for (int i = 0; i < soKQ; i++) {
			kq[i].Display();
		}
	}
	cout << "-----------------------------------------" << endl;
}

int QuanLy::FindStudent(string masv) {
	for (int i = 0; i < soSV; i++) {
		if (sv[i].GetMaSV() == masv) {
			return i;
		}
	}
	return -1;
}

int QuanLy::FindSubject(string mamh) {
	for (int i = 0; i < soMH; i++) {
		if (mh[i].GetMaMH() == mamh) {
			return i;
		}
	}
	return -1;
}

int QuanLy::FindResult(string masv, string mamh) {
	for (int i = 0; i < soKQ; i++) {
		if (kq[i].GetMaSV() == masv && kq[i].GetMaMH() == mamh) {
			return i;
		}
	}
	return -1;
}

void QuanLy::AddStudent() {
	string masv;
	cout << "Nhap ma SV: ";
	fflush(stdin);
	cin >> masv;
	if (FindStudent(masv) >= 0) {
		cout << "Ma SV da ton tai trong he thong!" << endl;
		AddStudent();
	}
	else {
		Student obj(masv);
		obj.Read();
		sv[soSV] = obj;
		soSV++;
		cout << "Them moi sinh vien thanh cong!" << endl;
		WriteStudent("student.txt"); // Cập nhật lại dữ liệu trong file txt
	}
}

void QuanLy::AddSubject() {
	string mamh;
	cout << "Nhap ma MH: ";
	fflush(stdin);
	cin >> mamh;
	if (FindSubject(mamh) >= 0) {
		cout << "Ma MH da ton tai trong he thong!" << endl;
		AddSubject();
	}
	else {
		Subject obj(mamh);
		obj.Read();
		mh[soMH] = obj;
		soMH++;
		cout << "Them moi mon hoc thanh cong!" << endl;
		WriteSubject("subject.txt"); // Cập nhật lại dữ liệu trong file txt
	}
}

void QuanLy::AddResult() {
	cout << "1. Nhap ket qua theo ma sinh vien" << endl;
	cout << "2. Nhap ket qua theo ma mon hoc" << endl;
	cout << "Lua chon: ";
	int x = 0;
	cin >> x;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		x = 0;
	}
	switch (x) {
	case 1:
		AddResultByStudent();
		break;
	case 2:
		AddResultBySubject();
		break;
	default:
		cout << "Lua chon sai!" << endl;
		AddResult();
		break;
	}
}

void QuanLy::AddResultByStudent() {
	string masv;
	cout << "Nhap ma SV can them ket qua: ";
	fflush(stdin);
	cin >> masv;
	if (FindStudent(masv) >= 0) {
		int somh;
		cout << "Nhap so mon hoc: ";
		cin >> somh;
		int i = 0;
		while (i < somh) {
			string mamh;
			cout << "Nhap ma MH thu " << i + 1 << ": ";
			fflush(stdin);
			cin >> mamh;
			if (FindSubject(mamh) < 0) {
				cout << "Khong ton tai mon hoc co MaMH = " << mamh << endl;
				i--;
			}
			else if (FindResult(masv, mamh) >= 0) {
				cout << "Da ton tai ket qua co MaSV = " << masv << ", MaMH = " << mamh << " trong he thong!" << endl;
			}
			else {
				float dqt, dkt;
				cout << "Nhap DQT: ";
				cin >> dqt;
				cout << "Nhap DKT: ";
				cin >> dkt;
				Result obj(mamh, masv, dqt, dkt);
				kq[soKQ] = obj;
				soKQ++;
				cout << "Them moi ket qua thanh cong!" << endl;
				WriteResult("result.txt"); // Cập nhật lại dữ liệu trong file txt
			}
			i++;
		}
	}
	else {
		cout << "Ma SV " << masv << " khong ton tai trong he thong!" << endl;
		AddResultByStudent();
	}
}

void QuanLy::AddResultBySubject() {
	string mamh;
	cout << "Nhap ma MH can them ket qua: ";
	fflush(stdin);
	cin >> mamh;
	if (FindSubject(mamh) >= 0) {
		int sosv;
		cout << "Nhap so sinh vien: ";
		cin >> sosv;
		int i = 0;
		while (i < sosv) {
			string masv;
			cout << "Nhap ma SV thu " << i + 1 << ": ";
			fflush(stdin);
			cin >> masv;
			if (FindStudent(masv) < 0) {
				cout << "Khong ton tai sinh vien co MaSV = " << masv << endl;
				i--;
			}
			else if (FindResult(masv, mamh) >= 0) {
				cout << "Da ton tai ket qua co MaSV = " << masv << ", MaMH = " << mamh << " trong he thong!" << endl;
			}
			else {
				float dqt, dkt;
				cout << "Nhap DQT: ";
				cin >> dqt;
				cout << "Nhap DKT: ";
				cin >> dkt;
				Result obj(mamh, masv, dqt, dkt);
				kq[soKQ] = obj;
				soKQ++;
				cout << "Them moi ket qua thanh cong!" << endl;
				WriteResult("result.txt"); // Cập nhật lại dữ liệu vào file txt
			}
			i++;
		}
	}
	else {
		cout << "Ma MH " << mamh << " khong ton tai trong he thong!" << endl;
		AddResultBySubject();
	}
}

void QuanLy::EditStudent() {
	string masv = "";
	cout << "Nhap ma SV can chinh sua: ";
	fflush(stdin);
	cin >> masv;
	int position = FindStudent(masv);
	if (position >= 0) {
		cout << "Nhap thong tin moi:" << endl;
		Student obj;
		obj.Read();
		sv[position] = obj;
		EditResultStudentID(masv, obj.GetMaSV());
		cout << "Cap nhat thong tin thanh cong!" << endl;
		WriteStudent("student.txt"); // Cập nhật lại dữ liệu trong file txt
	}
	else {
		cout << "Khong tim thay sinh vien co MaSV = " << masv << endl;
	}
}

void QuanLy::EditSubject()
{
	string mamh = "";
	cout << "Nhap ma MH can chinh sua: ";
	fflush(stdin);
	cin >> mamh;
	int position = FindSubject(mamh);
	if (position >= 0) {
		cout << "Nhap thong tin moi:" << endl;
		Subject obj;
		obj.Read();
		mh[position] = obj;
		EditResultSubjectID(mamh, obj.GetMaMH());
		cout << "Cap nhat thong tin thanh cong!" << endl;
		WriteSubject("subject.txt"); // Cập nhật lại dữ liệu trong file txt
	}
	else {
		cout << "Khong tim thay mon hoc co MaMH = " << mamh << endl;
	}
}

void QuanLy::EditResult()
{
	string masv = "";
	string mamh = "";
	cout << "Nhap thong tin ket qua can chinh sua:" << endl;
	cout << "Ma SV: ";
	fflush(stdin);
	cin >> masv;
	cout << "Ma MH: ";
	fflush(stdin);
	cin >> mamh;
	int position = FindResult(masv, mamh);
	if (position >= 0) {
		cout << "Nhap thong tin moi:" << endl;
		Result obj(mamh,masv);
		obj.Read();
		kq[position] = obj;
		cout << "Cap nhat thong tin thanh cong!" << endl;
		WriteResult("result.txt"); // Cập nhật lại dữ liệu vào file txt
	}
	else {
		cout << "Khong tim thay ket qua co MaSV = " << masv << ", MaMH = " << mamh << endl;
	}
}

void QuanLy::EditResultStudentID(std::string oldID, std::string newID)
{
	for (int i = 0; i < soKQ; i++)
	{
		if (kq[i].GetMaSV() == oldID)
		{
			kq[i].SetMaSV(newID);
		}
	}
	WriteResult("Result.txt"); // Cập nhật dữ liệu vào file txt
}

void QuanLy::EditResultSubjectID(std::string oldID, std::string newID)
{
	for (int i = 0; i < soKQ; i++)
	{
		if (kq[i].GetMaMH() == oldID)
		{
			kq[i].SetMaMH(newID);
		}
	}
	WriteResult("Result.txt"); // Cập nhật dữ liệu vào file txt
}

void QuanLy::RemoveStudent(string masv) {
	if (masv == "") {
		cout << "Nhap ma SV can xoa: ";
		fflush(stdin);
		cin >> masv;
	}
	int i = FindStudent(masv);
	if (i >= 0) {
		for (int j = i; j < soSV - 1; j++) {
			sv[j] = sv[j + 1];
		}
		soSV--;
		cout << "Xoa thanh cong mon hoc co MaSV = " << masv << endl;
		WriteStudent("student.txt"); // Cập nhật lại dữ liệu trong file txt
		RemoveResultByStudent(masv);
	}
	else {
		cout << "Khong tim thay sinh vien co MaSV = " << masv << endl;
	}
}

void QuanLy::RemoveSubject(string mamh) {
	if (mamh == "") {
		cout << "Nhap ma MH can xoa: ";
		fflush(stdin);
		cin >> mamh;
	}
	int i = FindSubject(mamh);
	if (i >= 0) {
		for (int j = i; j < soMH - 1; j++) {
			mh[j] = mh[j + 1];
		}
		soMH--;
		cout << "Xoa thanh cong mon hoc co MaMH = " << mamh << endl;
		WriteSubject("subject.txt"); // Cập nhật lại dữ liệu trong file txt
		RemoveResultBySubject(mamh);
	}
	else {
		cout << "Khong tim thay mon hoc co MaMH = " << mamh << endl;
		RemoveSubject();
	}
}

void QuanLy::RemoveResult(string masv, string mamh) {
	if (masv == "") {
		cout << "Nhap ma SV can xoa ket qua: ";
		fflush(stdin);
		cin >> masv;
	}
	if (mamh == "") {
		cout << "Nhap ma MH can xoa ket qua: ";
		fflush(stdin);
		cin >> mamh;
	}
	int pos = FindResult(masv, mamh);
	if (pos >= 0) {
		for (int j = pos; j < soKQ - 1; j++) {
			kq[j] = kq[j + 1];
		}
		soKQ--;
		cout << "Xoa thanh cong!" << endl;
		WriteResult("result.txt"); // Cập nhật lại dữ liệu vào file txt
	}
	else {
		cout << "Khong tim thay ket qua co MaSV = " << masv << ", MaMH = " << mamh << endl;
		RemoveResult();
	}
}

void QuanLy::RemoveResultByStudent(string masv) {
	int count = 0;
	int i = 0;
	while (i < soKQ) {
		if (kq[i].GetMaSV() == masv) {
			int pos = FindResult(masv, kq[i].GetMaMH());
			if (pos >= 0) {
				for (int j = pos; j < soKQ - 1; j++) {
					kq[j] = kq[j + 1];
				}
				soKQ--;
			}
			i--;
			count++;
		}
		i++;
	}
	if (count > 0)
	{
		cout << "Xoa thanh cong " << count << " ket qua co MaSV = " << masv << endl;
		WriteResult("result.txt"); // Cập nhật lại dữ liệu vào file txt
	}
}

void QuanLy::RemoveResultBySubject(string mamh) {
	int count = 0;
	int i = 0;
	while (i < soKQ) {
		if (kq[i].GetMaMH() == mamh) {
			int pos = FindResult(kq[i].GetMaSV(), mamh);
			if (pos >= 0) {
				for (int j = pos; j < soKQ - 1; j++) {
					kq[j] = kq[j + 1];
				}
				soKQ--;
			}
			i--;
			count++;
		}
		i++;
	}
	if (count > 0)
	{
		cout << "Xoa thanh cong " << count << " ket qua co MaMH = " << mamh << endl;
		WriteResult("result.txt"); // Cập nhật lại dữ liệu vào file txt
	}
}

void QuanLy::SearchStudent() {
	string masv;
	cout << "Nhap MaSV can tim: ";
	fflush(stdin);
	cin >> masv;
	int sv_index = FindStudent(masv);
	if (sv_index >= 0) {
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << right << setw(8) << "Ma SV" << " | ";
		cout << left << setw(30) << "Ho ten" << " | ";
		cout << right << setw(10) << "Ngay sinh" << " | ";
		cout << right << setw(3) << "GT" << " | ";
		cout << left << "Lop QL" << " | ";
		cout << setw(4) << "DTB" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
		sv[sv_index].Display();
		cout << "-----------------------------------------------------------------------------" << endl;
	}
	else cout << "Khong tim thay sinh vien co MaSV = " << masv << endl;
}

void QuanLy::SearchSubject() {
	string mamh;
	cout << "Nhap MaMH can tim: ";
	fflush(stdin);
	cin >> mamh;
	int mh_index = FindSubject(mamh);
	if (mh_index >= 0) {
		cout << "----------------------------------------------------------------------" << endl;
		cout << right << setw(8) << "Ma MH" << " | ";
		cout << left << setw(50) << "Ten MH" << " | ";
		cout << "So TC" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		mh[mh_index].Display();
		cout << "----------------------------------------------------------------------" << endl;
	}
	else cout << "Khong tim thay mon hoc co MaMH = " << mamh << endl;
}

void QuanLy::SearchResult() {
	string mamh;
	cout << "Nhap MaMH can tim: ";
	fflush(stdin);
	cin >> mamh;
	string masv;
	cout << "Nhap MaSV can tim: ";
	fflush(stdin);
	cin >> masv;
	int kq_index = FindResult(masv, mamh);
	if (kq_index >= 0) {
		cout << "-----------------------------------------" << endl;
		cout << setw(8) << "Ma MH" << " | ";
		cout << setw(8) << "Ma SV" << " | ";
		cout << setw(4) << "DQT" << " | ";
		cout << setw(4) << "DKT" << " | ";
		cout << setw(4) << "DTB" << endl;
		cout << "-----------------------------------------" << endl;
		kq[kq_index].Display();
		cout << "-----------------------------------------" << endl;
	}
	else cout << "Khong tim thay ket qua co MaMH = " << mamh << ", MaSV = " << masv << endl;
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

void QuanLy::CalGPA(string masv) {
	if (masv == "") {
		for (int i = 0; i < soSV; i++) {
			CalGPA(sv[i].GetMaSV());
		}
	}
	else {
		int sv_index = FindStudent(masv);
		if (sv_index == -1) {
			cout << "Khong tim thay sv co MaSV = " << masv << endl;
		}
		else {
			float tong = 0;
			int tongTC = 0;
			for (int i = 0; i < soKQ; i++) {
				if (kq[i].GetMaSV() == masv) {
					int mh_index = FindSubject(kq[i].GetMaMH());
					int SoTC = mh[mh_index].GetSoTC();
					tong += kq[i].CalAvg()*SoTC;
					tongTC += SoTC;
				}
			}
			if (tong > 0) tong /= tongTC;
			sv[sv_index].SetGPA(tong);
		}
	}
}