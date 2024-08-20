#include <iostream>;
using namespace std;

class Frac
{
	int numerator;
	int denominator;

	int HCF(int a, int b) 
	{
		while (b != 0) 
		{
			int remainder = a % b;
			a = b;
			b = remainder;
		}
		return a;
	}
	
public:
	
	Frac(int numerator=0, int denominator=1)
	{
		int hcf = HCF(numerator, denominator);
		this->numerator = numerator / hcf;
		this->denominator = denominator / hcf;
	}

	Frac operator*(const Frac&rhs)
	{
		int tempNumerator = this->numerator * rhs.numerator;
		int tempDenominator = this->denominator * rhs.denominator;
		Frac product(tempNumerator,tempDenominator);
		return product;
	}

	Frac operator+(const Frac&rhs)
	{
		int tempDenominator = this->numerator * rhs.denominator;
		int tempNumerator = ((this->numerator) * (tempDenominator / this->denominator)) + ((rhs.numerator) * (tempDenominator / rhs.denominator));
		Frac addition(tempNumerator,tempDenominator);
		return addition;
	}

	friend ostream& operator<<(ostream& os, const Frac& frac) 
	{
		os << frac.numerator << '/' << frac.denominator;
		return os;
	}
};

int main()
{
	Frac f1(50, 100);
	Frac f2(75, 100);

	Frac f3, f4;

	f3 = f1 * f2;
	f4 = f1 + f2;

	cout << "Fraction 1: " << f1 << endl;
	cout << "Fraction 2: " << f2 << endl;
	cout<<"Product: " << f3 << endl;
	cout<< "Addition: " << f4 << endl;

	return 0;
}



