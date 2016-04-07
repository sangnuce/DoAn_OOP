#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>

class Student {
private:
	std::string MaSV;
	std::string HoTen;
	std::string NgaySinh;
	std::string GioiTinh;
	std::string LopQL;
public:
	Student();
	Student(Student&);
	Student(std::string, std::string, std::string, std::string, std::string);
	std::string GetMaSV();
	void Read();
	void Display();
	void WriteFile(std::string);
};

#endif