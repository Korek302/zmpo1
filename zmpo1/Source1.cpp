#include "Header.h"


CTable::CTable()
{
	s_name = "CTable";
	length = 10;
	table = new int[length];
	cout << "bezp: " << s_name << endl;

	for (int i = 0; i < length; i++)
	{
		table[i] = 0;
	}
}

CTable::CTable(string sName)
{
	s_name = sName;
	length = 10;
	table = new int[length];
	cout << "parametr: " << s_name << endl;

	for (int i = 0; i < length; i++)
	{
		table[i] = 0;
	}
}

CTable::CTable(CTable &pcOther)
{
	s_name = pcOther.s_name + "_copy";
	length = pcOther.length;
	table = new int[length];
	for (int i = 0; i < length; i++)
	{
		table[i] = pcOther.getValue(i, 0);
	}
	cout << "kopiuj: " << s_name << endl;

	for (int i = 0; i < length; i++)
	{
		table[i] = 0;
	}
}

CTable::~CTable()
{
	cout << "usuwam: " << s_name << endl;
}

void CTable::vSetName(string sName)
{
	s_name = sName;
}

bool CTable::tableLengthChange(int length)
{
	if (length > 0)
	{
		table = (int*)realloc(table, length*sizeof(int));
		this->length = length;
		/*int* temp = new int[length];
		for (int i = 0; i < length; i++)
		{
		temp[i] = table[i];
		}
		table = temp;*/

		return true;
	}
	else
		return false;
}

bool CTable::setValue(int value, int pocket)
{
	if (pocket < length && pocket > 0)
	{
		table[pocket] = value;
		return true;
	}
	else
		return false;
}

int CTable::getValue(int pocket, int success)
{
	if (pocket < length && pocket > 0)
	{
		success = 1;
		return table[pocket];
	}
	else
	{
		success = -1;
		return -1;
	}
}

int* CTable::clone()
{
	int* out = new int[length];
	for (int i = 0; i < length; i++)
	{
		out[i] = table[i];
	}
	return out;
}

void CTable::passTable(CTable &B)
{
	B.tableLengthChange(length);
	for (int i = 0; i < length; i++)
	{
		B.table[i] = table[i];
	}
}

string CTable::toString()
{
	string temp = s_name + "\nlen: " + intToStr(length) + "\nvalues: ";

	for (int i = 0; i < length; i++)
	{
		if (i < length - 1)
			temp += intToStr(table[i]) + ", ";
		else
			temp += intToStr(table[i]);
	}
	temp += "\n";
	return temp;
}

string intToStr(int n)
{
	string tmp;
	if (n < 0) {
		tmp = "-";
		n = -n;
	}
	if (n > 9)
		tmp += intToStr(n / 10);
	tmp += n % 10 + 48;
	return tmp;
}