#include "CTable.h"

#define DEFAULT_NAME "default CTable"
#define DEFAULT_SIZE 10

CTable::CTable()
{
	s_name = DEFAULT_NAME;
	i_length = DEFAULT_SIZE;
	pi_table = new int[i_length];
	cout << "bezp: " << s_name << endl;

	for (int i = 0; i < i_length; i++)
	{
		pi_table[i] = 0;
	}
}

CTable::CTable(string sName)
{
	s_name = sName;
	i_length = DEFAULT_SIZE;
	pi_table = new int[i_length];
	cout << "parametr: " << s_name << endl;

	for (int i = 0; i < i_length; i++)
	{
		pi_table[i] = 0;
	}
}

CTable::CTable(string name, int len, int* tab)
{
	s_name = name + "_copy";
	i_length = len;
	pi_table = new int[i_length];
	for (int i = 0; i < i_length; i++)
	{
		pi_table[i] = tab[i];
	}
}

CTable::CTable(const CTable &pcOther)
{
	//passTable(pcOther);
	s_name = pcOther.s_name + "_copy";
	i_length = pcOther.i_length;
	pi_table = new int[i_length];
	for (int i = 0; i < i_length; i++)
	{
		pi_table[i] = pcOther.pi_table[i];
	}

	cout << "kopiuj: " << s_name << endl;
}

CTable::~CTable()
{
	cout << "usuwam: " << s_name << endl;
}

void CTable::vSetName(string sName)
{
	s_name = sName;
}


int CTable::iGetLength()
{
	return i_length;
}

bool CTable::bSetTableLength(int length)
{
	if (length > 0)
	{
		//pi_table = (int*)realloc(table, length*sizeof(int));

		int* temp = new int[length];
		for (int i = 0; i < length; i++)
		{
			temp[i] = pi_table[i];
		}
		pi_table = temp;
		i_length = length;

		return true;
	}
	else
		return false;
}

bool CTable::bSetValue(int value, int pocket)
{
	if (pocket < i_length && pocket > -1)
	{
		pi_table[pocket] = value;
		return true;
	}
	else
		return false;
}

int CTable::iGetValue(int pocket, int success)
{
	if (pocket < i_length && pocket > 0)
	{
		success = 1;
		return pi_table[pocket];
	}
	else
	{
		success = -1;
		return -1;
	}
}

CTable CTable::Clone()
{
	return CTable(*this);
}

void CTable::vCopyTable(CTable table)
{
	bSetTableLength(i_length);
	for (int i = 0; i < i_length; i++)
	{
		pi_table[i] = table.pi_table[i];
	}
}

string CTable::sToString()
{
	string temp = s_name + "\nlen: " + sIntToStr(i_length) + "\nvalues: ";

	for (int i = 0; i < i_length; i++)
	{
		if (i < i_length - 1)
			temp += sIntToStr(pi_table[i]) + ", ";
		else
			temp += sIntToStr(pi_table[i]);
	}
	temp += "\n";
	return temp;
}

/*CTable & CTable::operator=(const CTable & C1)
{
	if (this == &C1)
	{
		return *this;
	}
	delete[] pi_table;
	i_length = C1.i_length;
	s_name = C1.s_name;
	pi_table = new int[i_length];
	for (int i = 0; i < i_length; ++i)
	{
		pi_table[i] = C1.pi_table[i];
	}
}*/

string sIntToStr(int n)
{
	string temp;
	if (n < 0)
	{
		temp = "-";
		n = -n;
	}
	if (n > 9)
		temp += sIntToStr(n / 10);
	temp += n % 10 + 48;
	return temp;
}