#include <iostream>
using namespace std;
int main()
{
	int num; // the number entered by user
	int temp1; // first digit that makes up the sum
	int temp2; // second digit that makes up the sum
	int n; // the number of total combinations that sum to give the entered number
	bool prime1; // flag to check whether first digit is prime or not
	bool prime2; // flag to check whether second digit is prime or not
	bool atLeastOneSum = false; // this flag will remain false if the entered number cannot be expressed as a sum of prime numbers

	cout << "Input a Positive Integer: ";
	cin >> num;
	cout << endl;
	

	if(num%2==0) 
	{
		n = num / 2; // calculating the combinations of sums if number is even
	}
	else
	{
		n = ((num + 1) / 2) - 1;  // calculating the combinations of sums if number is odd
	}

	for(int i = 1;i<=n;i++) // loop will run for total number of combinations of sums
	{
		prime1 = true;
		prime2 = true;
		
		temp1 = i; // first digit that makes up the sum
		int j = 2; //starting from 2 since number is obviously divisible by 1
		if (temp1 == 1) // checking if first digit is prime or not
		{
			
			prime1 = false;
		}
		else
		{
			while (j < temp1) // checking if first digit is prime or not
			{
				if (temp1 % j == 0)
				{
					prime1 = false;
					break;
				}
				j++;
			}
		}

		temp2 = num - i;  // second digit that makes up the sum
	    j = 2; //starting from 2 since number is obviously divisible by 1
		if (temp2 == 1) // checking if second digit is prime or not
		{

			prime2 = false;
		}
		else
		{
			while (j < temp2) // checking if second digit is prime or not
			{
				if (temp2 % j == 0)
				{
					prime2 = false;
					break;
				}
				j++;
			}
		}

		if((prime1==true)&&(prime2==true)) // checking if whole combination of first and second digit is prime
		{
			atLeastOneSum = true;
			cout << num << " = " << temp1 << " + " << temp2 << endl;
		}
	}

	if(atLeastOneSum == false) // checking if the number cannot be expressed as a sum of prime numbers
	{
		cout << "This number cannot be expressed as a sum of prime numbers" << endl;
	}
}