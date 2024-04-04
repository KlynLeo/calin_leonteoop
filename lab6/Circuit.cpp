#include <iostream>
#include "Car.h"
#include "Weather.h"
#include "Circuit.h"
#include <string>

using namespace std;

Circuit::Circuit(int desiredCars)
{
	cars = new Car* [desiredCars];
}

void Circuit::SetLength(int lungime)
{
	length = lungime;
}

void Circuit::SetWeather(int vreme)
{
	weather = vreme;
}

void Circuit::AddCar(Car* tip_masina)
{
	nr_cars++;
	cars[nr_cars] = tip_masina;
}

void Circuit::swap(int i, int j)
{
	Car* aux = cars[i];
	cars[i] = cars[j];
	cars[j] = aux;

	float auxi = EndTimeCircuit[i];
	EndTimeCircuit[i] = EndTimeCircuit[j];
	EndTimeCircuit[j] = auxi;

	bool a = finish[i];
	finish[i] = finish[j];
	finish[j] = a;
}

void Circuit::sort_race_time()
{
	for (int i = 1; i <= nr_cars - 1; i++) 
		for (int j = 1; j <= nr_cars - i; j++)
			if (EndTimeCircuit[j] > EndTimeCircuit[j + 1])
				swap(j, j + 1);
}

void Circuit::Race()
{
	for (int i = 1; i <= nr_cars; i++)
	{
		bool Finish;
		EndTimeCircuit[i] = cars[i]->calculateTime(weather, length, Finish);
		finish[i] = Finish;
	}
	sort_race_time(); // descending sort
}

void Circuit::ShowFinalRanks()
{
	cout << "Clasamentul final este: " << endl;
	int rank = 1;
	for (int i = 1; i <= nr_cars; i++)
	{
		if (finish[i] != 0)
			cout << cars[i]->GetName() << ": " << rank << " (A terminat cursa in mai putin de " << EndTimeCircuit[i]+1 << " ore)" << endl;
		if ((i < nr_cars) && (EndTimeCircuit[i] == EndTimeCircuit[i + 1]))
			continue;
		rank++;
	} //nu va fi un clasament foarte specific, ci le va ranka in functie de numarul de ore in care termina cursa.
	//putem spune ca cele care o termina in mai putin de o ora sunt de rank 1, cele care termina in mai putin de 2 sunt rank 2 etc.
}

void Circuit::ShowWhoDidNotFinish()
{
	cout << "Masinile care nu au terminat cursa sunt: " << endl;
	int ok = 0;
	for (int i = 1; i <= nr_cars; i++)
		if (finish[i] == 0) {
			cout << cars[i]->GetName() << endl;
			ok = 1;
		}
	if (ok == 0)
		cout << "Toate masinile au reusit sa termine cursa";
}