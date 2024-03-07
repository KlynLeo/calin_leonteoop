#include <iostream>
#include "Global functions.h"
using namespace std;

int ComparaLaNume(Student* p1, Student* p2) {
	if (strcmp(p1->GetName(), p2->GetName()) > 0)
		return 1;
	else if (strcmp(p1->GetName(), p2->GetName()))
		return -1;
	return 0;
}

int ComparaLaMate(Student* p1, Student* p2) {
	if (p1->GetMath() > p2->GetMath())
		return 1;
	else if (p1->GetMath() < p2->GetMath())
		return -1;
	return 0;
}

int ComparaLaEng(Student p1, Student p2) {
	if (p1.GetEnglish() > p2.GetEnglish())
		return 1;
	else if (p1.GetEnglish() < p2.GetEnglish())
		return -1;
	return 0;
}

int ComparaLaIstorie(Student& p1, Student& p2) {
	if (p1.GetHistory() > p2.GetHistory())
		return 1;
	else if (p1.GetHistory() < p2.GetHistory())
		return -1;
	return 0;
}

int ComparaLaMedie(Student& p1, Student& p2) {
	if (p1.GetAvg() > p2.GetAvg())
		return 1;
	else if (p1.GetAvg() < p2.GetAvg())
		return -1;
	return 0;
}