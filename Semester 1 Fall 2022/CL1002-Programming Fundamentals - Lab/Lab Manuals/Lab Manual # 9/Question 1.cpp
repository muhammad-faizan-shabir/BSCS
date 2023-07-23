#include <iostream>
using namespace std;

void showIntro()
{
	cout << "This prgram will take input in 'cups' and then provide output in 'fluid ounces' " << endl;
}

double getCups()
{
	double cups;
	cout << "Enter number of cups: ";
	cin >> cups;
	return cups;
}

bool isValid(double cups)
{
	if (cups>0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double cupsToOunces(double cups)
{
	return (8.0 * cups);
}

int main()
{
	double cups;
	showIntro();
	cups = getCups();

	if (isValid(cups))
	{
		cout << "The Ounces are: " << cupsToOunces(cups) << endl;
	}
	else
	{
		cout << "Invalid input, the program will exit" << endl;
	}

}