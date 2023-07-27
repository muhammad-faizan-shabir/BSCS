#include<iostream>
using namespace std;

class Base
{
public:
	void func1()
	{
		cout << "func1()" << endl;
	}
	void show()
	{
		cout << "show()" << endl;
	}
};

class Derived : public Base
{
public:
	void display()
	{
		cout << "display()" << endl;
	}
};

int main()
{
	Derived obj;
	
	Base*obj1 = &obj; // This is Upcasting (Polymorphism)
	obj1->func1();
	obj1->show();

	Derived *obj2 = (Derived*)obj1; // This is Downcasting
	obj2->display();
	
	cout << endl;
	system("pause");
}