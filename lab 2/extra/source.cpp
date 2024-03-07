#include <iostream>
#include "movies.h"
using namespace std;

void Movie::set_name(const char nume[]) {
	strcpy_s(name, nume);
}
char* Movie::GetName() {
	return name;
}
void Movie::set_year(int anul) {
	year = anul;
}
int Movie::GetRy() {
	return year;
}

void Movie::set_score(double scorul) {
	score = scorul;
}
double Movie::GetIMDB() {
	return score;
}

void Movie::set_length(int lungimea) {
	length = lungimea;
}
int Movie::Getlength() {
	return length;
}

int Movie::passed_years() {
	return (2024 - year);
}