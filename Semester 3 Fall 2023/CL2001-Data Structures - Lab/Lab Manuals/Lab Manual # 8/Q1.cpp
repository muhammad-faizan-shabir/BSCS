#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0) // base case
	{
		return b;
	}
	else // general case
	{
		return gcd(b % a, a);
	}
}

int main()
{
	int a = 10, b = 15;
	cout << "GCD of " << a << " and " << b << " = " << gcd(a, b) << endl;
	
	a = 35, b = 10;
	cout << "GCD of " << a << " and " << b << " = " << gcd(a, b) << endl;
	
	a = 31, b = 2;
	cout << "GCD of " << a << " and " << b << " = " << gcd(a, b) << endl;
	
	a = 36, b = 60;
	cout << "GCD of " << a << " and " << b << " = " << gcd(a, b) << endl;
	
	cout << endl;
	system("pause");
	return 0;
}

