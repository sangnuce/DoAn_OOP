#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <string>

class Exception
{
private:
	std::string msg;
public:
	Exception();
	Exception(std::string m);
	std::string ToString();
};

#endif