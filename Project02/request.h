#pragma once
#include "structuretype.h"


class Request{
	public:
		Request(int sector, structure_type type);
		int getSector() const;
		structure_type getType() const;


	private:
		int sector;
		structure_type type;
};
