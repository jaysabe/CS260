#include <iostream>
#include <fstream>
#include <cstring>
#include "structuretype.h"
#include "builder.h"



using namespace std;

#define MAX_COMMAND_LENGTH 50
#define REQUESTS_PER_CYCLE 5

int main(int argc, char** argv) {

    if (argc != 2) {
	cout << "Usage: " << argv[0] << " <datafile>" << endl;
	return(0);
    }

    char* datafile = argv[1];
    ifstream infile(datafile);

    // The first line of the data file contains the number of builders in the format:
    // numbuilders x
    // We need to know how many builders we'll have so that we can allocate the dynamic
    // array of builders (see below)

    char junk[MAX_COMMAND_LENGTH];
    int numBuilders;
    infile >> junk;  // read and discard the text "numbuilders"
    infile >> numBuilders;

    // Create the dynamic array of builders based on how many we need (read above).
    // After creating the array, we will go through and set the builder number for
    // each one.

    Builder* builders;
    builders = new Builder[numBuilders];
    for (int i=0;i<numBuilders;i++)
    {
	builders[i].setBuilderNum(i+1);
    }

    // Now we're ready to begin the request/work cycles. We will keep doing this loop
    // until there is no more data in the datafile AND all the builders have completed
    // all their work.

    int cycle = 1;
    bool doneReadingData = false; 
    bool didSomething = false;
    bool done = false;  

    while (!done) {

	// At the start of each cycle we print this banner text. 
	cout << "======================================================================" << endl;
	cout << "=== Cycle: " << cycle << endl;
	cout << "======================================================================" << endl;
	cout << endl;
	cycle++;

	// Phase 1: Sending requests
	//
	// This the "send requests" part of a cycle. Here we are going to read requests from
	// the data file and send them to the appropriate builder. We can only handle a certain
	// number of requests per cycle and that is specified with the REQUESTS_PER_CYCLE
	// constant. It might be that we reach the end of the datafile before we've issued the
	// max number of commands for this cycle. The "if" condition inside the loop covers
	// this case.

	cout << "Dispatching new commands" << endl;
	cout << "------------------------" << endl;
	if (!doneReadingData)
	{
	    for (int i=0;i<REQUESTS_PER_CYCLE;i++)
	    {
		int builderNum;
		int sectorNum;
		char typeStr[MAX_COMMAND_LENGTH];

		infile >> builderNum;
		infile >> sectorNum;
		infile >> typeStr;
		if (infile.eof())
		{
		    doneReadingData = true;
		}
		else
		{
		    // After reading the builderNum, sectorNum, and typeStr from the
		    // datafile, we need to convert the typeStr to an enum and then
		    // we need to call the addRequest() method on the appropriate
		    // builder. We use the provided getFromString() function to convert
		    // the enum. We use the bulderNum to index into the array of
		    // builders so that we are accessing the correct one. And then we
		    // simply call the addRequest() method on that builder.

		    structure_type type = getFromString(typeStr);
		    builders[builderNum-1].addRequest(sectorNum,type);
		}
	    }
	}
	else
	{
	    cout << "No more commands to read" << endl;
	}
	cout << endl;

	
	// Phase 2: Doing work
	//
	// This the "do work" part of a cycle. Here we are going to go through the array
	// of all builders and give each one of them a chance to do some work. Each builder
	// may or may not have work to do. The builder will return true or false to let us
	// know if they did anything. If at least one builder does some work this cycle, then
	// we know that we're not yet done.
	//
	// Builders "do work" by us calling doCycle() on the builder. See the instructions to
	// make sure you understand what a builder is supposed to do when doCycle() is called.

	didSomething = false;
	cout << "Activating each builder" << endl;
	cout << "-----------------------" << endl;
	for (int i=0;i<numBuilders;i++)
	{
	    if (builders[i].doCycle())
	    {
		didSomething = true;
	    }
	}
	if (!didSomething)
	{
	    cout << "No builders have any pending commands this cycle" << endl;
	}
	cout << endl;

	// After sending requests and letting builders do work, we have to decide if
	// we should do another cycle. There are two conditions that must be met in
	// order for us to be completely done.
	//
	// 1. We must be at the end of the datafile.
	// 2. All of the builders reported that they were idle.
	//
	// Both of these conditions are tracked with boolean variables that are set in
	// the above phases. At this point we can set the "done" flag based on the
	// values of those variables.
	
	done = (doneReadingData && !didSomething);
    }

    // After all the work is done and all the builders are idle. It is time to tell
    // them all to come home. This is done by going through the array of builders
    // and calling the returnHome() method on each one.

    cout << "Recalling each builder" << endl;
    cout << "----------------------" << endl;
    for (int i=0;i<numBuilders;i++)
    {
	builders[i].returnHome();
    }
    cout << endl;

    delete [] builders;
}
