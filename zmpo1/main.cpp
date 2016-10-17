#include "CTable.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string s_choice;
	bool b_isCreated = false;
	vector<CTable> v_tableVector;

	cout << "1. Create any number of CTable objects" << endl
		<< "2. Define table length for one of the created CTable object" << endl
		<< "3. Delete one of the objects" << endl
		<< "4. Delete all objects" << endl
		<< "5. Rename one of the objects" << endl
		<< "6. Clone one of the objects" << endl
		<< "7. Print one of the objects" << endl
		<< "8. Set one of the values of one of the pockets of one of the objects" << endl;

	do
	{
		if (v_tableVector.size() == 0)
		{
			b_isCreated = false;
		}

		cin >> s_choice;

		switch (s_choice[0])
		{
		case '1':
		{
			if (!b_isCreated)
			{
				int quantity;
				cout << "How many objects?" << endl;
				cin >> quantity;
				//v_tableVector = new vector<CTable>(quantity);
				v_tableVector.resize(quantity);
				cout << v_tableVector.size() << " objects created" << endl;
				b_isCreated = true;
			}
			else
				cout << "Objects already created" << endl;
		}break;

		case '2':
		{
			if (!b_isCreated)
				cout << "None object created";
			else
			{
				int objectNumber;
				int newLength;
				cout << "Which object?" << endl;
				cin >> objectNumber;
				if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
					cout << "Wrong number" << endl;
				else
				{
					cout << "What length?" << endl;
					cin >> newLength;
					v_tableVector[objectNumber].bSetTableLength(newLength);
					cout << "Object " << objectNumber << ", new length: " << newLength << endl;
				}
			}
		}break;

		case '3':
		{
			if (!b_isCreated)
				cout << "None object created";
			else
			{
				int objectNumber;
				cout << "Which object?" << endl;
				cin >> objectNumber;
				if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
					cout << "Wrong number" << endl;
				else
				{
					v_tableVector.erase(v_tableVector.begin() + objectNumber);
					cout << "Object " << objectNumber << " deleted" << endl;
				}
			}
		}break;

		case '4':
		{
			if (!b_isCreated)
				cout << "None object created";
			else
			{
				v_tableVector.clear();
				cout << "All objects deleted" << endl;
			}
		}break;

		case '5':
		{
			if (!b_isCreated)
				cout << "None object created";
			else
			{
				int objectNumber;
				cout << "Which object?" << endl;
				cin >> objectNumber;
				if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
					cout << "Wrong number" << endl;
				else
				{
					string newName;
					cout << "Submit new name" << endl;
					cin >> newName;
					v_tableVector[objectNumber].vSetName(newName);
					cout << "Object " << objectNumber << " is now named " << newName << endl;
				}
			}
		}break;

		case '6':
		{
			if (!b_isCreated)
				cout << "None object created";
			else
			{
				int objectNumber;
				cout << "Which object?" << endl;
				cin >> objectNumber;
				if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
					cout << "Wrong number" << endl;
				else
				{
					CTable temp(v_tableVector[objectNumber]);
					v_tableVector.push_back(temp);
					cout << "Object " << objectNumber << " has been cloned" << endl;
				}
			}
		}break;

		case '7':
		{
			if (!b_isCreated)
				cout << "None object created";
			else
			{
				int objectNumber;
				cout << "Which object?" << endl;
				cin >> objectNumber;
				if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
					cout << "Wrong number" << endl;
				else
				{
					cout << v_tableVector[objectNumber].sToString() << endl;
				}
			}
		}break;

		case '8':
		{
			if (!b_isCreated)
				cout << "None object created";
			else
			{
				int objectNumber;
				int pocket;
				int newValue;
				cout << "Which object?" << endl;
				cin >> objectNumber;
				if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
					cout << "Wrong number" << endl;
				else
				{
					cout << "Which pocket?" << endl;
					cin >> pocket;
					if (pocket > v_tableVector[objectNumber].iGetLength() || pocket < 0)
						cout << "Wrong number of pocket" << endl;
					else
					{
						cout << "Submit new value" << endl;
						cin >> newValue;
						v_tableVector[objectNumber].bSetValue(newValue, pocket);
						cout << "Object " << objectNumber << ", pocket " << pocket << ", new value " << newValue << endl;
					}
				}
			}
		}break;

		default:
		{
			int i = 0;
			while (v_tableVector.size() != 0)
			{
				v_tableVector.erase(v_tableVector.begin());
				cout << "Object number " << i++ << " deleted" << endl;
			}
		}break;
		}

	} while (s_choice[0] != '0');


	getchar();
	return 0;
}