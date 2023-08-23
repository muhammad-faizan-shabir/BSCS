#include<iostream>
#include<string>
using namespace std;

double divide(int numerator, int denominator)
{
	//if denominator is zero then calculation should not be done
	if (denominator == 0)
	{
		string s = "Denominator cannot be zero";
		throw s;
	}
	else
	{
		return ((double)numerator) / denominator;
	}
}

int main()
{
	cout << "First try:" << endl;
	try
	{
		cout << divide(4, 6) << endl;
	}
	catch (string e)
	{
		cout << e << endl;
	}

	cout << endl << "Second try:" << endl;
	try
	{
		cout << divide(4, 0) << endl;
	}
	catch (string e)
	{
		cout << e << endl;
	}

	cout << endl;
	system("pause");
	return 0; 
}