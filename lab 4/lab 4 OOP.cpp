#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{ 
    Sort list_random(8, 2, 11);
    cout << "Lista initiala: ";
    list_random.Print();
    list_random.BubbleSort(0);
    cout << "Lista sortata: ";
    list_random.Print();
    cout <<"Nr de elemente din lista: " << list_random.GetElementsCount() << endl;
    int poz = 3;
    cout << "Elementul de pe pozitia " << poz  << " este: " << list_random.GetElementFromIndex(poz);
    cout << endl;
    cout << endl;

    int p[] = {4, 6, -2, 8, 3, 0, 5};
    Sort list_from_existing_vector(p, 7);
    cout << "Lista initiala: ";
    list_from_existing_vector.Print();
    list_from_existing_vector.QuickSort(0);
    cout << "Lista sortata: ";
    list_from_existing_vector.Print();
    cout << "Nr de elemente din lista: " << list_from_existing_vector.GetElementsCount() << endl;
    poz = 5;
    cout << "Elementul de pe pozitia " << poz << " este: " << list_from_existing_vector.GetElementFromIndex(poz);
    cout << endl;
    cout << endl;

    Sort list_variadic(5, 5, 4, 3, 2, 1);
    cout << "Lista initiala: ";
    list_variadic.Print();
    list_variadic.InsertSort(0);
    cout << "Lista sortata: ";
    list_variadic.Print();
    cout << "Nr de elemente din lista: " << list_variadic.GetElementsCount() << endl;
    poz = 4;
    cout << "Elementul de pe pozitia " << poz << " este: " << list_variadic.GetElementFromIndex(poz);
    cout << endl;
    cout << endl;

    Sort list_initializer;
    list_initializer.Print();
    cout << "Lista initiala: ";
    list_initializer.InsertSort(0);
    cout << "Lista sortata: ";
    list_initializer.Print();
    cout << "Nr de elemente din lista: " << list_initializer.GetElementsCount() << endl;
    poz = 4;
    cout << "Elementul de pe pozitia " << poz << " este: " << list_initializer.GetElementFromIndex(poz);
    cout << endl;
    cout << endl;

    char sir[] = "54,34,56,32,64,4,2,58,9,91";
    Sort list_string(sir);
    list_string.Print();
    cout << "Lista initiala: ";
    list_string.QuickSort(0);
    cout << "Lista sortata: ";
    list_string.Print();
    cout << "Nr de elemente din lista: " << list_string.GetElementsCount() << endl;
    poz = 4;
    cout << "Elementul de pe pozitia " << poz << " este: " << list_string.GetElementFromIndex(poz);
    cout << endl;
    cout << endl;


}


