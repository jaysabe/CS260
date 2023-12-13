#include <iostream>
#include "personmgr.h"
using namespace std;

void PersonMgr::addPerson(const Person& aPerson){
	hashtable.insert(aPerson);
}
void PersonMgr::removePerson(const char * personId){
	hashtable.remove(personId);
}

Person * PersonMgr::findPerson(const char * personId){
	return hashtable.locate(personId);
}

