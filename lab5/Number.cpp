#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
using namespace std;

 //constructori si destructori
Number::Number(const char* valoare, int baza) {
	value = new char[strlen(valoare)];
	strcpy(value, valoare);
	base = baza;
}

Number::~Number() {
}

Number::Number(const Number& n) { //copy
	base = n.base;
	value = n.value;
}

Number::Number(const Number&& n) { //move
	base = n.base;
	value = n.value;
}

Number::Number(const int n) {
	base = 10;
	value = toString(n);
}

//operatori
void Number::operator=(int n) {
	Number nr(toString(n), 10);
	nr.SwitchBase(base);
	*this = nr;
}

void Number::operator=(const char* s) {
	Number nr(s, 10);
	*this = nr;
}

void Number::operator=(const Number& n) {
	base = n.base;
	value = n.value;
}

char Number::operator[](int i) {
	return value[i];
}

Number operator+(const Number& n1, const Number& n2) {
	Number nr1 = n1;
	Number nr2 = n1;
	int baza_max;
	if (nr1.GetBase() > nr2.GetBase())
		baza_max = nr1.GetBase();
	else
		baza_max = nr2.GetBase();
	int nr = nr1.getBaseTen();
	nr += nr2.getBaseTen();

	char* c = toString(nr);
	Number newNumber(c, 10);
	newNumber.SwitchBase(baza_max);
	return newNumber;
}


Number operator-(const Number& n1, const Number& n2) {
	Number nr1 = n1;
	Number nr2 = n2;
	int b_max;
	if (nr1.GetBase() > nr2.GetBase())
		b_max = nr1.GetBase();
	else
		b_max = nr2.GetBase();

	int nr = nr1.getBaseTen();
	nr -= nr2.getBaseTen();

	char* c = toString(nr);
	Number newNumber(c, 10);
	newNumber.SwitchBase(b_max);
	return newNumber;
}

bool Number::operator>(Number& n) {
	int n1 = getBaseTen();
	int n2 = n.getBaseTen();

	return n1 > n2;
}

bool Number::operator>=(Number& n) {
	int n1 = getBaseTen();
	int n2 = n.getBaseTen();

	return n1 >= n2;
}
bool Number::operator<(Number& n) {
	int n1 = getBaseTen();
	int n2 = n.getBaseTen();

	return n1 < n2;
}
bool Number::operator<=(Number& n) {
	int n1 = getBaseTen();
	int n2 = n.getBaseTen();

	return n1 <= n2;
}
bool Number::operator==(Number& n) {
	int n1 = getBaseTen();
	int n2 = n.getBaseTen();

	return n1 == n2;
}

void Number::operator+=(Number& n) {
	int n1 = getBaseTen();
	n1 += n.getBaseTen();
	toString(n1);
	value = toString(n1);
	SwitchBase(base);
}

void Number::operator--() {
	value++;
}

void Number::operator--(int) {
	value[strlen(value) - 1] = NULL;
}

//metode
void Number::SwitchBase(int newBase) {
	int n = convertToBaseTen(value, base);
	char* newValue = convertToBase(n, newBase);
	value = newValue;
	base = newBase;
}

void Number::Print() {
	for (int i = 0; value[i] != NULL; i++) {
		cout << value[i];
	}
	cout << endl;
}

int Number::GetDigitsCount() {
	return strlen(value);
}

int Number::GetBase() {
	return base;
}

int Number::getBaseTen() {
	int n = convertToBaseTen(value, base);
	return n;
}


int Number::convertToBaseTen(char* s, int base) {

	int n = 0, p = 1;

	for (int i = strlen(value) - 1; i >= 0; i--) {
		n += Convertire(s[i]) * p;
		p *= base;
	}

	return n;
}

char* Number::convertToBase(int n, int base) {

	char* c = new char[50];
	int i = 0;

	while (n != 0) {
		int d = n % base;
		c[i++] = Convertire2(d);
		n /= base;
	}
	c[i] = '\0';

	for (int l = 0; l < i / 2; l++)
		swap(c[l], c[i - l - 1]);
	return c;
}

int Number::Convertire(char c) {
	if (c >= 'A')
		c = c - 'A' + 10;
	else
		c = c - '0';
	return c;
}

char Number::Convertire2(int n) {
	if (n >= 10)
		n = 'A' + (n - 10);
	else
		n = '0' + n;
	return n;
}

//functie ajutatoare
char* toString(int n) {
	char* s = new char[50];
	int i = 0;

	while (n != 0) {
		int d = n % 10;
		s[i++] = '0' + d;
		n /= 10;
	}

	s[i] = '\0';

	for (int l = 0; l < i / 2; l++) 
		swap (s[l], s[i - l - 1]);


	return s;
}
