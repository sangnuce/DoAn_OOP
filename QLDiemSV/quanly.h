#ifndef _QUANLY_H_
#define _QUANLY_H_

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
		void ReadStudent(std::string);
		void ReadSubject(std::string);
		void ReadResult(std::string);
		void PrintStudent();
		void PrintSubject();
		void PrintResult();
		void WriteStudent(std::string);
		void WriteSubject(std::string);
		void WriteResult(std::string);
		void AddStudent();
		void AddSubject();
		void AddResult();
};

#endif