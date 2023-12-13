#pragma once
#include "request.h"


class LinkedList{
	private:
		struct node {
			Request data;
			node * next;

			node (const Request& req) : data(req), next(nullptr){}
		};

		node * head;
		node * tail;
		int count;

	public:
		LinkedList();
		LinkedList(const LinkedList& other) = delete;
		LinkedList& operator=(const LinkedList& other) = delete;
		~LinkedList();
		
		int getCount() const;
		bool isEmpty() const;
		void addFront(const Request& req);
		void addBack(const Request& req);
		Request removeFront();
		Request removeBack();

};
