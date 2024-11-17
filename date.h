#pragma once
#include <iostream>
using namespace std;

class date
{
	// массив дней недели по которому будет происходить смещение по ним во время операций
	char** weekdays = new char*[7];
	int day, month, year;
	// переменная содержащая индекс по которому мы получаем значение из массива дней недели
	int week_day;
public:

	// конструкторы

	date() : date(1, 1, 2000, 0) { }
	explicit date(int dayP) : date(dayP, 1, 2000, 0) {}
	date(int dayP, int monthP) : date(dayP, monthP, 2000, 0) {}
	date(int dayP, int monthP, int yearP) : date(dayP, monthP, yearP, 0) {}
	date(int dayP, int monthP, int yearP, int week_dayP) : day{ dayP }, month{ monthP }, year{ yearP }, week_day{ week_dayP }
	{
		// выделение памяти и заполнение массива дней недели
		for (int i = 0; i < 7; i++)
		{
			weekdays[i] = new char[25];
		}

		strcpy_s(weekdays[0], 25, "Monday");
		strcpy_s(weekdays[1], 25, "Tuesday");
		strcpy_s(weekdays[2], 25, "Wednesday");
		strcpy_s(weekdays[3], 25, "Thursday");
		strcpy_s(weekdays[4], 25, "Friday");
		strcpy_s(weekdays[5], 25, "Saturday");
		strcpy_s(weekdays[6], 25, "Sunday");
	}
	date(const date& obj) : day{ obj.day }, month{ obj.month }, year{ obj.year }
	{
		// копирование массива дней недели из полученного (для сокращения кол-ва строк)
		for (int i = 0; i < 7; i++)
		{
			weekdays[i] = new char[25] {*obj.weekdays[i]};
		}

		week_day = obj.week_day;
	}

	// модификаторы

	void set_day(int dayP) { day = dayP; }
	void set_month(int monthP) { day = monthP; }
	void set_year(int yearP) { day = yearP; }
	void set_week_day(int week_dayP) { week_day = week_dayP; }

	// методы

	int differ(const date& obj) const;
	void print_date()const;

	// аксессоры

	int get_day()const { return day; }
	int get_month()const { return month; }
	int get_year()const { return year; }
	int get_week_day()const { return week_day; }

	// перегрузки

	friend date operator+(date& obj, int x);
	friend date operator-(date& obj, int x);
	friend date operator+(int x, date& obj);
	friend date operator-(int x, date& obj);
	date& operator++();
	date& operator--();

	friend ostream& operator<<(ostream& cout, const date& obj);
 
	friend istream& operator>>(istream& cin, date& obj);

	friend bool operator==(const date& obj, const date& obj2) { return (obj.day == obj2.day && obj.month == obj2.month && obj.year == obj2.year && obj.week_day == obj2.week_day); }
	friend bool operator!=(const date& obj, const date& obj2) { return (obj.day != obj2.day && obj.month != obj2.month && obj.year != obj2.year && obj.week_day != obj2.week_day); }
	friend bool operator>(const date& obj, const date& obj2) { return (obj.day > obj2.day && obj.month > obj2.month && obj.year > obj2.year && obj.week_day > obj2.week_day); }
	friend bool operator<(const date& obj, const date& obj2) { return (obj.day < obj2.day && obj.month < obj2.month && obj.year < obj2.year && obj.week_day < obj2.week_day); }
	friend bool operator>=(const date& obj, const date& obj2) { return (obj.day >= obj2.day && obj.month >= obj.month && obj.year >= obj2.year && obj.week_day >= obj2.week_day); }
	friend bool operator<=(const date& obj, const date& obj2) { return (obj.day <= obj2.day && obj.month <= obj2.month && obj.year <= obj2.year && obj.week_day <= obj2.week_day); }

	friend date operator+=(date& obj, int x);
	friend date operator-=(date& obj, int x);
	friend int operator+=(int x, date& obj);
	friend int operator-=(int x, date& obj);

	date& operator=(const date& obj);

	// деструктор

	~date()
	{
		delete[] weekdays;
	}
};

