/*
 * PersistenceManager.cpp
 *
 *  Created on: May 23, 2016
 *      Author: raydelto
 */
#include <iostream>
#include <fstream>
#include "PersistenceManager.h"

using namespace std;

PersistenceManager::PersistenceManager() {
	// TODO Auto-generated constructor stub

}

void PersistenceManager::save(string txt)
{
	ofstream esc;
	esc.open("mycontacts");
	esc << txt;
	esc.close();
}

/*std::string load()
{
	string txt = "";
	ifstream lec("mycontacts");
	if(lec.is_open())
	{
		string temp;
		while (getline(lec, temp))
			txt += temp + "\n";
		lec.close();
	}

	return txt;
}*/

