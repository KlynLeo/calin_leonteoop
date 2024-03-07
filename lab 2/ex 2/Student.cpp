#include <iostream>
#include "Student.h"
using namespace std;

void Student::SetName(const char nume[]) {
	strcpy_s(Name, nume);
}
char* Student::GetName() {
	return Name;
}
void Student::SetMath(float nota_mate) {
	Math = nota_mate;
}
float Student::GetMath() {
	return Math;
}
void Student::SetEnglish(float nota_eng) {
	English = nota_eng;
}
float Student::GetEnglish() {
	return English;
}
void Student::SetHistory(float nota_ist) {
	History = nota_ist;
}
float Student::GetHistory() {
	return History;
}
float Student::GetAvg() {
	return (Math + English + History) / 3;
}