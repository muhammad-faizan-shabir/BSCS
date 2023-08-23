#include<iostream>
using namespace std;

class A
{
public:
	void func() const
	{
	}
};

int main()
{
	const A obj;

	obj.func(); // since obj is constant so func() can only be called if it is a constant member function 
}