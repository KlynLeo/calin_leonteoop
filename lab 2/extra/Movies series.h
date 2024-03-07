#pragma once
#include "movies.h"
class MovieSeries {
	private:
		int count;
		Movie* vector[16];
	public:
		void Init();
		bool Add(Movie* p1);
		void Sort();
		void Print();
};