#include <iostream>
#include "Math.h"
#include <cstring>
#include <cstdarg>
int Math::Add(int a, int b) {
	return a + b;
}
int Math::Add(int a, int b, int c) {
	return a + b + c;
}
int Math::Add(double a, double b) {
	return a + b;
}
int Math::Add(double a, double b, double c) {
	return a + b + c;
}
int Math::Mul(int a, int b){
	return a * b;
}
int Math::Mul(int a, int b, int c) {
	return a * b * c;
}
int Math::Mul(double a, double b) {
	return a * b;
}
int Math::Mul(double a, double b, double c) {
	return a * b * c;
}
int Math::Add(int count, ...)
	{
		va_list args;
		va_start(args, count);
		int rez = 0;
		while (count != 0)
		{
			int elem = va_arg(args, int);
			rez = rez + elem;
			count--;
		}
		va_end(args);
		return rez;
	}
char* Math::Add(const char* s1, const char* s2) {
	if (s1 == nullptr || s2 == nullptr)
		return nullptr;
	else {
		size_t len1 = strlen(s1);
		size_t len2 = strlen(s2);
		char* res = new char[len1 + len2 + 1];
		strcpy_s(res, len1 + len2 + 1, s1);
		strcat_s(res, len1 + len2 + 1, s2);
		return res;
	}
}
