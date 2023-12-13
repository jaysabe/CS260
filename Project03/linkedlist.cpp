
#include <iostream>
#include <cstring>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList(): head(nullptr), tail(nullptr){
	count = 0;
}

LinkedList::~LinkedList(){
	Node * curr = head;
	while (curr){
		head = curr->next;
		delete curr;
		curr = head;
	}
	tail = nullptr;
}

int LinkedList::getCount() const{
	return count;
}

void LinkedList::add(const Person& aPerson){
	Node * newNode = new Node(aPerson);
	newNode->person = aPerson;
	newNode->next = head;

	if (!head){
		head = tail = newNode;
	}
	else {
		head = newNode;
	}
	count++;
}

Person * LinkedList::find(const char * targetId){
	Node * curr = head;
	
	while (curr && strcmp(curr->person.getPersonId(), targetId) != 0){
		curr = curr->next;
	}
	//ternary statement to return if found else nullptr
	return (curr) ? &(curr->person): nullptr;	
}

void  LinkedList::remove(const char * targetId){
	Node * curr = head;
	Node * prev = nullptr;
	

	while (curr && strcmp(curr->person.getPersonId(), targetId) != 0){
		prev = curr;
		curr = curr->next;
	}
	if (curr){
		
		if (prev){
			prev->next = curr->next;
		}
		else {
			head = curr->next;
		}
		
		if (curr== tail){
			tail = prev;
		}
		delete curr;
		count--;
	}
}
