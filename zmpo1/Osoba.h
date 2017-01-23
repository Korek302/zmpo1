#pragma once
#include <string>

using namespace std;

class Osoba
{
public:
	Osoba();
	Osoba(string* sNewName, int iNewAge);
	~Osoba();
	int iGetAge();
	string sGetName();
	Osoba& operator=(Osoba& pcOther);
	friend ostream& operator<<(ostream &out, const Osoba &osoba);
	friend istream& operator>>(istream &in, Osoba &osoba);
private:
	int iAge;
	string* sName;
};