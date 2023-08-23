#include<iostream>
using namespace std;

class Parent // abstract base class
{
public:
	virtual void show() = 0; // pure virtual function
};

class Child: public Parent
{
public:
	void show()
	{
		cout << "Show" << endl;
	}
};

int main()
{
	Child c;
	Parent* obj=&c;
	obj->show();
	
	cout << endl;
	system("pause");
}