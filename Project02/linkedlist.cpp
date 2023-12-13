#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList(){
	head = nullptr;
	tail = nullptr;
	count = 0;
}

LinkedList::~LinkedList(){
	node * curr = head;
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

bool LinkedList::isEmpty() const {
	return head == nullptr;
}

void LinkedList::addFront(const Request& req){
	node * newNode = new node(req);
	newNode->data = req;
	newNode->next = head;
	count = getCount();

	if (!head){
		head = tail = newNode;
	}
	else {
		head = newNode;
	}

	count++;
}

void LinkedList::addBack(const Request& req){
	node * newNode = new node(req);
	newNode->data = req;
	newNode->next = nullptr;
	count = getCount();

	if (!head){
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}

	count++;

}

Request LinkedList::removeFront(){
	count = getCount();
	//if list is empty
	if (!head){
		//do nothing
		
	}

	Request result = head->data;
	node * curr = head;
	head = head->next;
	delete curr;
	curr = nullptr;
	count--;

	return result;
}

Request LinkedList::removeBack(){
	count = getCount();
	//if list is empty:
	if (!head){
		//do nothing
	}
	node * curr = head, *prev = nullptr;

	while(curr->next){
		prev = curr;
		curr = curr->next;
	}

	Request result = curr->data;

	if (!prev){
	//one node:
		head = tail = nullptr;
	}
	else{
		prev->next = nullptr;
		tail = prev;
	}

	delete curr;
	curr = nullptr;
	count--;
	
	return result;
}

