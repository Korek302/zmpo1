#include <iostream>
#include <string>
#include "Osoba.h"

Osoba::Osoba()
{
	iAge = 0;
	sName = new string;
	*sName = "";
}

Osoba::Osoba(string* sNewName, int iNewAge)
{
	iAge = iNewAge;
	*sName = *sNewName;
}

Osoba::~Osoba()
{
	delete sName;
}

int Osoba::iGetAge()
{
	return iAge;
}

string Osoba::sGetName()
{
	return *sName;
}

ostream& operator<<(ostream &out, const Osoba &osoba)
{
	return out << "Person(Name: " << (*osoba.sName) << ", " << "Age: " << osoba.iAge << ")" << endl;
}

istream& operator>>(istream &in, Osoba &osoba)
{
	in >> (*osoba.sName) >> osoba.iAge;
	return in;
}

Osoba& Osoba::operator=(Osoba& pcOther)
{
	iAge = pcOther.iGetAge();
	*sName = pcOther.sGetName();
	return *this;
}