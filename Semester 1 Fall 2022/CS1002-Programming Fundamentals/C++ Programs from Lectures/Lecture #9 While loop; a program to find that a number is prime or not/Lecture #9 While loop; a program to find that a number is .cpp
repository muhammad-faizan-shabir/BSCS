#include <iostream>
using namespace std;
int main()
{
	int n;
	int i = 2;
	bool IsPrime = true;

	cout << "Enter a number to find whether it is prime or not" << endl;
	cin >> n;

	if(n==0||n==1||n==-1)
	{
		cout << "1,-1,0 are not prime numbers" << endl;
		IsPrime = false;
	}
	else
	{
		if(n<0)
		{
			n = n * -1;
		}
		while(i<n)
		{
			if(n%i==0)
			{
				IsPrime = false;
				break;
			}
			i++;
		}
	}

	if(IsPrime)
	{
		cout << "Number is prime" << endl;
	}
	else
	{
		cout << "Number is not prime" << endl;
	}
}