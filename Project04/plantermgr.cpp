// defines the implrementation of PlanterMgr
#include <iostream>
#include <cstring>
#include "plantermgr.h"
using namespace std;


void PlanterMgr::plant(int num, char* name){
	Box newBox(num, name);
	bt.insert(newBox);
	cout << "Planting " << name << " in box " << num << endl;
}

void PlanterMgr::harvest(char* name, int start, int stop){
	BoxList * blptr = bt.getRange(start, stop);

	BoxList& boxList = *blptr;

	cout << "Harvesting " << name 
	     << " plants from boxes " << start 
	     << " to " << stop << ". " << endl;

	cout << "The following boxes will be harvested: ";

	boxList.startIterating();

	while(boxList.hasNextBox()){
		const Box& aBox = boxList.getNextBox();

		if(strcmp(aBox.getBoxName(), name)==0){
			cout << aBox.getBoxNum() << " ";
		}
		
	}
	cout << endl;

	delete blptr;

	}


void PlanterMgr::prune(int num){
	int removedBox = bt.remove(num);
	
	if( removedBox != -1){
	cout << "Pruning box number " << removedBox << "." << endl;
	}

}
