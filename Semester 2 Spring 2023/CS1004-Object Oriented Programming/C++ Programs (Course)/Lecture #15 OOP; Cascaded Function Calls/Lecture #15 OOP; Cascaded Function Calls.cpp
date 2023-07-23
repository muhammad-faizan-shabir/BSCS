#include<iostream> 
using namespace std; 

class A 
{ 
	int val; 
public:

	A(int a = 5) 
	{ 
		cout << a << "param\n"; val = a;
	} 
	
	A(const A& obj) 
	{
		cout << "copy\n"; 
	} 
	
	~A() 
	{ 
		cout << "dest\n";
	} 
	
	A myFunc(A obj) 
	{ 
		return obj;
	}

	void okay()
	{
		cout << "okay\n";
	} 
	
	void display() 
	{ 
		cout << "assignment\n"; 
	} 
};

void main()
{
	{
		A obj3, obj1 = obj3; 
		obj3.myFunc(obj1).okay(); //Cascaded Call
	} 
	system("pause");
}