#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <string>

class Exception
{
protected:
	std::string msg;
public:
	Exception(std::string msg = "");
	virtual std::string ToString() = 0;
};

class ExFileNotFound :public Exception {
public:
	ExFileNotFound(std::string msg = "");
	virtual std::string ToString();
};

class ExReadFileError :public Exception {
public:
	ExReadFileError(std::string msg = "");
	virtual std::string ToString();
};

#endif