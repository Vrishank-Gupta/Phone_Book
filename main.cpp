#include <iostream>
#include <cstring>
#include <conio.h>
#include "hashmap.h"
using namespace std;

int main()
{
	char name[20],n1[]={"Niketan"},n2[]={"Rohan"},n3[]={"Vrishank"},n4[]={"Shivam"};
	long int number;
	Hashmap<long int> m;
	m.insert(n1,844735651);
	m.insert(n2,837698841);
	m.insert(n3,913666642);
	m.insert(n4,880097704);
	cout<<"************************************************ TELEPHONE DIRECTORY ************************************************";
	cout<<endl;
	while(1)
	{
		cout << "\n\t\t\t\t\t\t\t  Menu ";
		cout << "\n1.Search through contacts\n2.Add new Contact\n3.Update a contact\n4.Exit\nEnter your choice:- ";
		int ch;
		cin >> ch;
		cout << endl;
		switch(ch)
		{
			case(1):
			{
				cout << "1.Search by name\n2.Search by number\nEnter your Choice:- ";
				int sub;
				cin >> sub;
				switch(sub)
				{
					case(1):
					{
						cout << "Enter Name to search :- ";
						fflush(stdin);
						cin >> name;
						int number = m.findNumber(name);
						if (number == 0)
							{
								cout << "\nNot Found";
								break;
							}
							else
							{
								cout << "\nNumber:- ";
								cout << number;
							}
						break;
					}
	
					case(2):
					{
						cout << "Enter Number:- ";
						cin >>  number;
						if (m.findName(number) != '\0')
						{
							cout << endl << "Name is :- ";
							strcpy(name,m.findName(number));
							cout << name;
						}
						else
							cout << "\nNot Found!";
						break;
					}
					default:
					{
						cout << "Wrong choice";
						break;
					}
				}
				break;
			}
	
			case(2):
			{
				fflush(stdin);			
				cout << "Enter The Name:- ";
				cin.getline(name,55);			
				cout << "Enter Contact number :- ";
				cin >> number;
				m.insert(name,number);
				cout << "\nAdded Successfully!!";
				break;
			}
	
			case(3):
			{
				fflush(stdin);
				cout << "\nEnter Name of the Contact to be updated:- ";
				cin >> name;
				number = m.findNumber(name);
				m.update(name);
				cout << "\nUpdated Successfully!!";
				break;
			}

			case(4):
				return 0;

			default:
			{
				cout << "\n Wrong Choice!";
				break;
			}
		}
	}
}