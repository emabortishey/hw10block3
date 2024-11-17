#pragma once
#include "date.h"

class stri
{
	char* str;
	int size;

public:

	stri() : stri("none", 80) { }
	stri(const char* str_P) : stri(str_P, strlen(str_P)+1) { }
	stri(const char* str_P, int size_P) : str{ new char[size_P] { *str_P } }, size{size_P} { }
	stri(const stri& obj) : str{ new char[obj.size] { *obj.str } }, size{ obj.size } { }

	void set_str(const char* str_P) {  delete[] str;
		str = new char[strlen(str_P) + 1] {*str_P};
		size = strlen(str_P) + 1; }
	void set_size(int size_P) { size = size_P; }

	const char* get_str() { return str; }
	int get_size() { return size; }

	char operator[](int index) { return str[index]; }
	int operator()(char symb) {
		for (int i = 0; i < size; i++) {
			if (str[i] == symb) { return i; }
		}  return -1;
	}

	operator int() { return size; }
};

