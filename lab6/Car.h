#pragma once

class Car 
{
protected:
	int fuel_capacity; 
	int fuel_consumption; 
	int average_speed[3]; 
	const char* Name_Car;
public:
	virtual int calculateTime(int, int, bool&) = 0; 
	virtual const char* GetName() = 0;
};