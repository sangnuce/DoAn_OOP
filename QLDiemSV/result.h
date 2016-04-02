#ifndef _RESULT_H_
#define _RESULT_H_

#include <string>

class Result {
private:
	std::string HocKy;
	std::string MaMH;
	std::string MaSV;
	float DQT;
	float DKT;
public:
	Result();
	Result(Result&);
	Result(std::string, std::string, std::string, float, float);
	void Read();
	void Display();
	void WriteFile();
};

#endif