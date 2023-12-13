#include "sensordata.h"

SensorData::SensorData() : sectorNumber(0), ironLevel(0), siliconLevel(0){}

SensorData::SensorData(int sector, int iron, int silicon): sectorNumber(sector), ironLevel(iron), siliconLevel(silicon){}
//~SensorData();

int SensorData::getSector() const {
	return sectorNumber;
}

int SensorData::getIronLevel() const{
	return ironLevel;
}

int SensorData::getSiliconLevel() const {
	return siliconLevel;
}


