/*
 * List.h
 *
 *  Created on: May 22, 2016
 *      Author: raydelto
 */

#ifndef LIST_H_
#define LIST_H_
#include "Element.h"
#include "PersistenceManager.h"
class List
{
	public:
		List();
		void add(std::string);//(Element* element);
		void remove(int index);
		void modify(int index, std::string name);
		void listall();
		int _count;
		virtual ~List();
	private:
		Element* _first;
		Element* _last;
};

#endif /* LIST_H_ */
