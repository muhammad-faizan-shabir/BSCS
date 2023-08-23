#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int num;
	int length;
	int reverse = 0;
	int n;
	int zeros;

	cout << "Enter number to get its digits as words" << endl;
	cin >> num;

	length = ceil(log10(num));
	

	for (; num > 0; num = num / 10)
	{
		reverse = (reverse * 10) + (num % 10);
	}

	zeros = length - (ceil(log10(reverse)));
	

	for(;reverse>0;reverse=reverse/10)
	{
		n = reverse % 10;
		switch(n)
		{
		case 0:
			cout << "zero ";
			break;
		case 1:
			cout << "one ";
			break;
		case 2:
			cout << "two ";
			break;
		case 3:
			cout << "three ";
			break;
		case 4:
			cout << "four ";
			break;
		case 5:
			cout << "five ";
			break;
		case 6:
			cout << "six ";
			break;
		case 7:
			cout << "seven ";
			break;
		case 8:
			cout << "eight ";
			break;
		case 9:
			cout << "nine ";
			break;
		}
	}

	for(;zeros>=1;zeros--)
	{
		cout << "zero ";
	}


}

	