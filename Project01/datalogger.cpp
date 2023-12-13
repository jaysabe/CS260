#include "datalogger.h"

void DataLogger::addData(int& sector, int& iron, int& silicon){
	SensorData aData(sector, iron, silicon);

	linkedList.addSensorData(aData);
}

bool DataLogger::containsSector(int& sector) const{
	return linkedList.sectorInList(sector);
}

void DataLogger::removeSector(int& sector){
	linkedList.wipeSector(sector);

}

void DataLogger::printReport() const {
	//print all reports:
	linkedList.printListBySector();
	linkedList.printListByIron();
	linkedList.printListBySilicon();
	linkedList.printAvgsBySector();
	
}

void DataLogger::printSectorList() const{
	linkedList.printSectorNums();
}
