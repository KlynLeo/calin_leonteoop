
#include <iostream>
#include "NumberList.h"
using namespace std;
int main()
{
    NumberList obiect;
    int numar, x[20];
    obiect.Init();
    cin >> numar;
    for (int i = 0; i < numar; i++) {
        cin >> x[i];
        obiect.Add(x[i]);
    }
    obiect.Sort();
    obiect.Print();
}

