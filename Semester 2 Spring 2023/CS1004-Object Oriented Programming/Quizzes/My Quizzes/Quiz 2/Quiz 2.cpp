#include<iostream> 
using namespace std;

class A 
{
private: 
	int* a; 
public: 
	A(int _a = 0) 
	{
		cout << "A() Called for " << _a << ".\n"; 
		a = new int; 
		*a = _a; 
	} 
	void Print() 
	{ 
		cout << "a =\t" << *a << endl; 
	} 
	A(const A& rhs) 
	{ 
		cout << "Copy Constructor Called.\n"; 
	} 
	void operator=(const A& rhs) 
	{ 
		cout << "Assignment Operator Callsed.\n"; 
	}
	   
	~A() 
	{ 
		if (a != 0) 
		{ 
			cout << "~A() Called for " << *a << ".\n"; 
			delete a;
		} 
	} 
	void SetA(int _a) 
	{
		*a = _a;
	}
}; 

void main() 
{ 
	A obj1(5);
	{ 
		A obj2 = obj1; 
		obj2.SetA(10);
		obj2.Print(); 
	} 
	obj1.Print();
}