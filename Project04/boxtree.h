//defines BoxTree class
#pragma once
#include "box.h"
#include "boxlist.h"

class BoxTree{
	private:
		struct Node{
			Box box;
			Node * left;
			Node * right;
			
			Node(const Box& aBox) : box(aBox), left(0), right(0){}
			};

		Node * root;
		int size;

		void insert(Node*& root, const Box& aBox);
		int remove(Node*& root, const int num);
		void deleteNode(Node*& target);
		void destroyTree(Node*& root);
		void copyTree(Node*& newRoot, Node * root);
		void getRange(Node*& root, int start, int stop, BoxList& result);

	public:
		BoxTree();
		BoxTree(const BoxTree& aBt);
		BoxTree &operator=(const BoxTree& aBt);
		~BoxTree();
		
		void insert(const Box& aBox);
		int remove(const int num);
		int getSize() const;
		BoxList * getRange(int, int);
};
