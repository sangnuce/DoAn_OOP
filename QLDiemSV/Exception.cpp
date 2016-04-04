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