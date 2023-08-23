#include <iostream>
using namespace std;

void func1(int *p)
{
	*p = 10;
}

void func2(int &*p) // this is a pointer to a reference and this is illegal in c++
// so this code will not work
{
	int x = 3;
	p = &x;
	*p = 10;
}

int * func3()
{
	int x = 5;
	return &x;
}

void main()
{
	int num = 2;
	
	func1(&num);
	cout << num << endl;
	
	func2(&num);
	cout << num << endl;
	
	cout << func3();
}