

class Sort {
private:
    int* list;
    int size;

public:
    Sort(int numElements, int min, int max);
    Sort(int* arr, int numElements);
    Sort(int count, ...);
    Sort();
    Sort(char* str);

    void InsertSort(bool ascending = false);
    void QuickSort(bool ascending = false);
    void BubbleSort(bool ascending = false);

 
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};

