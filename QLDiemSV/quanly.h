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
		std::vector<std::vector<std::string>> ReadFile(std::string) throw(ExFileNotFound);
		void Init();
		void ClearFile(std::string);
		void ReadStudent(std::string) throw(ExReadFileError);
		void ReadSubject(std::string) throw(ExReadFileError);
		void ReadResult(std::string) throw(ExReadFileError);
		void PrintStudent();
		void PrintSubject();
		void PrintResult();
		int FindStudent(std::string = "");
		int FindSubject(std::string = "");
		int FindResult(std::string = "", std::string = "");
		void AddStudent();
		void AddSubject();
		void AddResult();
		void AddResultByStudent();
		void AddResultBySubject();
		void EditStudent();
		void EditSubject();
		void EditResult();
		void EditResultStudentID(std::string oldID, std::string newID);
		void EditResultSubjectID(std::string oldID, std::string newID);
		void RemoveStudent(std::string = "");
		void RemoveSubject(std::string = "");
		void RemoveResult(std::string = "", std::string = "");
		void RemoveResultByStudent(std::string = "");
		void RemoveResultBySubject(std::string = "");
		void SearchStudent();
		void SearchSubject();
		void SearchResult();
		void WriteStudent(std::string);
		void WriteSubject(std::string);
		void WriteResult(std::string);
		void CalGPA(std::string = "");

};

#endif