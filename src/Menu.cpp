/*
 * Menu.cpp
 *
 *  Created on: May 22, 2016
 *      Author: raydelto
 */

#include "Menu.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

List mylist;

Menu::Menu()
{
	ifstream lec("mycontacts");
	if(lec.is_open())
	{
		string temp;
		while (getline(lec, temp))
			if(temp != "")
				mylist.add(temp);
		lec.close();
	}
}

void Menu::clearScreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void Menu::pause()
{
	#ifdef _WIN32
	system("pause");
	#else
	system("read -n1 -r -p \"Press any key to continue...\" key");
	#endif
}


bool Menu::validate(int option)
{
	if(option >= 1 && option <= 5)
	{
		return true;
	}else
	{
		cout << "Please pick an option between 1 and 5"<< endl;
		pause();
		return false;
	}
}

void Menu::routeAction(int option)
{
	switch(option)
	{
	case 1:
		listContacts();
		break;
	case 2:
		addContacts();
		break;
	case 3:
		removeContacts();
		break;
	case 4:
		modifyContacts();
		break;

	case 5:
		cout << "Thanks for using our software, good bye!" << endl;
	}
	pause();
}

void Menu::listContacts()
{
	mylist.listall();
	cout << endl;
}

void Menu::addContacts()
{
	string resp = "";

	while(resp == "")
	{
		cout << "Input the contact's name: ";
		cin >> resp;
	}

	mylist.add(resp);

	cout << "Added!" << endl;
}

void Menu::removeContacts()
{
	int resp = 0;

	while(resp == 0)
	{
		cout << "Input the position of the element to remove: ";
		cin >> resp;
	}

	mylist.remove(resp-1);
}

void Menu::modifyContacts()
{
	if(mylist._count == 0)
	{
		cout << "The list is empty!" << endl;
		return;
	}

	int inx = 0;

	while(inx == 0)
	{
		cout << "Input the position of the element to modify: ";
		cin >> inx;

		if(inx < 0)
		{
			cout << "* The position must be positive! *" << endl;
			inx = 0;
		}
		else if(inx > mylist._count)
		{
			cout << "* Position out of bounds! *" << endl;
			inx = 0;
		}
	}

	string name = "";

	while(name == "")
	{
		cout << "Input the new name: ";
		cin >> name;
	}

	mylist.modify(inx-1, name);
}

void Menu::show()
{
	int option;
	do
	{
		clearScreen();
		cout << "ITLA Phonebook" << endl;
		cout << "1- List contacts" << endl;
		cout << "2- Add contacts" << endl;
		cout << "3- Remove contact" << endl;
		cout << "4- Modify contact" << endl;
		cout << "5- Exit" << endl;
		cout << "Select an option => ";
		cin >> option;
		if(validate(option))
		{
			routeAction(option);
		}
	}while(option !=5);
}
