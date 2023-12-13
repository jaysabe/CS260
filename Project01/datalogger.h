#pragma once
#include "linkedlist.h"
using namespace std;

class DataLogger 
{
	private:
		LinkedList linkedList;
	public:
		void	addData(int&, int&, int&);
		bool	containsSector(int&) const;
		void	removeSector(int&);
		void	printReport() const;
		void	printSectorList() const;


};
