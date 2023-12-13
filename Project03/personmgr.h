// defines personmgr class
#pragma once
#include "hashtable.h"

class PersonMgr {
	private:
		HashTable hashtable;

	public:
		
		void addPerson(const Person& pers);
		void removePerson(const char *personId);
		Person * findPerson(const char *personId);
};
