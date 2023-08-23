#include <iostream>
using namespace std;

class A
{
	int a;
	double b;
public:
	A()
	{
		a = 5;
		b = 7.8;
		cout << "My non-parameterized constructor " << endl;
	}

	A(int n1,double n2)
	{
		a = n1;
		b = n2;
		cout << "Parameterized constructor " << endl;
	}
};

int main()
{
	A obj1; // will run the non-parameterized constructor 

	A obj2(7, 8.5); // will run the parameterized constructor

	A obj3(); // will run the default constructor
}