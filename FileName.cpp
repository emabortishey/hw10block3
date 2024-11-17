#include "date.h"

int main()
{
	setlocale(LC_ALL, "russian");

	date obj{ 13, 1, 2008, 0};
	date obj2{ 12, 1, 2008, 1 };


	/*obj.differ(obj2);

	if (obj > obj2)
	{
		cout << 1;
	}

	cout << "Hello";*/
	//obj.print_date();

	obj += 364;
	cout << obj;

	int buff_year, buff_month, buff_day, diff_days = 733328;

	buff_year = diff_days / 365;
	buff_month = (diff_days % 365) / 31;
	buff_day = ((diff_days % 365) % 31);

	cout << buff_day << '\t' << buff_month << '\t' << buff_year;

	//cout << obj;

	return 0;
}