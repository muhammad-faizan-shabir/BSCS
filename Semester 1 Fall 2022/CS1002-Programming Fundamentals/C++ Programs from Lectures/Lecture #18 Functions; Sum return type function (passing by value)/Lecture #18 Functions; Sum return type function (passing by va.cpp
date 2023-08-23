#include <iostream>
using namespace std;

int sum (int x ,int y)
{
	int z = x + y;
	return z;
}

int main()
{
	int a;
	int b;
	int result;

	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;

	result = sum(a, b);
	
	cout << "The sum is: " << result;

}