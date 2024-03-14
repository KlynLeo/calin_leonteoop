
#include <iostream>
#include "Math.h"
using namespace std;
int main()
{
    Math a;
    cout << a.Add(24, 56) << endl;
    cout << a.Add(12, 56, 75) << endl;
    cout << a.Add(12.4, 764.6) << endl;
    cout << a.Add(34.5, 32.7, 32.65) << endl;
    cout << a.Mul(23, 4) << endl;
    cout << a.Mul(2, 4, 5) << endl;
    cout << a.Mul(2.2, 4.4) << endl;
    cout << a.Mul(10.5, 4.3, 5.8) << endl;
    cout << a.Add(5,1,2,3,4,5) << endl;
    cout << a.Add("Mihai, Naty si Tudor ", "sunt praf la fotbal");
}

