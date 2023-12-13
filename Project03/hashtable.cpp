#include "hashtable.h"
#include <iostream>
#include <cstring>
using namespace std;

HashTable::HashTable(): arraySize(9973){
	llArray = new LinkedList[arraySize];
}


int HashTable:: hash(const char *  personId)const {
	size_t hashVal = 0;
	size_t prime = 31;
	while(*personId){
		hashVal = (hashVal * prime) ^ (*personId++);
	
	}
	return static_cast<int>(hashVal % arraySize);
}


HashTable::~HashTable(){
	delete[] llArray;
	llArray = nullptr;
}



void HashTable::insert(const Person& aPerson) {
	int index = 0;
	index = hash(aPerson.getPersonId());
	llArray[index].add(aPerson);
}

void HashTable::remove(const char * personId){
	int index = hash(personId);
	llArray[index].remove(personId);
}

Person * HashTable::locate(const char * personId){
	int index = hash(personId);
	return llArray[index].find(personId);
}


