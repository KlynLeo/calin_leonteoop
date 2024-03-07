#pragma once
class Movie {
	public:
		char name[256];
		int year;
		double score;
		int length;
	public:
		void set_name(const char nume[]);
		char* GetName();

		void set_year(int anul);
		int GetRy();

		void set_score(double scorul);
		double GetIMDB();

		void set_length(int lungimea);
		int Getlength();

		int passed_years();
};