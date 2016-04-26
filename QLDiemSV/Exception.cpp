#include <iostream>
#include <string>
#include "Exception.h"

using namespace std;

Exception::Exception()
{
	msg = "";
}

Exception::Exception(string m)
{
	msg = m;
}

string Exception::ToString() {
	return msg;
}

ExFileNotFound::ExFileNotFound() {
	msg = "";
}

ExFileNotFound::ExFileNotFound(string m) {
	msg = m;
}

ExReadFileError::ExReadFileError() {
	msg = "";
}

ExReadFileError::ExReadFileError(string m) {
	msg = m;
}

ExOutOfRange::ExOutOfRange() {
	msg = "";
}

ExOutOfRange::ExOutOfRange(string m) {
	msg = m;
}
