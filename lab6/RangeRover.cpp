#include "RangeRover.h"
#include "Weather.h"
#include <string>

RangeRover::RangeRover()
{
	fuel_capacity = 70;
	fuel_consumption = 9;
	average_speed[Weather::Rain] = 100;
	average_speed[Weather::Snow] = 90;
	average_speed[Weather::Sun] = 150;
	Name_Car = "Range Rover";
};

int RangeRover::calculateTime(int weather, int length, bool& Finish)
{
	int speed = average_speed[weather];
	int autonomie = fuel_capacity / fuel_consumption;
	int distance = autonomie * speed;

	if (distance > length)
		Finish = 1;
	else
		Finish = 0;

	int timpfinal = length / average_speed[weather];
	return timpfinal;
}

const char* RangeRover::GetName()
{
	return Name_Car;
}