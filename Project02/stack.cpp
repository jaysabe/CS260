#include "stack.h"
using namespace std;

Stack::Stack(): list() {
	//default constructor is called automatically
	//to init the 'list' datamember
}

bool Stack::isEmpty()const {
	return list.isEmpty();
}

void Stack::push(const Request &req){
	list.addFront(req);
}


Request Stack::pop() {
	return list.removeFront();
}


