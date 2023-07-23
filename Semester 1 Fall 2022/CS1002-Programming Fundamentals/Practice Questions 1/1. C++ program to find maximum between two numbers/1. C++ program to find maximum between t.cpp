//C++ program to find maximum between two numbers
#include <iostream>
using namespace std;
int main()
{
	int num1;
	int num2;
	cout << "Enter first integer" << endl;
	cin >> num1;
	cout << "Enter second integer" << endl;
	cin >> num2;
	if (num1==num2)
	{
		cout << "Both Numbers are equal" << endl;
	}
	else if(num1>num2)
	{
		cout << "First number is greater" << endl;
	}
	else
	{
		cout << "Second number is greater" << endl;
	}
}