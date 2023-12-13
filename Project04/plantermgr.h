// defines the PLanterMgr class
#include "boxtree.h"


class PlanterMgr {
	private:
		BoxTree bt;
		
	public:
		void plant(int, char*);
		void harvest(char*, int start, int stop);
		void prune(int);
};
