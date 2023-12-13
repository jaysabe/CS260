#pragma once
#include "request.h"
#include "linkedlist.h"


class Stack {
	private:
		LinkedList list;
	
	public:
		Stack();
		bool isEmpty() const;
		void push(const Request &req);
		Request pop();
};
