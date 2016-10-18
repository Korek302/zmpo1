#include "CTable.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string s_choice;
	bool b_isCreated = false;
	vector<CTable*> v_tableVector;



	/*CTable* temp0 = new CTable();
	v_tableVector.push_back(temp0);

	(*v_tableVector[0]).vSetName("tab1");

	CTable* temp1 = new CTable(*v_tableVector[0]);
	v_tableVector.push_back(temp1);

	v_tableVector.push_back(new CTable("tab3", 7));

	(*v_tableVector[2]).bSetValue(4, 2);

	(*v_tableVector[0]).bSetValue(5, 2);

	(*v_tableVector[1]).iGetValue(2, 0);

	(*v_tableVector[1]).iGetValue(2, 0);

	(*v_tableVector[0]).iGetValue(2, 0);

	(*v_tableVector[2]).iGetValue(2, 0);

	(*v_tableVector[0]).iGetValue(0, 0);

	(*v_tableVector[0]).bSetTableLength(10);

	v_tableVector.erase(v_tableVector.begin() + 0);*/




	cout << "1. Create any number of CTable objects" << endl
		<< "2. Define table length for one of the created CTable object" << endl
		<< "3. Delete one of the objects" << endl
		<< "4. Delete all objects" << endl
		<< "5. Rename one of the objects" << endl
		<< "6. Clone one of the objects" << endl
		<< "7. Print one of the objects" << endl
		<< "8. Set one of the values of one of the pockets of one of the objects" << endl
		<< "9. Print all objects" << endl
		<< "0. Create object using parameter constructor" << endl
		<< "e to exit" << endl
		<< "pressing any other button will clear the vector" << endl;

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
			int quantity;
			cout << "How many objects?" << endl;
			cin >> quantity;
			for (int i = 0; i < quantity; i++)
			{
				CTable* temp = new CTable();
				v_tableVector.push_back(temp);
			}
			cout << v_tableVector.size() << " objects created" << endl;
			b_isCreated = true;
		}break;

		case '2':
		{
			if (!b_isCreated)
				cout << "None object created" << endl;
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
					(*v_tableVector[objectNumber]).bSetTableLength(newLength);
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
				cout << "None object created" << endl;
			else
			{
				v_tableVector.clear();
				cout << "All objects deleted" << endl;
			}
		}break;

		case '5':
		{
			if (!b_isCreated)
				cout << "None object created" << endl;
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
					(*v_tableVector[objectNumber]).vSetName(newName);
					cout << "Object " << objectNumber << " is now named " << newName << endl;
				}
			}
		}break;

		case '6':
		{
			if (!b_isCreated)
				cout << "None object created" << endl;
			else
			{
				int objectNumber;
				cout << "Which object?" << endl;
				cin >> objectNumber;
				if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
					cout << "Wrong number" << endl;
				else
				{
					CTable* temp = new CTable(*v_tableVector[objectNumber]);
					v_tableVector.push_back(temp);
					cout << "Object " << objectNumber << " has been cloned" << endl;
				}
			}
		}break;

		case '7':
		{
			if (!b_isCreated)
				cout << "None object created" << endl;
			else
			{
				int objectNumber;
				cout << "Which object?" << endl;
				cin >> objectNumber;
				if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
					cout << "Wrong number" << endl;
				else
				{
					cout << (*v_tableVector[objectNumber]).sToString() << endl;
				}
			}
		}break;

		case '8':
		{
			if (!b_isCreated)
				cout << "None object created" << endl;
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
					if (pocket > (*v_tableVector[objectNumber]).iGetLength() || pocket < 0)
						cout << "Wrong number of pocket" << endl;
					else
					{
						cout << "Submit new value" << endl;
						cin >> newValue;
						(*v_tableVector[objectNumber]).bSetValue(newValue, pocket);
						cout << "Object " << objectNumber << ", pocket " << pocket << ", new value " << newValue << endl;
					}
				}
			}
		}break;

		case '9':
		{
			if (!b_isCreated)
				cout << "None object created" << endl;
			else
			{
				for(int i = 0; i < v_tableVector.size(); i++)
					cout << (*v_tableVector[i]).sToString() << endl;
			}
		}break;

		case '0':
		{
			string name;
			int length;
			cout << "Submit object name" << endl;
			cin >> name;
			cout << "Submit object length" << endl;
			cin >> length;
			v_tableVector.push_back(new CTable(name, length));
			cout << "Object " << name << " created" << endl;
			b_isCreated = true;
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

	} while (s_choice[0] != 'e');


	getchar();
	return 0;
}