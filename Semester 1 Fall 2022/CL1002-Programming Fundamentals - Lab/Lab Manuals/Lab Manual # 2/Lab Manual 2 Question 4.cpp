#include <iostream>
using namespace std;
int main()
{
	int num;
	int sum;
	int product;
	cout << "Enter a number between 100000 to 999999" << endl;
	cin >> num;
	if((num>=100000)&&(num<=999999))
	{
		sum = ((num / 100000) % 10) + ((num / 10000) % 10) + ((num / 1000) % 10) + ((num / 100) % 10) + ((num / 10) % 10) + (num % 10);
		product = ((num / 100000) % 10) * ((num / 10000) % 10) * ((num / 1000) % 10) * ((num / 100) % 10) * ((num / 10) % 10) * (num % 10);
		cout << "The sum is: " << sum << endl;
		cout << "The product is: " << product << endl;
	}
	else {
		if(num<100000)
		{
			cout << "NOT A SIX DIGIT NUMBER: TOO SMALL" << endl;
		}
		else
		{
			cout << "NOT A SIX DIGIT NUMBER: TOO LARGE" << endl;
		}
	}
}