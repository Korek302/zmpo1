#include "CTable.h"

#define DEFAULT_NAME "default CTable"
#define DEFAULT_SIZE 5
#define DEFAULT_VALUE NULL

template<class T>
CTable<T>::CTable()
{
	s_name = DEFAULT_NAME;
	i_length = DEFAULT_SIZE;
	pi_table = new T[i_length];
	cout << "bezp: " << s_name << endl;

	/*for (int i = 0; i < i_length; i++)
	{
		pi_table[i] = DEFAULT_VALUE;
	}*/
}

template<class T>
CTable<T>::CTable(string sName, int iLen)
{
	s_name = sName;
	i_length = iLen;
	pi_table = new T[i_length];
	cout << "parametr: " << s_name << endl;

	/*for (int i = 0; i < i_length; i++)
	{
		pi_table[i] = DEFAULT_VALUE;
	}*/
}

template<class T>
CTable<T>::CTable(const CTable<T> &pcOther)
{
	s_name = pcOther.s_name + "_copy";
	i_length = pcOther.i_length;
	pi_table = new T[i_length];
	for (int i = 0; i < i_length; i++)
	{
		pi_table[i] = pcOther.pi_table[i];
	}

	cout << "kopiuj: " << s_name << endl;
}

template<class T>
CTable<T>::~CTable()
{
	delete[] pi_table;
	cout << "usuwam: " << s_name << endl;
}

template<class T>
void CTable<T>::vSetName(string sName)
{
	s_name = sName;
}

template<class T>
int CTable<T>::iGetLength()
{
	return i_length;
}

template<class T>
bool CTable<T>::bSetTableLength(int length)
{
	if (length > 0)
	{
		//pi_table = (int*)realloc(table, length*sizeof(int));

		T* temp = new T[length];

		if (length > i_length)
		{
			for (int i = 0; i < i_length; i++)
			{
				temp[i] = pi_table[i];
			}
			/*for (int i = i_length; i < length; i++)
			{
				temp[i] = DEFAULT_VALUE;
			}*/
		}
		else
		{ 
			for (int i = 0; i < length; i++)
			{
				temp[i] = pi_table[i];
			}
		}

		delete[] pi_table;
		pi_table = temp;
		i_length = length;

		return true;
	}
	else
		return false;
}

template<class T>
bool CTable<T>::bSetValue(T value, int pocket)
{
	if (pocket < i_length && pocket > -1)
	{
		pi_table[pocket] = value;
		return true;
	}
	else
		return false;
}

template<class T>
T CTable<T>::iGetValue(int pocket, int success)
{
	if (pocket < i_length && pocket > 0)
	{
		success = 1;
		return pi_table[pocket];
	}
	else
	{
		success = -1;
		return T();
	}
}

template<class T>
CTable<T> CTable<T>::Clone()
{
	return CTable(*this);
}

template<class T>
void CTable<T>::vCopyTable(CTable table)
{
	bSetTableLength(i_length);
	for (int i = 0; i < i_length; i++)
	{
		pi_table[i] = table.pi_table[i];
	}
}

template<class T>
string CTable<T>::sToString()
{
	string temp = s_name + "\nlen: " + sIntToStr(i_length) + "\nvalues: ";

	for (int i = 0; i < i_length; i++)
	{
		if (i < i_length - 1)
		{ 
			stringstream buffer;
			buffer << pi_table[i];
			temp += buffer.str() + ", ";
		}
		else
		{ 
			stringstream buffer;
			buffer << pi_table[i];
			temp += buffer.str();
		}
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

template class CTable<int>;
template class CTable<double>;
template class CTable<char>;
template class CTable<Osoba>;