#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <ctime>
#include <cstring>
using namespace std;

//constructori
Sort::Sort(int numElements, int min, int max) {
    srand(time(nullptr));
    size = numElements;
    list = new int[size];
    for (int i = 0; i < size; ++i) {
        list[i] = min + rand() % (max - min + 1);
    }
}

Sort::Sort(int* arr, int numElements) {
    size = numElements;
    list = new int[size];
    for (int i = 0; i < size; ++i) {
        list[i] = arr[i];
    }
}

Sort::Sort(int contor, ...) {
    size = contor;
    list = new int[size];
    va_list args;
    va_start(args, contor);
    for (int i = 0; i < size; i++)
        list[i] = va_arg(args, int);
    va_end(args);
}

Sort::Sort() : list(new int [6] {32, 4, 45, 54, 6, 9}), size(6) {};

Sort::Sort(char* str): size(0), list(nullptr) {
    const char* delimiter = ",";
    char* temp = new char[strlen(str) + 1];

    strcpy(temp, str); 
    char* p = strtok(temp, delimiter); 
    while (p != NULL) {
        size++;
        p = strtok(NULL, delimiter);
    }
    list = new int[size]; //trebuie intai sa aflu cat spatiu sa aloc, de asta numar "cuvintele"

    strcpy(temp, str); 
    p = strtok(temp, delimiter);
    int i = 0;

    while (p != NULL && i < size) {
        list[i++] = atoi(p);
        p = strtok(NULL, delimiter);
    }
    delete[] temp;
}

//sortari
void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (list[j] > list[j + 1])
                swap(list[j], list[j + 1]); 
    ascendent = true;
}

void Sort::InsertSort(bool ascendent)
{
    int key;
    for (int i = 1; i < size; i++)
    {
        key = list[i];
        int j = i - 1;
        while (j >= 0 && list[j] > key)
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
    ascendent = true;
}

int partitie(int* list, int l, int h)
{
    int x = list[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (list[j] <= x)
        {
            i++;
            int aux = list[i];
            list[i] = list[j];
            list[j] = aux;
        }
    }
    int aux = list[i + 1];
    list[i + 1] = list[h];
    list[h] = aux;
    return (i + 1);
}

void Sort::QuickSort(bool ascendent)
{
    int l = 0;
    int h = size - 1;
    int stiva[100];
    int top = -1;

    stiva[++top] = l;
    stiva[++top] = h;

    while (top >= 0)
    {
        h = stiva[top--];
        l = stiva[top--];

        int p = partitie(list, l, h);

        if (p - 1 > l)
        {
            stiva[++top] = l;
            stiva[++top] = p - 1;
        }

        if (p + 1 < h)
        {
            stiva[++top] = p + 1;
            stiva[++top] = h;
        }
    }
    ascendent = true; 
}

//alte metode
void Sort::Print() {
    for (int i = 0; i < size; ++i) {
        cout << list[i] << " ";
    }
     cout << std::endl;
}

int Sort::GetElementsCount() {
    return size;
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < size) 
        return list[index];
    else
        return -1; 
}
