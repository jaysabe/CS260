#pragma once
#include "sensordata.h"
#include <iostream>
#include <cstring>

class LinkedList {
	private:
		struct Node{	
			SensorData data;
			Node * nextBySector;
			Node * nextByIron;
			Node * nextBySilicon;

		//constructor for init node data
			Node(): nextBySector(nullptr), nextByIron(nullptr), nextBySilicon(nullptr){}
			Node(const SensorData& aData): data(aData), nextBySector(nullptr), nextByIron(nullptr), nextBySilicon(nullptr) {}
		};

		Node *	headBySector;
		Node *	headByIron;
		Node *	headBySilicon;
		int	count;
	public:
		LinkedList();
		LinkedList(const LinkedList &) = delete;
		~LinkedList();
		LinkedList & operator=(const LinkedList&) = delete;
		bool addSensorData(SensorData& aData);
		//sorting helper functions:
		bool sortBySectorChain(SensorData& aData);
		bool sortByIronChain(SensorData& aData);
		bool sortBySiliconChain(SensorData& aData);
		
		void printListBySector() const;
		void printListByIron() const;
		void printListBySilicon() const;
		
		//Print iron and silicon averages:
		void printAvgsBySector()const;
		
		//prints all sector numbers in the list
		void printSectorNums() const;

		//checks for specific sector number
		bool sectorInList(const int & sector) const;

		//removes all insteances of a given sector from list
		bool wipeSector(const int& sector);
};
