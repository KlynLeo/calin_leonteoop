#include <iostream>
#include "Movies series.h"
using namespace std;
void MovieSeries::Init() {
	count = 0;
}
bool MovieSeries::Add(Movie* p1) {
	if (count >= 16)
		return false;
	else {
		vector[count] = p1;
		count++;
	}
}
void MovieSeries::Sort() {
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
			if (vector[i]->passed_years() > vector[j]->passed_years()){
				int aux = vector[i]->passed_years();
				vector[i]->passed_years() = vector[j]->passed_years();
				vector[j]->passed_years() = aux;
			}
}
void MovieSeries::Print() {
	for (int i = 0; i < count; i++) {
		cout << "Numele filmului: " << vector[i]->GetName() << endl;
		cout << "Anul lansarii: " << vector[i]->GetRy() << endl;
		cout << "Scorul IMDB: " << vector[i]->GetIMDB() << endl;
		cout << "Durata: "<< vector[i]->Getlength() << " minute" << endl;
		cout << "Acum cati ani a fost lansat: " << vector[i]->passed_years() << endl << endl << endl;
	}
}
