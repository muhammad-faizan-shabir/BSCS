#include<iostream>
using namespace std;

class A;
class B
{
	int b;
public:
	B(int n = 5)
	{
		b = n;
	}

	void display(A);
};

class A
{
	int a;
	friend void B::display(A);
public:
	A(int n = 9)
	{
		a = n;
	}
	// any logic
};

void B::display(A obj)
{
	// your logic
	cout << obj.a << endl;
}

void main()
{
	A obj1;
	B obj2;
	obj2.display(obj1);
	//any logic
	system("pause");
}


