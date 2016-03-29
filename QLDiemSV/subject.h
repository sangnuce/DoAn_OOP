#pragma once

#include <string>

class Subject {
private:
	std::string MaMH;
	std::string TenMH;
	std::string NhomMH;
	std::string HocKy;
	int SoTC;
public:
	Subject();
	Subject(Subject&);
	Subject(std::string, std::string, std::string, std::string, int);
	void Read();
	void Display();
};