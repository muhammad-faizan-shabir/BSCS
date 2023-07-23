#include <iostream>
using namespace std;

void IsPrime(int num1, int num2)
{
	int a = num1;

	for (; a <= num2; a++)
	{
		int temp = 2;
		bool prime = true;
		int temp2 = a;

		if (a == -1 || a == 0 || a == 1)
		{
			prime = false;
		}

		if (a < 0)
		{
			temp2 = temp2*-1;
		}


		for (; temp < temp2;temp++)
		{
			
			if ((temp2%temp) == 0)
			{
				prime = false;
				break;
			}
		}

		if (prime == true)
		{
			cout << a << endl;
		}

	}
}

int main()
{
	int num1;
	int num2;

	cout << "Enter first number: ";
	cin >> num1;

	cout << "Enter second number: ";
	cin >> num2;

	IsPrime(num1, num2);

	
}