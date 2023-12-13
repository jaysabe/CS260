#ifndef STRUCTURETYPE_H
#define STRUCTURETYPE_H

// The snum for the three different types of structures that can be built.
// The UNK type is "unknown".
enum structure_type {WIND, WATER, SOLAR,UNK};

// This function takes a string value and find the matching enum token. For example:
//
// structure_type st = getFromString("wind");
//
// This will result in the variable "st" having the value "WIND".
structure_type getFromString(const char* str);

// This function takes a structure_type as input and it copies into the "str" argument
// the string value equivalent of that type. It is important to note that the "str"
// argument must point to allocated space already. Here is an example of using this
// function:
//
// structure_type st = SOLAR;
// char stName[100];
//
// toString(st,stName);
// cout << stName << endl;
//
// This will result in the text "solar" being copied into "str".
void toString(const structure_type type,char* str);

// This function takes a structure_type as input and then returns a string
// that says what it is. For example:
//
// structure_type st = WATER;
// cout << str(st) << endl;
//
// This will result in "water harvester" being printed on the screen.
const char* str(const structure_type type);

#endif
