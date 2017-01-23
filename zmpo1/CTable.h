#include <string>
#include <iostream>
#include <sstream>
#include "Osoba.h"

using namespace std;

template<class T>
class CTable
{
public:
	CTable();
	CTable(string sName, int iLen);
	CTable(const CTable<T> &pcOther);
	~CTable();
	int iGetLength();
	void vSetName(string sName);
	bool bSetTableLength(int length);
	bool bSetValue(T value, int pocket);
	T iGetValue(int pocket, int success);
	CTable<T> Clone();
	void vCopyTable(CTable table);
	string sToString();
	//CTable &operator = (const CTable &C1);
private:
	int i_length;
	string s_name;
	T* pi_table;
};

string sIntToStr(int n);