#include "request.h"

Request::Request(int sector, structure_type type){
	this->sector = sector;
	this->type = type;	
}

int Request::getSector() const{
	return sector;
}

structure_type Request::getType() const{
	return type;
}
