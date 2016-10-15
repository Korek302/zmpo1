#include <string>
#include <iostream>
#include <sstream>

using namespace std;


string intToStr(int n);

class CTable
{
private:
	int length;
	string s_name;
	int* table;
public:
	CTable();
	CTable(string sName);
	CTable(CTable &pcOther);
	~CTable();
	void vSetName(string sName);
	bool tableLengthChange(int length);
	bool setValue(int value, int pocket);
	int getValue(int pocket, int success);
	int* clone();
	void passTable(CTable& B);
	string toString();
};