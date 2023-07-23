#include <iostream>
using namespace std;

class FeetInches
{
	int feet;
	int inches;

	void  simplify()
	{
		if((inches>=12)||(inches<0))
		{
			for(;inches>=12;)
			{
				inches = inches - 12;
				feet = feet + 1;
			}
		}
	}

public:
	// Constructor
	FeetInches(int f = 0,int i=0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	// There is no need for a Copy Constructor
	
	// There is no need to Overload Assignment Operator 

	// Setters
	void setFeet(int f)
	{
		feet = f;
	}
	void setInches(int i)
	{
		inches = i;
	}
	
	// Getters
	int getFeet()
	{
		return feet;
	}
	int getInches()
	{
		return inches;
	}

	// Operator Overloading for  +,-,*,/,>,<,>=,<=
	void operator+(const FeetInches &obj)
	{
		cout << "Addition Operator" << endl;
		// some logic
	}
	
	void operator-(const FeetInches& obj)
	{
		cout << "Subtraction Operator" << endl;
		// some logic
	}

	void operator*(const FeetInches& obj)
	{
		cout << "Multiplication Operator" << endl;
		// some  logic
	}

	void operator/(const FeetInches& obj)
	{
		cout << "Division Operator" << endl;
		// some logic
	}

	void operator>(const FeetInches& obj)
	{
		cout << "> Operator" << endl;
		// some logic
	}

	void operator<(const FeetInches& obj)
	{
		cout << "< Operator" << endl;
		// some logic
	}

	void operator>=(const FeetInches& obj)
	{
		cout << ">= Operator" << endl;
		// some logic
	}

	void operator<=(const FeetInches& obj)
	{
		cout << "<= Operator" << endl;
		// some logic
	}
};

int main()
{
	FeetInches f1;
	cout << "f1 data: " << endl;
	cout << f1.getFeet() << " feet " << f1.getInches() << " inches" << endl << endl;

	FeetInches f2 = f1;
	cout << "f2 data: " << endl;
	cout << f2.getFeet() << " feet " << f2.getInches() << " inches" << endl << endl;

	FeetInches f3(5, 18);
	cout << "f3 data: " << endl;
	cout << f3.getFeet() << " feet " << f3.getInches() << " inches" << endl << endl;

	f1 = f3;
	cout << "f1 data: " << endl;
	cout << f1.getFeet() << " feet " << f1.getInches() << " inches" << endl << endl;

	cout << "f3 data: " << endl;
	cout << f3.getFeet() << " feet " << f3.getInches() << " inches" << endl << endl;
	
	system("pause");
	return 0;
}