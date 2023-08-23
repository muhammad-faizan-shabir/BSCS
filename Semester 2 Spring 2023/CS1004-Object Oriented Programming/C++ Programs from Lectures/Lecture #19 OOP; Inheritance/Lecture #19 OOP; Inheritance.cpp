#include<iostream>
using namespace std;

class A
{
	int a;
public:
	A()
	{
		cout << "Constructor A" << endl;
		a = 0;
	}

	~A()
	{
		cout << "Destructor A" << endl;
	}

	void display()
	{
		cout << a << endl;
	}

	void SetA(int n)
	{
		a = n;
	}

	int GetA()
	{
		return a;
	}
};

class B : public A
{
	int b;
public:
	B()
	{
		cout << "Constructor B" << endl;
		b = 1;
	}

	~B()
	{
		cout << "Destructor B" << endl;
	}

	void print()
	{
		cout << b << endl;
	}

	void SetB(int n)
	{
		b = n;
	}

	int GetB()
	{
		return b;
	}
};

int main()
{
	{
		A obj1;
		obj1.display();
		obj1.SetA(15);
		cout << obj1.GetA() << endl << endl;
		
		B obj2;
		obj2.display();
		obj2.SetA(7);
		cout<<obj2.GetA()<<endl;
		obj2.print();
		obj2.SetB(4);
		cout<<obj2.GetB() << endl;
	}
	cout << endl;
	system("pause");
}