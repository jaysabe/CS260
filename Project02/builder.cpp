#include "builder.h"
#include "structuretype.h"
#include <iostream>
using namespace std;

Builder::Builder(){
	builderNumber = 0;
	currSector = 0;
}

void Builder::setBuilderNum(int num){
	builderNumber = num;
}

void Builder::setCurrSector(int sector){
	currSector = sector;
}

int Builder::getBuilderNum() const {
	return builderNumber;
}

int Builder::getCurrSector() const {
	return currSector;
}

void Builder::addRequest(int sector, structure_type type){
	Request req(sector, type);

	cout << "Builder #" << builderNumber << ": Received request to build a "<< str(req.getType()) << " in sector " << req.getSector() << endl;

	pending.addFront(req);	

}

bool Builder::doCycle(){
	bool didStuff = true;
	int builderNum = getBuilderNum();
	//int currSector = getCurrSector();

	if (!pending.isEmpty()){	
		//get oldest request
		Request currReq = pending.removeBack();
	

		//Compare the loc of the req to the builder
		if (currReq.getSector() != currSector){
			cout << "Builder #" << builderNum 
			     << ": Moving to sector " 
			     << currReq.getSector() << endl;
		
		//update to this loc:
		setCurrSector(currReq.getSector());
		}

		//Build structure:
		cout << "Builder #" << builderNum << ": Building a " 
		     << str(currReq.getType()) 
		     << " in sector " << currReq.getSector() << endl;
	        
		//push stack
		backtrackStack.push(currReq);	
	}
	else{
		didStuff = false;
	}

	return didStuff;
}

void Builder::returnHome(){
	int builderNum = getBuilderNum();

	//backtrack through the processed requests and print msg:
	while (!backtrackStack.isEmpty()){
		//set popped requests
		Request req = backtrackStack.pop();
		
		//check location
		if (req.getSector() != currSector){
			cout << "Builder #" << builderNum 
			     << ": Moving to sector " 
			     << req.getSector() << endl;
		
			//update to this loc:
			setCurrSector(req.getSector());
		}
		
		cout << "Builder #" << builderNum 
		     << ": Connected to " 
		     << str(req.getType()) 
		     << " in sector " << req.getSector() << endl;

	}
		if (backtrackStack.isEmpty()) {
			cout << "Builder #" << builderNum 
			     << ": Arrived back at base." << endl;
		}
}



