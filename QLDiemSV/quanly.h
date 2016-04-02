#ifndef _QUANLY_H_
#define _QUANLY_H_

#include <iostream>
#include <vector>
#include <string>
#include "student.h"
#include "subject.h"
#include "result.h"

class QuanLy {
	private:
		int soSV, soMH, soKQ;
		Student* sv;
		Subject* mh;
		Result* kq;
	public:
		QuanLy();
		~QuanLy();
		std::vector<std::vector<std::string>> ReadFile(std::string);
		void ClearFile(std::string);
		void ReadStudent();
		void ReadSubject();
		void ReadResult();
		void PrintStudent();
		void PrintSubject();
		void PrintResult();
		void WriteStudent();
		void WriteSubject();
		void WriteResult();
		void AddStudent();
		void AddSubject();
		void AddResult();
};

#endif