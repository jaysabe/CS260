// defines table.cpp
#include "table.h"
using namespace std;

void printExtreme(node * root, bool smallest){
	if (root == nullptr){
	}
	
       if (smallest){
	       if(root->left != nullptr){
		       printExtreme(root->left, smallest);
	       }
	       else {
		       cout << root->data << endl;
	       }
       }
	else {
		if(root->right != nullptr){
			printExtreme(root->right, smallest);
		}
		else {
			cout << root->data << endl;
		}
	}
}

void add(node ** newRoot, int data){
	if (*newRoot == nullptr){
		*newRoot = new node;
		(*newRoot)->data = data;
		(*newRoot)->left = (*newRoot)->right = nullptr;
		return;
	}
	
	if (data < (*newRoot)->data){
		add(&((*newRoot)->left), data);
	}
	else{
		add(&((*newRoot)->right), data);
	}
}

void copyOdd(node * root, node ** newRoot){
	if (root == nullptr){	
		return;
	}
	
	if(root->data % 2 == 1){	
       	      	//if the value is odd, copy it to new tree
		add(newRoot, root->data);
	}	

		copyOdd(root->left, newRoot);
		copyOdd(root->right, newRoot);	
	}

