#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <string>

class Exception
{
protected:
	std::string msg;
public:
	Exception();
	Exception(std::string);
	std::string ToString();
};

class ExFileNotFound :public Exception {
public:
	ExFileNotFound();
	ExFileNotFound(std::string);
};

class ExReadFileError :public Exception {
public:
	ExReadFileError();
	ExReadFileError(std::string);
};
#endif