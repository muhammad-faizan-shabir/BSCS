#include<iostream>
using namespace std;

class RationalNumber
{
	int numerator;
	int denominator;
public:
	RationalNumber(int n = 1, int d = 1)
	{
		if (d <= 0)
		{
			numerator = n;
			denominator = 1;
		}
		else
		{
			numerator = n;
			denominator = d;
		}

		if (numerator != 1 && denominator != 1)
		{
			if (numerator > denominator)
			{
				int i;
				for (i = denominator; !(((numerator%i == 0) && (denominator%i == 0))); i--)
				{
				}
				denominator = denominator / i;
				numerator = numerator / i;
			}
			else if (numerator < denominator)
			{
				int i;
				for (i = numerator; !(((numerator%i == 0) && (denominator%i == 0))); i--)
				{
				}
				denominator = denominator / i;
				numerator = numerator / i;
			}
			else
			{
				denominator = 1;
				numerator = 1;
			}
		}
	}

	friend RationalNumber operator+(const RationalNumber& obj1, const RationalNumber&obj2);
	friend RationalNumber operator-(const RationalNumber& obj1, const RationalNumber&obj2);

	void display()
	{
		cout << numerator << "/" << denominator << endl;
	}
};

RationalNumber operator+(const RationalNumber& obj1, const RationalNumber&obj2)
{
	int numerator = 0;
	int denominator = 0;

	numerator = (obj1.numerator*obj2.denominator)+(obj1.denominator*obj2.numerator);
	denominator = obj1.denominator*obj2.denominator;

	RationalNumber temp(numerator, denominator);

	return temp;
}

RationalNumber operator-(const RationalNumber& obj1, const RationalNumber&obj2)
{
	int numerator = 0;
	int denominator = 0;

	numerator = (obj1.numerator*obj2.denominator)-(obj1.denominator*obj2.numerator);
	denominator = obj1.denominator*obj2.denominator;

	RationalNumber temp(numerator, denominator);

	return temp;
}

int main()
{
	RationalNumber obj1(2, 0);
	obj1.display();
	cout << endl;

	RationalNumber obj2(2, -4);
	obj2.display();
	cout << endl;

	RationalNumber obj3(3, 12);
	obj3.display();
	cout << endl;

	RationalNumber obj4;
	obj4.display();
	cout << endl;

	RationalNumber obj5(10, 3);
	RationalNumber obj6(5, 7);

	RationalNumber obj7 = obj5 + obj6;
	obj7.display();
	cout << endl;

	RationalNumber obj8 = obj5 - obj6;
	obj8.display();
	cout << endl;

	system("pause");
}
