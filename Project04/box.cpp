//defines box.cpp
#include <iostream>
#include <cstring>
#include "box.h"
using namespace std;

Box::Box() : num(0), name(nullptr){}

Box::Box(int num, char* name):num(0), name(nullptr){
	setBoxNum(num);
	setBoxName(name);
}

Box::Box(const Box& aBox): num(0),name(nullptr){
	setBoxNum(aBox.num);
	setBoxName(aBox.name);
}

Box & Box::operator=(const Box& aBox){
	if (this != &aBox){
		setBoxNum(aBox.num);
		setBoxName(aBox.name);
	}
	return *this;
}

bool Box::operator<(const Box& other) const{
	return num < other.num;
}

Box::~Box(){
	if (name){
		delete[] this->name;
	}
}

int Box::getBoxNum() const{
	return num;
}

char * Box::getBoxName() const{
	return name;
}

void Box::setBoxNum(int num){
	this->num = num;
}

void Box::setBoxName(const char* name){
	if(this->name){
		delete[] this->name;
		this->name = nullptr;
	}
	
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
} 
