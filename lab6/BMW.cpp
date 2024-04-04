#include "BMW.h"
#include "Weather.h"
#include <string>

BMW::BMW()
{
	fuel_capacity = 55;
	fuel_consumption = 8;
	average_speed[Weather::Rain] = 120;
	average_speed[Weather::Snow] = 70;
	average_speed[Weather::Sun] = 180;
	Name_Car = "BMW";
};

int BMW::calculateTime(int weather, int length, bool& Finish)
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

const char* BMW::GetName()
{
	return Name_Car;
}