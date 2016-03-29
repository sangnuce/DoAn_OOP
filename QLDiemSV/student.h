#pragma once

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
	void Read();
	void Display();
};