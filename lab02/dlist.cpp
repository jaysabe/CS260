#include "dlist.h"
using namespace std;
//put the implmenetation of the required functions here

void printNth(node * head, int n){
	node * curr = head;
	
	if (curr){
	if (n==1 || !curr->next){
		cout << "Value of the Nth's node: " << curr->data << endl;
	}
	else{
		printNth(curr->next, n-1);
	}
	}

	
}

void insertAtN(node *& head, int n, int value) {
	node * curr = head;

	//if position reached or emd of the list:
	if (n==1 || !curr->next){
		node * newNode = nullptr;
		newNode = new node;
		newNode->data = value;

		if (!curr->previous){
		//insert at beginning:
			newNode->previous = nullptr;
			curr->previous = newNode;
			newNode->next = curr;
			head = newNode;
	}
		//insert in the middle
		else if (curr->previous && curr->next){
		newNode->next = curr;
		newNode->previous = curr->previous;
		curr->previous->next = newNode;
		curr->previous = newNode;
	}
		else{
		//if at the end of the list, insert at last ele
			curr->next = newNode;
			newNode->previous = curr;
			newNode->next = nullptr;
		}
	}
	else {
	insertAtN(head->next, n-1, value);
}}

