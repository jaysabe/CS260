#include "linkedlist.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


LinkedList::LinkedList():headBySector(NULL), headByIron(NULL),headBySilicon(NULL),count(0){
}


LinkedList::~LinkedList(){
	Node * curr = headBySector;
	
	while (curr){
		headBySector = curr->nextBySector;
		delete curr;
		curr = headBySector;
	}

	//reset count
	count = 0;
}


bool LinkedList::sortBySectorChain(SensorData& aData){
	bool check;

	Node * prev = nullptr;
	Node * curr = headBySector;

	//Traverse and insert by Sector
	while (curr != nullptr && curr->data.getSector() < aData.getSector()){
		prev = curr;
		curr = curr->nextBySector;
	}

	//if exists
	if(curr && curr->data.getSector() == aData.getSector())
		check = false;
	else {
		Node * newNode = new Node(aData);
		newNode->data = aData;
		newNode->nextBySector = NULL;
		
		//link to newNode
		newNode->nextBySector = curr;
		if(prev==NULL)
			headBySector = newNode;
		else
			prev->nextBySector = newNode;
		
		check = true;
	}
	return check;
}

bool LinkedList::sortByIronChain(SensorData& aData){
	bool check;

	Node * prev = nullptr;
	Node * curr = headByIron;

	//Traverse and insert by iron levels
	while (curr != nullptr && curr->data.getIronLevel() < aData.getIronLevel()){
		prev = curr;
		curr = curr->nextByIron;
	}

	//if data exists already
	if(curr && curr->data.getIronLevel() == aData.getIronLevel())
		check = false;
	else {
		Node * newNode = new Node(aData);
		newNode->data = aData;
		newNode->nextByIron = NULL;
		
		//link to newNode
		newNode->nextByIron = curr;
		if(prev==NULL)
			headByIron = newNode;
		else
			prev->nextByIron = newNode;
		
		check = true;
	}
	return check;
}

bool LinkedList::sortBySiliconChain(SensorData& aData){
	bool check;

	Node * prev = nullptr;
	Node * curr = headBySilicon;

	//Traverse and insert in order by silicon:
	while (curr != nullptr && curr->data.getSiliconLevel() < aData.getSiliconLevel()){
		prev = curr;
		curr = curr->nextBySilicon;
	}

	//if data already exists 
	if(curr && curr->data.getSiliconLevel() == aData.getSiliconLevel())
		check = false;
	else {
		Node * newNode = new Node(aData);
		newNode->data = aData;
		newNode->nextBySilicon = NULL;
		
		//link to newNode
		newNode->nextBySilicon = curr;
		if(prev==NULL)
			headBySilicon = newNode;
		else
			prev->nextBySilicon = newNode;
		
		check = true;
	}
	return check;
}


bool LinkedList::addSensorData(SensorData& aData){
	bool dataAdded = false;
	Node * newNode = new Node;
	newNode->data = aData;
	
	//Call helper sorting functions:
	sortBySectorChain(aData);
	sortByIronChain(aData);
	sortBySiliconChain(aData);

	count++;
	dataAdded = true;
	
	
	return dataAdded;
}

void LinkedList::printListBySector() const {
	Node * curr = headBySector;


	cout << "-------------------------------------------"
	     << "---------------------------" << endl 
	     << "Data By Sector: " << endl
	     << "-------------------------------------------"
	     << "---------------------------" << endl; 
	
	while (curr != nullptr){
		cout << "Sector: #" << curr->data.getSector() << " "
		     << curr->data.getIronLevel() << " grams iron,  "
		     << curr->data.getSiliconLevel() << " milligrams silicon" << endl;

		//traverse:
		curr = curr->nextBySector;
	}
	cout << endl;
}

void LinkedList::printListByIron() const {
	Node * curr = headByIron;
	
	cout << "-------------------------------------------"
	     << "---------------------------" << endl 
	     << "Data By Iron: " << endl
	     << "-------------------------------------------"
	     << "---------------------------" << endl; 
	
	while (curr != nullptr){
		cout << "Sector: #" << curr->data.getSector() << " "
		     << curr->data.getIronLevel() << " grams iron,  "
		     << curr->data.getSiliconLevel() << " milligrams silicon" << endl;

		//traverse:
		curr = curr->nextByIron;
		
	}
	cout << endl;
	
}

void LinkedList::printListBySilicon() const {
	Node * curr = headBySilicon;
	
	cout << "-------------------------------------------"
	     << "---------------------------" << endl 
	     << "Data By Silicon: " << endl
	     << "-------------------------------------------"
	     << "---------------------------" << endl; 
	
	while (curr != nullptr){
		cout << "Sector: #" << curr->data.getSector() << " "
		     << curr->data.getIronLevel() << " grams iron,  "
		     << curr->data.getSiliconLevel() << " milligrams silicon" << endl;

		//traverse:
		curr = curr->nextBySilicon;
		
	}
	cout << endl;
}


void LinkedList::printAvgsBySector()const {
	int length = 0;
	double avgIron = 0.0;
	double avgSilicon = 0.0;

	cout << "-------------------------------------------"
	     << "---------------------------" << endl 
	     << "Averages by Sector: " << endl
	     << "-------------------------------------------"
	     << "---------------------------" << endl; 

	Node * curr = headBySector;
		
	for (int i = 1; curr; i++){
		int sect = curr->data.getSector();
			
		cout << "Sector: #" << i;
		//if theres data in a sector
		if (i ==sect){

			//set vals
			avgIron = 0.0;
			avgSilicon = 0.0;
			length = 0;
			
			//collects all data with same sector
			while(curr!= nullptr && i == curr->data.getSector()){

				avgIron += curr->data.getIronLevel();
				avgSilicon += curr->data.getSiliconLevel();
				curr=curr->nextBySector;
				length++;
			}
			avgIron /= static_cast<double>(length);
			avgSilicon /= static_cast<double>(length);
			 
			cout << " "
	           	     << avgIron << " grams iron, "
		     	     << avgSilicon << " milligrams silicon"
	             	     << endl;
		}	
		else {
			cout << "\t --- no data ---" << endl;
	}	
}
}


void LinkedList::printSectorNums() const{
	Node * curr = headBySector;
	

	//print list of sector numbers in ascending order
	while (curr != nullptr){
		cout  << curr->data.getSector();

		//Check if theres another node after the curr
		if (curr->nextBySector != nullptr){
			cout << ", "; //add comma 
		}

		//traverse
		curr= curr->nextBySector;
	}

	//for spacing at the end of the list
	cout << endl << endl;
}
	
bool LinkedList::sectorInList(const int& sector) const{
	
	for (Node * curr = headBySector; curr; curr = curr->nextBySector){
		if (sector == curr->data.getSector()){
			return true;	
		}
	}
	return false;

}

bool LinkedList::wipeSector(const int& sector){
	bool removed = false;

	Node * curr = headBySector;
	Node * prev = nullptr;

	while(curr != nullptr){
		if (curr->data.getSector() == sector){
			if (prev == nullptr){
			//remove first node
				headBySector = curr->nextBySector;			
			}
			else{
				prev->nextBySector = curr->nextBySector;		
		}
			//delete node
			delete curr;
			removed = true;
			return removed;
			
		}
		prev = curr;
		curr=curr->nextBySector;
	}
	return removed;
}
