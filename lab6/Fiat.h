#pragma once

#include "Car.h"

class Fiat : public Car
{
public:
    Fiat();
    int calculateTime(int, int, bool&) override;
    const char* GetName() override;
};