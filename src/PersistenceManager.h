/*
 * PersistenceManager.h
 *
 *  Created on: May 23, 2016
 *      Author: raydelto
 */

#ifndef PERSISTENCEMANAGER_H_
#define PERSISTENCEMANAGER_H_

//TODO: Implement a persistence handler that allows data to remain permanently in the computer

class PersistenceManager
{
	public:
		PersistenceManager();
		void save(std::string);
		//std::string load();
};

#endif /* PERSISTENCEMANAGER_H_ */
