#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <string>

class Subject {
private:
	std::string MaMH;
	std::string TenMH;
	int SoTC;
public:
	Subject(Subject&);
	Subject(std::string mamh = "", std::string tenmh = "", int sotc = 0);
	std::string GetMaMH();
	int GetSoTC();
	void Read();
	void Display();
	void WriteFile(std::string);
};

#endif