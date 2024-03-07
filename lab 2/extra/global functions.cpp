#include <iostream>
#include "movies.h"

int compare_name(Movie f1, Movie f2) {
	if (strcmp(f1.GetName(), f2.GetName()) > 0)
		return 1;
	else if (strcmp(f1.GetName(), f2.GetName()) < 0)
		return -1;
	return 0;
}
int compare_year(Movie f1, Movie f2) {
	if (f1.GetRy() > f2.GetRy())
		return 1;
	else if (f1.GetRy() < f2.GetRy())
		return -1;
	return 0;
}
int compare_score(Movie f1, Movie f2) {
	if (f1.GetIMDB() > f2.GetIMDB())
		return 1;
	else if (f1.GetIMDB() < f2.GetIMDB())
		return -1;
	return 0;
}
int compare_length(Movie f1, Movie f2) {
	if (f1.Getlength() > f2.Getlength())
		return 1;
	else if (f1.Getlength() < f2.Getlength())
		return -1;
	return 0;
}
int compare_passed_years(Movie f1, Movie f2) {
	if (f1.passed_years() > f2.passed_years())
		return 1;
	else if (f1.passed_years() < f2.passed_years())
		return -1;
	return 0;
}