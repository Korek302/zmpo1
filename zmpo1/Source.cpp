#include "Header.h"
#include <iostream>

int main()
{
	CTable test;

	cout << test.toString();

	test.tableLengthChange(5);

	cout << test.toString();

	system("PAUSE");
	return 0;
}