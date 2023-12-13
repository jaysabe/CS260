//defines hashtable class
#pragma once
#include "linkedlist.h"

class HashTable {
	private:
		LinkedList * llArray;
		int arraySize;

		//calc hash index
		int hash(const char *  personId)const;

	public:
		HashTable();
		HashTable(HashTable&) = delete;
		HashTable& operator=(HashTable&) = delete;
		~HashTable();
		
		void insert(const Person& aPerson);
		void remove(const char * personId);
		Person * locate(const char * personId);
};


