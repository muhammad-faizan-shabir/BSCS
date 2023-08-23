#include<iostream>
using namespace std;

class A
{
	int x;
protected:
	int y;
public:
	int z;
	
	A()
	{
		x = 1;
		y = 2;
		z = 3;
	}

	void display()
	{
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << "z: " << z << endl;
	}
};

class B : public A
{
	int b;
public:
	void print()
	{
		//x = 5; inaccessble since private in A class
		y = 10;
		z = 15;

		//cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << "z: " << z << endl;
		cout << "okay" << endl;
	}
};

int main()
{
	B obj;
	obj.display();
	cout << endl;
	obj.print();
	
	cout << endl;
	system("pause");
}