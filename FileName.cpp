#include "date.h"

int main()
{
	setlocale(LC_ALL, "russian");

	date obj{ 13, 1, 1, 0};
	date obj2{ 12, 1, 2008 };


	/*obj.differ(obj2);

	if (obj > obj2)
	{
		cout << 1;
	}

	cout << "Hello";*/
	//obj.print_date();

	cout << 410 - obj << "\n\n\n" << 1 % 7;

	return 0;
}