#include "Seat.h"
#include "Weather.h"
#include <string>

Seat::Seat()
{
	fuel_capacity = 35;
	fuel_consumption = 18;
	average_speed[Weather::Rain] = 80;
	average_speed[Weather::Snow] = 60;
	average_speed[Weather::Sun] = 120;
	Name_Car = "Seat";
};

int Seat::calculateTime(int weather, int length, bool& Finish)
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

const char* Seat::GetName()
{
	return Name_Car;
}