//defines boxlist implementation
#include "boxlist.h"
using namespace std;


BoxList::BoxList():head(nullptr), mCurrent(nullptr){}

BoxList::BoxList(const BoxList& other) : head(nullptr), mCurrent(nullptr){
	Node * otherCurr = other.head;
	while(otherCurr){
		addBox(otherCurr->box);
		otherCurr = otherCurr->next;
	}
}

BoxList::~BoxList(){
	Node * curr = head;
	while(curr){
		Node * next = curr->next;
		delete curr;
		curr = next;
	}
}

int BoxList::getSize() const{
	return size;
}

void BoxList::addBox(const Box& aBox){
	//inserting at tail:
	Node *newNode = new Node(aBox);
	newNode->box = aBox;
	size = getSize();

	if(!head){
		head = newNode;
	}
	else {
		Node * curr = head;
		while(curr->next){
			curr = curr->next;
		}
		curr->next = newNode;
	}
	size++;
}

void BoxList::startIterating(){
	mCurrent = head;
}

const Box& BoxList::getNextBox(){
	const Box& currBox = mCurrent->box;
	mCurrent = mCurrent->next;
	
	return currBox;
}

bool BoxList::hasNextBox() const{
	return mCurrent != nullptr;
}
