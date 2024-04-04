#include "Fiat.h"
#include "Weather.h"
#include <string>

Fiat::Fiat()
{
	fuel_capacity = 45;
	fuel_consumption = 5;
	average_speed[Weather::Rain] = 45;
	average_speed[Weather::Snow] = 30;
	average_speed[Weather::Sun] = 130;
	Name_Car = "Fiat";
};

int Fiat::calculateTime(int weather, int length, bool& Finish)
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

const char* Fiat::GetName()
{
	return Name_Car;
}