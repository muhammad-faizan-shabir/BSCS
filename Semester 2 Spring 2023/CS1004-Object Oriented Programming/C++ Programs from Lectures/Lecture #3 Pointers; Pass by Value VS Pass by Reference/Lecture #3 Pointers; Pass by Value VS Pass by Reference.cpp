#include <iostream>
using namespace std;

void func(int num)
{
	num = 5;
}

void func2(int &num)
{
	num = 10;
}

void main()
{
	int num = 2;
	cout << num << endl;

	func(num);
	cout << num << endl;

	func2(num);
	cout << num << endl;
}