#include <iostream>
using namespace std;
int main()
{
	int num1;
	int num2;
	int diff;
	int multiplesOfThree;
	int multiplesOfFive;


	cout << "Enter first integer: " << endl;
	cin >> num1;
	cout << "Enter second integer: " << endl;
	cin >> num2;

	diff = num1 - num2;

	if(diff<0)
	{
		diff = diff * -1;
	}

	multiplesOfThree = (diff / 3) + 1;

	multiplesOfFive = (diff / 5) + 1;

	cout << multiplesOfThree << " numbers are multiples of 3" << endl;

	cout << multiplesOfFive << " numbers are multiples of 5" << endl;



}