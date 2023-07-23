#include<iostream>
using namespace std;

class A
{
	int a;
	friend void display(A);
public:
	A(int n = 3)
	{
		a = n;
	}
	// other functions
};

void display(A obj)
{
	obj.a = 4;
	cout << obj.a << endl;
}// end of display()

void main()
{
	A obj1(9);
	display(obj1);
	system("pause");
}