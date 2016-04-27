#include <iostream>
#include <string>
#include "Exception.h"

using namespace std;

Exception::Exception(string msg)
{
	this->msg = msg;
}

string Exception::ToString() {
	return msg;
}

ExFileNotFound::ExFileNotFound(string msg) : Exception(msg) {
}

string ExFileNotFound::ToString() {
	return ("ExFileNotFound Exception: " + msg);
}

ExReadFileError::ExReadFileError(string msg) : Exception(msg) {
}

string ExReadFileError::ToString() {
	return ("ExReadFileError Exception: " + msg);
}