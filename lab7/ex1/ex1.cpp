#include <iostream>
using namespace std;

float operator""_Kelvin(long double kelvin) {
    return kelvin - 273.15;
}

float operator""_Fahrenheit(long double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    float a = 350.0_Kelvin;
    float b = 164.0_Fahrenheit;
    cout << "300 Kelvin in Celsius: " << a << std::endl;
    cout << "120 Fahrenheit in Celsius: " << b << std::endl;

    return 0;
}
