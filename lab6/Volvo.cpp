#include "Volvo.h"
#include "Weather.h"
#include <string>

Volvo::Volvo()
{
	fuel_capacity = 60;
	fuel_consumption = 7;
	average_speed[Weather::Rain] = 110;
	average_speed[Weather::Snow] = 80;
	average_speed[Weather::Sun] = 160;
	Name_Car = "Volvo";
};

int Volvo::calculateTime(int weather, int length, bool& Finish)
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

const char* Volvo::GetName()
{
	return Name_Car;
}