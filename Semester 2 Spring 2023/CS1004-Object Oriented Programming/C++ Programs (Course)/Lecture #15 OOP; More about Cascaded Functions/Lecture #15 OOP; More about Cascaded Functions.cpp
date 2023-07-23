#include<iostream> 
using namespace std; 

class A 
{ 
	int val;
public:
	A(int a = 5)
	{ 
		cout << a << "param\n"; 
		val = a; 
	} 
	
	A(const A& obj) 
	{ 
		cout << "copy\n";
	} 
	
	~A() 
	{ 
		cout << "dest\n"; 
	} 
	
	A set(int n)
	{ 
		val = n; 
		return *this;
	} 
	
	A myFunc(A obj) 
	{ 
		return obj;
	} 
	
	A okay() 
	{
		cout << "okay\n"; 
		return *this;
	} 
	
	A display()
	{ 
		cout << "display\n";
		return *this; 
	} 
	
	A noice() 
	{ 
		cout << "noice\n"; 
		return *this; 
	} 
};

void main() 
{
	{
		A obj3, obj1 = obj3; 
		obj3.okay().display().noice().set(6); //Cascaded Call
	} 
	system("pause"); 
}