// defines person.cpp
#include <iostream>
#include <cstring>
#include "person.h"
using namespace std;

Person::Person(char * personId, char * fName, char * lName, char * famId): personId(nullptr), fName(nullptr), lName(nullptr), famId(nullptr){
	setPersonId(personId);
	setfName(fName);
	setlName(lName);
	setFamId(famId);
	}

Person::Person(const Person& aPerson): personId(nullptr), fName(nullptr), lName(nullptr), famId(nullptr){
	setPersonId(aPerson.personId);
	setfName(aPerson.fName);
	setlName(aPerson.lName);
	setFamId(aPerson.famId);
}

Person & Person::operator=(const Person& aPerson){
	if (this != &aPerson){	
		setPersonId(aPerson.personId);
		setfName(aPerson.fName);
		setlName(aPerson.lName);
		setFamId(aPerson.famId);
	}
	return *this;
}

Person::~Person(){
	if (personId){
	       	delete[] this->personId;
		personId = nullptr;
	}
	if (fName){
	       	delete[] this->fName;
		fName = nullptr;
	}
	if (lName){
	       	delete[] this->lName;
		lName = nullptr;
	}
	if (famId){
	       	delete[] this->famId;
		famId = nullptr;
}
}

char * Person::getPersonId() const{
	return personId;
}
char * Person::getfName() const{
	return fName;
}
char * Person::getlName() const{
	return lName;
}
char * Person::getFamId() const{
	return famId;
}

void Person::setPersonId(const char * personId){
	if (this->personId){
		delete[] this->personId;
		this->personId = nullptr;
	}
	this->personId = new char[strlen(personId)+1];
	strcpy(this->personId, personId);	
}

void Person::setfName(const char * fName){
	if (this->fName){
		delete[] this->fName;
		this->fName = nullptr;
	}
	this->fName = new char[strlen(fName)+1];
	strcpy(this->fName, fName);	
}

void Person::setlName(const char * lName){
	if (this->lName){
		delete[] this->lName;
		this->lName = nullptr;
	}
	this->lName = new char[strlen(lName)+1];
	strcpy(this->lName, lName);	
}

void Person::setFamId(const char * famId){
	if (this->famId){
		delete[] this->famId;
		this->famId = nullptr;
	}
	this->famId = new char[strlen(famId)+1];
	strcpy(this->famId, famId);	
}

void Person::print() const{
	cout <<"ID: " << personId << endl << "First Name: " << fName << endl << "Last Name: " << lName << endl;
	cout << endl;
}
