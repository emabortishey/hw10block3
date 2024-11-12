#include "date.h"

void date::print_date() const
{
	cout << day << '\t' << month << '\t' << year << '\t' << week_day;
}

int date::differ(const date& obj) const
{
	int buff_day = day, buff_month = month, buff_year = year;
	int buff_day2 = obj.day, buff_month2 = obj.month, buff_year2 = obj.year;
	int diff_days;

	buff_year *= 365;
	buff_month *= 31;
	buff_day += buff_year + buff_month;

	buff_year2 *= 365;
	buff_month2 *= 31;
	buff_day2 += buff_year2 + buff_month2;

	if (buff_day > buff_day2)
	{
		diff_days = buff_day - buff_day2;
	}
	else if (buff_day < buff_day2)
	{
		diff_days = buff_day2 - buff_day;
	}
	else
	{
		cout << "\nРазницы нет";
		return 0;
	}

	buff_year = diff_days / 365;
	buff_month = (diff_days % 365) / 31;
	buff_day = ((diff_days % 365) % 31);

	cout << "\nРазница между датами (дни месяцы годы): ";
	cout << '\n' << buff_day << '\t' << buff_month << '\t' << buff_year;

	cout << "\nРазница между датами в днях: " << diff_days;

	return 1;
}


date& date::operator=(const date& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	day = obj.day;
	month = obj.month;
	year = obj.year;
	this->set_week_day(obj.week_day);

	return *this;
}

date operator+(date& obj, int x)
{
	int buff_day{ obj.day }, buff_month{ obj.month }, buff_year{ obj.year }, buff_week_day{ obj.week_day };

	if (x >= 31 - obj.day && x < (365 - (obj.month * 31 + obj.day)))
	{
		buff_month += x / 31;
		buff_day += x % 31;
	}
	else if (x > 365)
	{
		buff_year += x / 365;
		buff_month += (x % 365) / 31;
		buff_day += (x % 365) % 31;
	}
	else
	{
		buff_day += x;
	}

	if (buff_week_day + (x % 7) > 6)
	{
		buff_week_day = 0;
	}
	else
	{
		buff_week_day += x % 7;
	}

	date buff{ buff_day, buff_month, buff_year, buff_week_day }; 

	return buff;
}
date operator+(int x, date& obj)
{
	int buff_day{ obj.day }, buff_month{ obj.month }, buff_year{ obj.year }, buff_week_day{ obj.week_day };

	if (x >= 31 - obj.day && x < (365 - (obj.month * 31 + obj.day)))
	{
		buff_month += x / 31;
		buff_day += x % 31;
	}
	else if (x > 365)
	{
		buff_year += x / 365;
		buff_month += (x % 365) / 31;
		buff_day += (x % 365) % 31;
	}
	else
	{
		buff_day += x;
	}

	if (buff_week_day + (x % 7) > 6)
	{
		buff_week_day = 0;
	}
	else
	{
		buff_week_day += x % 7;
	}

	date buff{ buff_day, buff_month, buff_year, buff_week_day };

	return buff;
}

date operator-(date& obj, int x)
{
	int buff_day{ obj.day }, buff_month{ obj.month }, buff_year{ obj.year }, buff_week_day{ obj.week_day };

	if (x >= 31 - obj.day && x < (365 - (obj.month * 31 + obj.day)))
	{
		buff_month -= x / 31;
		buff_day -= x % 31;
	}
	else if (x > 365)
	{
		buff_year -= x / 365;
		buff_month -= (x % 365) / 31;
		buff_day -= (x % 365) % 31;
	}
	else
	{
		buff_day -= x;
	}

	if (buff_week_day - (x % 7) < 0)
	{
		buff_week_day = 0;
	}
	else
	{
		buff_week_day += x % 7;
	}

	date buff{ buff_day, buff_month, buff_year, buff_week_day };

	return buff;
}

date operator-(int x, date& obj)
{
	int buff_day{ obj.day }, buff_month{ obj.month }, buff_year{ obj.year }, buff_week_day{obj.week_day};

	if (x >= 31 - obj.day && x < (365 - (obj.month * 31 + obj.day)))
	{
		buff_month -= x / 31;
		buff_day -= x % 31;
	}
	else if (x > 365)
	{
		buff_year -= x / 365;
		buff_month -= (x % 365) / 31;
		buff_day -= (x % 365) % 31;
	}
	else
	{
		buff_day -= x;
	}

	date buff{ buff_day, buff_month, buff_year, buff_week_day };

	return buff;
}

date& date::operator++()
{
	if (day + 1 > 31 && (month * 31 - day) + 1 < 365)
	{
		month++;
		day = 1;
	}
	else if (month * 32 - day + 1 > 365)
	{
		year++;
		month = 1;
		day = 1;
	}
	else
	{
		day++;
	}

	if (week_day == 6)
	{
		week_day = 0;
	}
	else
	{
		week_day++;
	}

	return *this;
}

date& date::operator--()
{
	if (day - 1 < 1 && month - 1 >= 1)
	{
		month--;
		day = 31;
	}
	else if (day - 1 < 1 && month - 1 < 1)
	{
		year--;
		month = 12;
		day = 31;
	}
	else
	{
		day--;
	}

	if (week_day == 0)
	{
		week_day = 6;
	}
	else
	{
		week_day--;
	}

	return *this;
}

ostream& operator<<(ostream& cout, const date& obj)
{
	cout << obj.day << '\t' << obj.month << '\t' << obj.year << '\t' << obj.weekdays[obj.week_day];
	return cout;
}

istream& operator>>(istream& cin, date& obj)
{
	cin >> obj.day >> obj.month >> obj.year >> obj.week_day;

	return cin;
}