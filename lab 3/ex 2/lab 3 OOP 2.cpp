
#include <iostream>
#include "Canvas.h"
int main()
{
    Canvas Canvas(50,50);
    Canvas.Clear();
    
    Canvas.DrawCircle(20, 10, 5, '.');
    Canvas.Print(); 
    Canvas.FillCircle(20, 10, 5, '.');
    Canvas.Print();

    Canvas.Clear();
    Canvas.DrawRect(10, 5, 30, 20, '*');
    Canvas.Print();
    Canvas.FillRect(10, 5, 30, 20, 'm');
    Canvas.Print();

    Canvas.Clear();
    Canvas.SetPoint(2, 17, '*');
    Canvas.SetPoint(2, 7, '*');
    Canvas.DrawLine(2, 17, 2, 7, '|');
    Canvas.Print();


}
