#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "result.h"

class Student {
private:
	std::string MaSV;
	std::string HoTen;
	std::string NgaySinh;
	std::string GioiTinh;
	std::string LopQL;
	float GPA;
public:
	Student(Student&);
	Student(std::string masv = "", std::string hoten = "", std::string ngaysinh = "", std::string gioitinh = "", std::string lopql = "");
	std::string GetMaSV();
	void SetGPA(float);
	float GetGPA();
	void Read();
	void Display();
	void WriteFile(std::string);
};

#endif