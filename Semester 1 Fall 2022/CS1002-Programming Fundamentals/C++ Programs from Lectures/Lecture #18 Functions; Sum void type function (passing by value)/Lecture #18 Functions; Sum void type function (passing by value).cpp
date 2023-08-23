#include <iostream>
using namespace std;

void sum(int a , int b)
{
	cout << "The sum is: " << a + b;
}

int main()
{
	int a;
	int b;

	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;

	sum(a, b);
}