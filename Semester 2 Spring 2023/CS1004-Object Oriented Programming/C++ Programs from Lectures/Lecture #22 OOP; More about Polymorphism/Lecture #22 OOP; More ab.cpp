#include<iostream>
using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "Parent's Constructor" << endl;
	}
	virtual~Parent()
	{
		cout << "Parent's Destructor" << endl;
	}
	virtual void display() const
	{
		cout << "Display Inside Parent" << endl;
	}
};

class Child : public Parent
{
public:
	Child()
	{
		cout << "Child's Constructor" << endl;
	}
	~Child()
	{
		cout << "Child's Destructor" << endl;
	}
	void display() const
	{
		cout << "Display Inside Child" << endl;
	}
};

int main()
{
	{
		Child c;
		cout << endl;
		// there is polymorphism
		//Parent &obj = c;

		// there is polymorphism
		//Parent *obj = &c;

		// there is no polymorphism
		//Parent obj = c;

		//obj.display();
		//obj->display();
		cout << endl;
	}
	cout << endl;
	system("pause");
}
