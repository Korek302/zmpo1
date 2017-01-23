#include "CTable.h"
#include "WrongIndexException.h"
#include "NoneObjectsCreatedException.h"
#include <iostream>
#include <vector>

using namespace std;

#define DEFAULT_TYPE Osoba

int main()
{
	string s_choice;
	bool b_isCreated = false;
	vector<CTable<DEFAULT_TYPE>*> v_tableVector;

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
					CTable<DEFAULT_TYPE>* temp = new CTable<DEFAULT_TYPE>();
					v_tableVector.push_back(temp);
				}
				cout << v_tableVector.size() << " objects created" << endl;
				b_isCreated = true;
			}break;

			case '2':
			{
				try
				{
					if (!b_isCreated)
						throw NoneObjectsCreatedException();//cout << "None object created" << endl;
					else
					{
						try
						{
							int objectNumber;
							int newLength;
							cout << "Which object?" << endl;
							cin >> objectNumber;
							if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
								throw WrongIndexException();//cout << "Wrong number" << endl;
							else
							{
								cout << "What length?" << endl;
								cin >> newLength;
								(*v_tableVector[objectNumber]).bSetTableLength(newLength);
								cout << "Object " << objectNumber << ", new length: " << newLength << endl;
							}
						}
						catch (WrongIndexException error)
						{
							cout << error.sGetError();
						}
					}
				}
				catch (NoneObjectsCreatedException error)
				{
					cout << error.sGetError();
				}
			}break;

			case '3':
			{
				try
				{
					if (!b_isCreated)
						throw NoneObjectsCreatedException();//cout << "None object created" << endl;
					else
					{
						try
						{
							int objectNumber;
							cout << "Which object?" << endl;
							cin >> objectNumber;
							if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
								throw WrongIndexException();//cout << "Wrong number" << endl;
							else
							{
								delete v_tableVector[objectNumber];
								v_tableVector.erase(v_tableVector.begin() + objectNumber);
								cout << "Object " << objectNumber << " deleted" << endl;
							}
						}
						catch (WrongIndexException error)
						{
							cout << error.sGetError();
						}
					}
				}
				catch (NoneObjectsCreatedException error)
				{
					cout << error.sGetError();
				}
			}break;

			case '4':
			{
				try
				{
					if (!b_isCreated)
						throw NoneObjectsCreatedException();//cout << "None object created" << endl;
					else
					{
						for (int ii = 0; ii < v_tableVector.size(); ii++)
						{
							delete v_tableVector[ii];
						}
						v_tableVector.clear();
						cout << "All objects deleted" << endl;
					}
				}
				catch (NoneObjectsCreatedException error)
				{
					cout << error.sGetError();
				}
			}break;

			case '5':
			{
				try
				{
					if (!b_isCreated)
						throw NoneObjectsCreatedException();//cout << "None object created" << endl;
					else
					{
						try
						{
							int objectNumber;
							cout << "Which object?" << endl;
							cin >> objectNumber;
							if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
								throw WrongIndexException();//cout << "Wrong number" << endl;
							else
							{
								string newName;
								cout << "Submit new name" << endl;
								cin >> newName;
								(*v_tableVector[objectNumber]).vSetName(newName);
								cout << "Object " << objectNumber << " is now named " << newName << endl;
							}
						}
						catch (WrongIndexException error)
						{
							cout << error.sGetError();
						}
					}
				}
				catch (NoneObjectsCreatedException error)
				{
					cout << error.sGetError();
				}
			}break;

			case '6':
			{
				try
				{
					if (!b_isCreated)
						throw NoneObjectsCreatedException();//cout << "None object created" << endl;
					else
					{
						try
						{
							int objectNumber;
							cout << "Which object?" << endl;
							cin >> objectNumber;
							if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
								throw WrongIndexException();//cout << "Wrong number" << endl;
							else
							{
								CTable<DEFAULT_TYPE>* temp = new CTable<DEFAULT_TYPE>(*v_tableVector[objectNumber]);
								v_tableVector.push_back(temp);
								cout << "Object " << objectNumber << " has been cloned" << endl;
							}
						}
						catch (WrongIndexException error)
						{
							cout << error.sGetError();
						}
					}
				}
				catch (NoneObjectsCreatedException error)
				{
					cout << error.sGetError();
				}
			}break;

			case '7':
			{
				try
				{
					if (!b_isCreated)
						throw NoneObjectsCreatedException();//cout << "None object created" << endl;
					else
					{
						try
						{
							int objectNumber;
							cout << "Which object?" << endl;
							cin >> objectNumber;
							if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
								throw WrongIndexException();//cout << "Wrong number" << endl;
							else
							{
								cout << (*v_tableVector[objectNumber]).sToString() << endl;
							}
						}
						catch (WrongIndexException error)
						{
							cout << error.sGetError();
						}
					}
				}
				catch (NoneObjectsCreatedException error)
				{
					cout << error.sGetError();
				}
			}break;

			case '8':
			{
				try
				{
					if (!b_isCreated)
						throw NoneObjectsCreatedException();//cout << "None object created" << endl;
					else
					{
						try
						{
							int objectNumber;
							int pocket;
							DEFAULT_TYPE newValue;
							cout << "Which object?" << endl;
							cin >> objectNumber;
							if (objectNumber > v_tableVector.size() - 1 || objectNumber < 0)
								throw WrongIndexException();//cout << "Wrong number" << endl;
							else
							{
								cout << "Which pocket?" << endl;
								cin >> pocket;
								if (pocket > (*v_tableVector[objectNumber]).iGetLength() || pocket < 0)
									throw WrongIndexException();//cout << "Wrong number of pocket" << endl;
								else
								{
									cout << "Submit new value" << endl;
									cin >> newValue;
									(*v_tableVector[objectNumber]).bSetValue(newValue, pocket);
									cout << "Object " << objectNumber << ", pocket " << pocket << ", new value " << newValue << endl;
								}
							}
						}
						catch (WrongIndexException error)
						{
							cout << error.sGetError();
						}
					}
				}
				catch (NoneObjectsCreatedException error)
				{
					cout << error.sGetError();
				}
			}break;

			case '9':
			{
				try
				{
					if (!b_isCreated)
						throw NoneObjectsCreatedException();//cout << "None object created" << endl;
					else
					{
						for (int i = 0; i < v_tableVector.size(); i++)
							cout << (*v_tableVector[i]).sToString() << endl;
					}
				}
				catch (NoneObjectsCreatedException error)
				{
					cout << error.sGetError();
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
				v_tableVector.push_back(new CTable<DEFAULT_TYPE>(name, length));
				cout << "Object " << name << " created" << endl;
				b_isCreated = true;
			}break;

			case 'e':
			{
				for (int ii = 0; ii < v_tableVector.size(); ii++)
				{
					delete v_tableVector[ii];
				}
				s_choice[0] = 'x';
				b_isCreated = false;
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

	} while (s_choice[0] != 'x');


	getchar();
	return 0;
}