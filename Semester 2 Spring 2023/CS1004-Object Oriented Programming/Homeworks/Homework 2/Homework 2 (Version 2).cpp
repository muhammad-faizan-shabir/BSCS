#include <iostream>
using namespace std;

class FeetInches
{
	int feet;
	int inches;
public:
	void  simplify()
	{
		if ((inches >= 12) || (inches<0))
		{
			for (; inches >= 12;)
			{
				inches = inches - 12;
				feet = feet + 1;
			}
		}
	}

	// Constructor
	FeetInches(int f = 0, int i = 0)
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
		simplify();
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
	FeetInches operator+(const FeetInches &obj)
	{
		cout << "Addition Operator" << endl;
		FeetInches A;
		A.feet = feet + obj.feet;
		A.inches = inches + obj.inches;
		A.simplify();
		return A;
	}

	FeetInches operator-(const FeetInches& obj)
	{
		cout << "Subtraction operator" << endl;
		FeetInches A;
		A.inches = ((feet * 12) + inches) - ((obj.feet * 12) + obj.inches);
		A.simplify();
		return A;
	}

	FeetInches operator*(const FeetInches& obj)
	{
		cout << "Multiplication Operator" << endl;
		FeetInches A;
		A.feet = 0;
		A.inches = (((feet * 12) + inches) * ((obj.feet * 12) + obj.inches));
		A.simplify();
		return A;
	}

	FeetInches operator/(const FeetInches& obj)
	{
		cout << "Division Operator" << endl;
		FeetInches A;
		A.feet = 0;
		A.inches = (((feet * 12) + inches) / ((obj.feet * 12) + obj.inches));
		A.simplify();
		return A;
	}

	bool operator>(const FeetInches& obj)
	{
		cout << "> Operator" << endl;
		bool status;
		if (feet>obj.feet)
		{
			status = true;
		}
		else if ((feet == obj.feet) && (inches>obj.inches))
		{
			status =true;
		}
		else
		{
			status = false;
		}
		return status;
	}

	bool operator<(const FeetInches& obj)
	{
		cout << "< Operator" << endl;
		bool status;
		if (feet<obj.feet)
		{
			status = true;
		}
		else if ((feet == obj.feet) && (inches<obj.inches))
		{
			status = true;
		}
		else
		{
			status = false;
		}
		return status;
	}

	bool operator>=(const FeetInches& obj)
	{
		cout << ">= Operator" << endl;
		bool status;
		if (feet>obj.feet)
		{
			status = true;
		}
		else if ((feet == obj.feet) && (inches>obj.inches))
		{
			status = true;
		}
		else if ((feet == obj.feet) && (inches==obj.inches))
		{
			status = true;
		}
		else
		{
			status = false;
		}
		return status;
	}

	bool operator<=(const FeetInches& obj)
	{
		cout << "<= Operator" << endl;
		bool status;
		if (feet<obj.feet)
		{
			status = true;
		}
		else if ((feet == obj.feet) && (inches<obj.inches))
		{
			status = true;
		}
		else if ((feet == obj.feet) && (inches == obj.inches))
		{
			status = true;
		}
		else
		{
			status = false;
		}
		return status;
	}
};

int main()
{
	cout << "Checking the simplify() member function: " << endl;
	FeetInches obj1(6, 50);
	cout << "Before simplify() called: Feet = " << 6 << " Inches = " << 50 << endl;
	cout<< "After simplify() called: Feet = " << obj1.getFeet() << " Inches = " << obj1.getInches() << endl;
	cout << endl;

	cout << "Checking overloaded operators with obj2(4,2) and obj3(3,4)" << endl << endl;

	cout << "Checking overloaded + operator: " << endl;
	FeetInches obj2(4, 2);
	FeetInches obj3(3, 4);
	obj1 = obj2 + obj3;
	cout << "Feet = " << obj1.getFeet() << " Inches = " << obj1.getInches() << endl;
	cout << endl;

	cout << "Checking overloaded - operator: " << endl;
	obj1 = obj2 - obj3;
	cout << "Feet = " << obj1.getFeet() << " Inches = " << obj1.getInches() << endl;
	cout << endl;

	cout << "Checking overloaded * operator: " << endl;
	obj1 = obj2 * obj3;
	cout << "Feet = " << obj1.getFeet() << " Inches = " << obj1.getInches() << endl;
	cout << endl;

	cout << "Checking overloaded / operator: " << endl;
	obj1 = obj2 / obj3;
	cout << "Feet = " << obj1.getFeet() << " Inches = " << obj1.getInches() << endl;
	cout << endl;

	cout << "Checking overloaded > operator: " << endl;
	if(obj2>obj3)
	{
		cout << "obj2 is greater than obj3" << endl;
	}
	else
	{
		cout << "obj3 is greater than obj2" << endl;
	}
	cout << endl;

	cout << "Checking overloaded < operator: " << endl;
	if (obj2 < obj3)
	{
		cout << "obj2 is lesser than obj3" << endl;
	}
	else
	{
		cout << "obj3 is lesser than obj2" << endl;
	}
	cout << endl;

	cout << "Checking overloaded >= operator: " << endl;
	if (obj2 >= obj3)
	{
		cout << "obj2 is greater equal to obj3" << endl;
	}
	else
	{
		cout << "obj3 is greater equal to obj2" << endl;
	}
	cout << endl;

	cout << "Checking overloaded <= operator: " << endl;
	if (obj2 <= obj3)
	{
		cout << "obj2 is lesser equal to obj3" << endl;
	}
	else
	{
		cout << "obj3 is lesser equal to obj2" << endl;
	}
	cout << endl;
	
	system("pause");
	return 0;
}