#include<iostream>
#include<string>
using namespace std;

class invalidDay
{
	int day;
public:
	invalidDay(int num)
	{
		day = num;
	}

	int getday()
	{
		return day;
	}

	string message()
	{
		return " is an Invalid Day!";
	}
};

class invalidMonth
{
	int month;
public:
	invalidMonth(int num)
	{
		month = num;
	}

	int getmonth()
	{
		return month;
	}

	string message()
	{
		return " is an Invalid Month!";
	}
};

class invalidYear
{
	int year;
public:
	invalidYear(int num)
	{
		year = num;
	}

	int getyear()
	{
		return year;
	}

	string message()
	{
		if (year< 0)
		{
			return " is an Invalid Year!";
		}
		else
		{
			return " is not a LEAP Year";
		}
		
	}
};

int main()
{
	int month;
	int day;
	int year;
	
	try
	{
		cout << "Enter the date of birth" << endl;
		cout << "Enter the MONTH NUMBER: ";
		cin >> month;
		cout << "Enter the DAY NUMBER: ";
		cin >> day;
		cout << "Enter the Year NUMBER: ";
		cin >> year;
		cout << endl;

		if (year<0)
		{
			throw invalidYear(year);
		}

		if ((month<1) || (month>12))
		{
			throw invalidMonth(month);
		}

		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
		{
			if (day<1 || day>31)
			{
				throw invalidDay(day);
			}
		}
		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		{
			if (day<1 || day>30)
			{
				throw invalidDay(day);
			}
		}
		else
		{
			if ((year % 4) == 0)
			{
				if ((day<1) || (day>29))
				{
					throw invalidDay(day);
				}
			}
			else
			{
				if ((day<1) || (day>28))
				{
					if (day == 29)
					{
						throw invalidYear(year);
					}
					else
					{
						throw invalidDay(day);
					}
				}
			}
		}
		
		switch (month)
		{
		case 1:
			cout << "January ";
			break;
		case 2:
			cout << "February ";
			break;
		case 3:
			cout << "March ";
			break;
		case 4:
			cout << "April ";
			break;
		case 5:
			cout << "May ";
			break;
		case 6:
			cout << "June ";
			break;
		case 7:
			cout << "July ";
			break;
		case 8:
			cout << "August ";
			break;
		case 9:
			cout << "September ";
			break;
		case 10:
			cout << "October ";
			break;
		case 11:
			cout << "November ";
			break;
		case 12:
			cout << "December ";
			break;
		}

		cout << day << ", " << year << endl;
    }
	catch (invalidMonth obj)
	{
		cout << obj.getmonth() << obj.message() << endl;
	}
	catch (invalidDay obj)
	{
		cout << obj.getday() << obj.message() << endl;
	}
	catch (invalidYear obj)
	{
		cout << obj.getyear() << obj.message() << endl;
	}

	cout << endl;
	system("pause");
}