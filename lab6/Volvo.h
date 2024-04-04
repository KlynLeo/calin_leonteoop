#pragma once

#include "Car.h"

class Volvo : public Car
{
public:
    Volvo();
    int calculateTime(int, int, bool&) override;
    const char* GetName() override;
};


