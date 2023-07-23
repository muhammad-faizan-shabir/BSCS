#include<iostream>
using namespace std;

class Int
{
	int a;
public:
	Int(int n = 0)
	{
		a = n;
	}

	Int operator++() // for pre operation
	{
		++a;
		return *this;
	}

	Int operator++(int) // for post operation
	{
		Int obj1(a);
		a++;
		return obj1;
	}

	friend ostream&operator<<(ostream &strm, const Int &obj)
	{
		strm << obj.a;
		return strm;
	}

	friend istream&operator>>(istream &strm, Int &obj)
	{
		strm >> obj.a;
		return strm;
	}
};

int main()
{
	Int a = 5;
	Int b = a++;

	cout << b << endl << a << endl << endl;

	++a;

	cout << b << endl << a << endl << endl;
	
	b = ++a;

	cout << b << endl << a << endl << endl;

	system("pause");
}