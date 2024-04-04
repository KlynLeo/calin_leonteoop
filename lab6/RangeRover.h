#pragma once

#include "Car.h"

class RangeRover : public Car
{
public:
    RangeRover();
    int calculateTime(int, int, bool&) override;
    const char* GetName() override;
}; 
