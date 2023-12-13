#include <iostream>
#include "list.h"

//reverses list
void reverse(node * head, node *& newHead){
	//base case
	if (head->next != nullptr){       
		reverse(head->next, newHead);
		node * curr = newHead;
		
		//call helper instead of while?
		while(curr->next != nullptr){
			curr = curr->next;
		}
		curr->next = new node;
		curr->next->data = head->data;
		curr->next->next = nullptr;

	}
	else {
		newHead = new node;
		newHead->data = head->data;
		newHead->next = nullptr;
		
	}
}


void removeLast(node *& head){
	
	if (head == NULL) return;

	//if only one node, delete it and set head to NULL
	if (head->next == NULL){
		delete head;
		head = NULL;
	}
	else if (head->next->next == NULL){
		//two nodes in list
		delete head->next;
		head->next = NULL;
	}
	else{
	
	//Recursively remove last node from rest of list
	removeLast(head->next);
	}
}
