
#include <iostream>
#include "Student.h"
#include "Global functions.h"
using namespace std;
int main()
{
    Student p1, p2;
    p1.SetName("Michael Jackson");
    p1.SetMath(6.3);
    p1.SetEnglish(9.0);
    p1.SetHistory(3.5);
    p1.GetAvg();
    
    p2.SetName("Michael Jordan");
    p2.SetMath(6.3);
    p2.SetEnglish(8.5);
    p2.SetHistory(7.5);
    p2.GetAvg();
  
    cout << ComparaLaNume(&p1, &p2) << endl; //comparatie lexicografica
    cout << ComparaLaMate(&p1, &p2) << endl;
    cout << ComparaLaEng(p1, p2) << endl;
    cout << ComparaLaIstorie(p1, p2) << endl;
    cout << ComparaLaMedie(p1, p2) << endl;
}

