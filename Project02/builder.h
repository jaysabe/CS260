#pragma once
#include "stack.h"
#include "linkedlist.h"

class Builder {
	private:
		int builderNumber;
		int currSector;
		LinkedList pending;
		Stack backtrackStack;

	public:
		Builder();
		int getCurrSector() const;
		int getBuilderNum() const;
		void setCurrSector(int sector);
		void setBuilderNum(int num);
		void addRequest(int, structure_type type);
		bool doCycle();
		void returnHome();


};
