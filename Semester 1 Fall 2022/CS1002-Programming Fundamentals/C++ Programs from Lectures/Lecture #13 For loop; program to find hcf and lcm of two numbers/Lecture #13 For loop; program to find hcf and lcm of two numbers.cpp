// program to find hcf and lcm of two numbers
#include <iostream>
using namespace std;
int main()
{
	int num1;
	int num2;
	int hcf ;
	int lcm;

	cout << "Enter first number: ";
	cin >> num1;

	cout << "Enter second number: ";
	cin >> num2;

	if (num1 > num2)
	{
		int temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	for (int i = num1; i >= 1; i--)
	{
		if (((num1 % i)==0) && ((num2 % i)==0))
		{
			hcf = i;
			break;
		}
	}

	cout << "HCF is: " << hcf << endl;

	lcm = (num1 * num2) / hcf;

	cout << "LCM is: " << lcm;
}