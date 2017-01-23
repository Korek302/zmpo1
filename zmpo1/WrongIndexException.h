#pragma once
#include <string>

using namespace std;

class WrongIndexException
{
public:
	string sGetError()
	{
		return("Wrong index number \n");
	};
};