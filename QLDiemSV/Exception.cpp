#include <iostream>
#include <string>
#include "Exception.h"

using namespace std;

Exception::Exception(string msg)
{
	this->msg = msg;
}

ExFileNotFound::ExFileNotFound(string msg)
{
	this->msg = msg;
}

string ExFileNotFound::ToString()
{
	return ("ExFileNotFound Exception: " + msg);
}

ExReadFileError::ExReadFileError(string msg)
{
	this->msg = msg;
}

string ExReadFileError::ToString()
{
	return ("ExReadFileError Exception: " + msg);
}