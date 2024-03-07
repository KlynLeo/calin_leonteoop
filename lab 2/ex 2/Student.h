#pragma once
#include <iostream>

class Student {
private:
	char Name[50];
	float Math;
	float English;
	float History;
	float AvgGrade;
public:
	void SetName(const char nume[]);
	char* GetName();

	void SetMath(float nota_mate);
	float GetMath();

	void SetEnglish(float nota_eng);
	float GetEnglish();

	void SetHistory(float nota_ist);
	float GetHistory();

	float GetAvg();
};