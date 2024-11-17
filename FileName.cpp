#include "date.h"

int main()
{
	setlocale(LC_ALL, "russian");

	// проверка одной из перегрузок

	date obj{ 13, 1, 2008, 0};

	obj += 364;
	cout << obj;

	return 0;
}