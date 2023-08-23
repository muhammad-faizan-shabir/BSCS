#include<iostream>
using namespace std;

class B;
class A
{
	int a;
	friend class B;
public:
	A()
	{
		a = 0;
	}
};

class B
{
	int b;
public:
	B()
	{
		b = 0;
	}
	
	void display(A obj)
	{
		obj.a = 46;
		cout << obj.a << endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	obj2.display(obj1);

	cout << endl;
	system("pause");
}