#pragma once
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "RangeRover.h"
#include "Fiat.h"

class Circuit
{
private:
	int length;
	int weather;
	Car ** cars;
	float EndTimeCircuit[6];
	bool finish[6];
	int nr_cars = 0;

public:
	Circuit(int);
	void swap(int, int);
	void SetLength(int);
	void SetWeather(int);
	void AddCar(Car*);
	void Race();
	void sort_race_time();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};