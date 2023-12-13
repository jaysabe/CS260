// defines person class
#pragma once

class Person {
	private:
		char * personId, * fName, * lName, * famId;
	public:
		Person(char * personId, char* fName, char *lName, char *famId);
		Person(const Person& aPerson);
		Person& operator=(const Person& aPerson);
		~Person();

		char * getPersonId() const;
		char * getfName() const;
		char * getlName() const;
		char * getFamId() const;
		
		void setPersonId(const char * personId);
		void setfName(const char * fName);
		void setlName(const char * lName);
		void setFamId(const char * famId);

		void print() const;
};
