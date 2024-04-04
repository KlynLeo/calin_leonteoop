#pragma once

#include "Car.h"

class BMW : public Car
{
public:
    BMW();
    int calculateTime(int, int, bool&) override;
    const char* GetName() override;
};

