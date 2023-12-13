//defines boxlist.cpp
#include "boxtree.h"
using namespace std;


BoxTree::BoxTree():root(nullptr), size(0){}


BoxTree::BoxTree(const BoxTree& aBt):root(nullptr), size(aBt.size){
	*this = aBt;
}

BoxTree& BoxTree::operator=(const BoxTree& aBt){
	//relase then copy current obj
	destroyTree(root);
	copyTree(root, aBt.root);
	
	return *this;
}


void BoxTree::copyTree (Node *& newRoot, Node * root){
	if(root){
		//copy root:
		newRoot = new Node(root->box);
		copyTree(newRoot->left, root->left);
		copyTree(newRoot->right, root->right);
	}
	else {
		newRoot = nullptr;
	}
}

BoxTree::~BoxTree(){
	destroyTree(root);
}

void BoxTree::destroyTree(Node*& root){
	if(root){
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
		root = nullptr;
	}
}

void BoxTree::insert(const Box& aBox){
	insert(root, aBox);
}

void BoxTree::insert(Node*& root, const Box& aBox){
	if(!root){
		root = new Node(aBox);
		size++;
	}
	else if(aBox < root->box){
		insert(root->left, aBox);
	}
	else {
		insert(root->right, aBox);
	}
}

int BoxTree::remove(const int num){
	return remove(root, num);
}

int BoxTree::remove(Node*& root, const int num){
	int removalOccurred = -1;
	
	if(!root){
	}
	else if (num == root->box.getBoxNum()){
		removalOccurred = root->box.getBoxNum();
		deleteNode(root);
		
	}
	else if (num < root->box.getBoxNum()){
		removalOccurred = remove(root->left, num);
	}
	else{
		removalOccurred = remove(root->right, num);
	}

	return removalOccurred;
}

void BoxTree::deleteNode(Node*& target){
	Node * temp;

	//a leaf:
	if(!target->left && !target->right){
		delete target;
		target = nullptr;
	}
	//no left child:
	else if(!target->left){
		temp = target;
		target = target->right;
		temp->right = nullptr;
		delete temp;
	}
	//no right child:
	else if(!target->right){
		temp = target;
		target = target->left;
		temp->left = nullptr;
		delete temp;
	}
	//two children:
	else {
		Node * prev = nullptr;
		Node * curr = target->right;
		
		//find inorder successor
		while(curr->left){
			prev = curr;
			curr = curr->left;
		}

		target->box = curr->box;
		//disconnect curr:
		if(prev){
			prev->left = curr->right;
		}
		else {
			target->right = curr->right;
		}


		//delete curr:
		curr->right = nullptr;
		delete curr;
	}
	size--;
}

int BoxTree::getSize() const{
	return size;
}

BoxList * BoxTree::getRange(int start, int stop){
	BoxList * result = new BoxList();
	getRange(root, start, stop, *result);
	//returns BoxList with nodes in specified range
	return result;	
}

void BoxTree::getRange(Node*& root, int start, int stop, BoxList& result){
	for (int num = start; num <=stop; ++num){
		Node * curr = root;

		while(curr != nullptr){
			if(num < curr->box.getBoxNum()){
				curr = curr->left;
			}
			else if(num == curr->box.getBoxNum()){
				result.addBox(curr->box);
				break;
			}
			else{
				curr = curr->right;
			}

		}
	}
	/*if(root != nullptr){
		if(start < root->box.getBoxNum()){
			getRange(root->left, start, stop, result);
		}
		else if(start <= root->box.getBoxNum() && stop >= root->box.getBoxNum()){
			result.addBox(root->box);
		}
		else if(stop > root->box.getBoxNum()){
			getRange(root->right, start, stop, result);
		}
	}*/
}

