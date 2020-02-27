/*
 * List.cpp
 *
 *  Created on: May 22, 2016
 *      Author: raydelto
 */

#include "List.h"
#include <iostream>
#include <cstdlib>
using namespace std;

List::List(): _first(NULL), _last(NULL), _count(0)
{

}

void List::add(string name)//(Element* element)
{
	Element* element = new Element(name);

	if(!_last)
		_first = _last = element;
	else
		_last = _last->_next = element;

	_count++;
}

void List::remove(int index)
{
	if(_count == 0)
	{
		cout << "The list is empty!" << endl;
		return;
	}
	else if(index < 0)
	{
		cout << "The position must be positive!" << endl;
		return;
	}
	else if(index >= _count)
	{
		cout << "Position out of bounds!" << endl;
		return;
	}

	Element* before = NULL;
	Element* current = _first;
	Element* after = NULL;

	for(int x = 0; x < index; x++)
	{
		before = current;
		current = current->_next;
	}

	after = current->_next;

	if(before)
		before->_next = after;
	else
		_first = after;

	delete current;

	_count--;
}

void List::modify(int index, std::string name)
{
	Element* current = _first;

	for(int x = 0; x < index; x++)
		current = current->_next;

	current->_name = name;

	cout << "Modified!" << endl;
}

void List::listall()
{
	if(!_first)
	{
		cout << "The list is empty!" << endl;
		return;
	}

	Element current = *_first;

	for(int x = 0; x < _count; x++)
	{
		cout << x+1 << ") " << current._name << endl;
		if(current._next != NULL)
			current = *current._next;
	}
}

List::~List()
{
	string txt = "";

	Element current = *_first;

	for(int x = 0; x < _count; x++)
	{
		txt += current._name + "\n";
		if(current._next != NULL)
			current = *current._next;
	}

	PersistenceManager pm;
	pm.save(txt);

	while(_first)
		remove(0);

	cout << "* Done! *" << endl;
}
