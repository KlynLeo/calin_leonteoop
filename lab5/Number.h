class Number {

private:
    char* value;
    int base;

public:
    Number(const char* value, int base);
    ~Number();
    Number(const Number& n);
    Number(const Number&& n);
    Number(const int);

    char operator[] (int i);

    friend Number operator+ (const Number& x, const Number& y);
    friend Number operator- (const Number& x, const Number& y);

    bool operator> (Number& n);
    bool operator>= (Number& n);
    bool operator< (Number& n);
    bool operator<= (Number& n);
    bool operator==(Number& n);

    void operator= (const char*);
    void operator= (const Number& n);
    void operator= (int n);

    void operator+= (Number& n);

    void operator-- ();
    void operator-- (int);


    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount();
    int  GetBase();
    int getBaseTen();


private:
    int convertToBaseTen(char* s, int base);
    char* convertToBase(int n, int base);
    int Convertire(char c);
    char Convertire2(int n);
};

char* toString(int);
