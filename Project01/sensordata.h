#pragma once

class SensorData {
	public:
		SensorData();
		SensorData(int, int, int);
		
		
		int	getSector() const;
		int	getIronLevel() const;
		int	getSiliconLevel() const;
	
	private:
		int	sectorNumber;
		int	ironLevel;
		int	siliconLevel;

};
