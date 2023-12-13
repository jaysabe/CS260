//Defines box class
#pragma once

class Box {
	private:
		int num;
		char * name;
	
	public:
		Box();
		Box(int num, char*);
		Box(const Box& aBox);
		Box& operator=(const Box& aBox);
		~Box();

		int getBoxNum() const;
		char * getBoxName() const;

		void setBoxNum(const int num);
		void setBoxName(const char* name); 

		//helper functions
		bool operator<(const Box& other) const;

};
