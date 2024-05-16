#include <iostream>
using namespace std;

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template <class T>
class Array;
template<class T>
class ArrayIterator
{
private:
    int Current; 
    Array<T>* Ar; 

public:
    ArrayIterator() : Current(0), Ar(nullptr) {}
    ArrayIterator(Array<T>* ar, int current) : Current(current), Ar(ar) {}

    ArrayIterator& operator++() {
        ++Current;
        return *this;
    }
    ArrayIterator& operator--() {
        --Current;
        return *this;
    }

    bool operator==(const ArrayIterator<T>& other) const {
        return Ar == other.Ar && Current == other.Current;
    }
    bool operator!=(const ArrayIterator<T>& other) const {
        return Ar != other.Ar || Current == other.Current;
    }

    T* GetElement() {
        return &Ar->operator[](Current);
    }
};


template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array()
    {
        Capacity = 0;
        Size = 0;
    }
    Array(int capacity)
    {
        List = new T * [capacity];
        Capacity = capacity;
    }

    ~Array()
    {
        delete[] List;
    }

    Array(const Array<T>& other)
    {
        for (int i = 0; i < Size; i++)
            List[i] = other.List[i];
        Capacity = other.Capacity;
        Size = other.Size;
    }

    T& operator[] (int index)
    {
        try
        {
            if (index >= Size)
                throw out_of_range("The index is out of range");
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem)
    {
        if (Capacity == Size)
        {
            Capacity *= 2;
            T** copieLista = new T * [Capacity];
            for (int i = 0; i < Size; i++)
                copieLista[i] = List[i];
            delete[] List;
            List = copieLista;
        }
        List[Size] = new T(newElem);
        Size++;
        return *this;
    }

    int GetSize()
    {
        return Size;
    }
    int GetCapacity()
    {
        return Capacity;
    }

    const Array<T>& Insert(int index, const T& newElem)
    {
        try
        {
            if (index >= Capacity || index < 0)
                throw out_of_range("Indexul e prea mare sau nu e pozitiv");
        }
        catch (exception& e) {
            cout << "exceptie: " << e.what() << endl;
        }

        if (Size == Capacity)
        {
            Capacity *= 2;
            T** copieLista = new T * [Capacity];
            for (int i = 0; i < index; i++)
                copieLista[i] = List[i];
            delete[] List;
            List = copieLista;
        }
        for (int i = Size - 1; i >= index; i--)
            List[i + 1] = List[i];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T>& otherArray)
    {
        try
        {
            if (index >= Capacity || index < 0)
                throw out_of_range("Indexul e prea mare sau nu e pozitiv");
        }
        catch (exception& e) {
            cout << "exceptie: " << e.what() << endl;
            exit(1);
        }

        if (Capacity < Size + otherArray.Size)
        {
            Capacity *= 2;
            T** copieLista = new T * [Capacity];
            for (int i = 0; i < index; i++)
                copieLista[i] = List[i];
            delete[] List;
            List = copieLista;
        }
        for (int i = Size - 1; i >= index; i--)
            List[i + otherArray.Size] = List[i];
        for (int i = 0; i < otherArray.Size; i++)
            List[index + i] = otherArray.List[i];
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index)
    {
        try
        {
            if (index >= Capacity || index < 0)
                throw out_of_range("Indexul e prea mare sau nu e pozitiv");
        }
        catch (exception& e) {
            cout << "exceptie: " << e.what() << endl;
        }

        delete List[index];
        for (int i = index; i < Size - 1; i++) {
            List[i] = List[i + 1];
        }

        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray)
    {
        if (this == &otherArray)
            return true;
        for (int i = 0; i < Size; ++i) {
            delete List[i];
        }
        delete[] List;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; ++i) {
            List[i] = otherArray.List[i];
        }
        return true;
    }

    void Sort()
    {
        for (int i = 0; i < Size; i++)
            for (int j = i+1; j < Size; j++)
                if (*List[i] > *List[j])
                    swap(List[i], List[j]);
    }
 
    void Sort(bool(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; ++i) {
            for (int j = i + 1; j < Size; ++j) {
                if (compare(*List[j], *List[i])) {
                    swap(List[i], List[j]);
                }
            }
        }
    }

    void Sort(Compare* comparator)
    {
        if (Size <= 1) {
            return;
        }

        for (int i = 0; i < Size; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    int BinarySearch(const T& elem)
    {
        int left = 0;
        int right = Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (*List[mid] == elem)
                return mid;
            else if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int left = 0;
        int right = Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int comp = compare(*List[mid], elem);
            if (comp == 0)
                return mid;
            else if (comp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(T& elem, Compare* comparator)
    {
        int left = 0;
        int right = Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int comp = comparator->CompareElements(List[mid], &elem);
            if (comp == 0)
                return mid;
            else if (comp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem)
    {
        for (int i = 0; i < Size; i++)
        {
            if (*List[i] == elem)
                return i;
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; i++)
        {
            if (compare(*List[i], elem) == 0)
                return i;
        }
        return -1;
    }

    int Find(T& elem, Compare* comparator)
    {
        for (int i = 0; i < Size; i++)
        {
            if (comparator->CompareElements(List[i], &elem) == 0)
                return i;
        }
        return -1;
    }
    
    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(this, 0);
    }
    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(this, Size);
    }
};

class IntCompare : public Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) override
    {
        int* int1 = static_cast<int*>(e1);
        int* int2 = static_cast<int*>(e2);
        if (*int1 < *int2) {
            return -1;
        }
        else if (*int1 > *int2) {
            return 1;
        }
        return 0;
    }
};


template<typename T>
bool Comp1(const T& a, const T& b) {
    return a < b;
}

int Comp2(const int& a, const int& b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int main()
{
    Array<int> arr(10);
    Array<int> arr2(3);
    Array<int> arr3(9);
    IntCompare int_compare;
    arr2 += -3;
    arr2 += -2;
    arr += 5;
    arr += 10;
    arr += 3;
    arr += 8;
    arr += 1;
    arr += 7;
    arr.Insert(1, arr2);
    arr.Insert(3, -1);
    arr.Delete(1);
    cout << "Se pot observa modificarile pt arr: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    arr3 = arr;
    cout << "Arrayul arr3 este la fel cu arr 1: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    arr.Sort(Comp1);
    cout << "arr sortat cu orice metoda doriti: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int asta = 8;
    cout << "Elementul " << asta << " se afla pe pozitia: " << arr.BinarySearch(asta, &int_compare);
    cout << endl;
    cout << "Elementul " << asta << " se afla pe pozitia: " << arr.Find(asta, &int_compare);
    cout << endl;
}