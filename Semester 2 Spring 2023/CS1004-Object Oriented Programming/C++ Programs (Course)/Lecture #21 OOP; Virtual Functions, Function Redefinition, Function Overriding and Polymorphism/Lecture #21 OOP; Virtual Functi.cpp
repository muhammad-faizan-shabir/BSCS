#include<iostream>
using namespace std;

class Parent
{
	// Data member(s)
public:
	Parent()
	{
		cout << "Parent's Constructor" << endl;
	}

	virtual ~Parent()
	{
		cout << "Parent's Destructor" << endl;
	}

    virtual void display()
	{
		cout << "Display inside Parent" << endl;
	}
};

class Child : public Parent
{
	// Data Member(s)
public:
	int z;
	Child()
	{
		cout << "Child's Constructor" << endl;
	}

	~Child()
	{
		cout << "Child's Destructor" << endl;
	}

	void display()
	{
		cout << "Display inside Child" << endl;
	}
};

int main()
{ 
	{
		Child obj1;
		obj1.display();
		obj1.Parent::display();
		
		Child*obj2 = new Child;
		obj2->display();
		obj2->Parent::display();
		delete obj2;
		
		//Parent *ptr3 = new Parent; (correct)
		
		Parent *ptr = new Child; // ptr holds the address of parent of the child, not the child

		//Child *ptr1 = new Parent; (wrong)
		
		//Child *ptr2 = new Child; (correct)

		ptr->display(); // without the use of virtual, this was call parent's display but with virtual this will call child's display
		ptr->Parent::display();// calling display of parent forcefully when virtual is bieng used
		delete ptr;
	}
	cout << endl;
	system("pause");
}