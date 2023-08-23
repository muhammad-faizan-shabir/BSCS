#include <iostream>
using namespace std;

void func2(int *&p) // this is a reference to a pointer and this is legal in c++
{
	*p = 10;
}

void main()
{
	int num = 2;
	
	//func2(&num); // this is incorrect because &num is a rvalue and not a lvalue
	               // and a reference can only be assigned with a lvalue

	int* ptr = &num;
	
	func2(ptr); // this is correct because ptr is a lvalue and can also be a rvalue
	            // and a reference can only be assigned with a lvalue 
}