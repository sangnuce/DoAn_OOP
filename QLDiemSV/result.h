#ifndef _RESULT_H_
#define _RESULT_H_

#include <string>

class Result {
private:
	std::string MaMH;
	std::string MaSV;
	float DQT;
	float DKT;
public:
	Result(Result&);
	Result(std::string mamh = "", std::string masv = "", float dqt = 0, float dkt = 0);
	std::string GetMaMH();
	std::string GetMaSV();
	float CalAvg();
	void Read();
	void Display();
	void WriteFile(std::string);
};

#endif