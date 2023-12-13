//defines LinkedList class
#pragma once
#include "person.h"

class LinkedList {
	private:
		struct Node{
			Person person;
			Node * next;
			
			Node (const Person& pers) : person(pers), next(nullptr){}
		};

		Node * head;
		Node * tail;
		int count;

	public:
		LinkedList();
		LinkedList(LinkedList&) = delete;
		LinkedList& operator=(LinkedList&) = delete;
		~LinkedList();

		int getCount() const;
		void add(const Person& pers);
		void remove(const char * personId);
		Person * find(const char * personId);
};
