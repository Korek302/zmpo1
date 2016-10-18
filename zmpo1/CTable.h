#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class CTable
{
private:
	int i_length;
	string s_name;
	int* pi_table;
public:
	CTable();
	CTable(string sName);
	CTable(string table, int length, int* tab);
	CTable(const CTable &pcOther);
	~CTable();
	int iGetLength();
	void vSetName(string sName);
	bool bSetTableLength(int length);
	bool bSetValue(int value, int pocket);
	int iGetValue(int pocket, int success);
	CTable Clone();
	void vCopyTable(CTable table);
	string sToString();
	//CTable &operator = (const CTable &C1);
};

string sIntToStr(int n);