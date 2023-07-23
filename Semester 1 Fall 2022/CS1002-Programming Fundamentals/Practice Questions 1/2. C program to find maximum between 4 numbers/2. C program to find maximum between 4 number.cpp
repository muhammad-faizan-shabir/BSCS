//C program to find maximum between 4 numbers
#include <iostream>
using namespace std;
int main()
{
	int num1, num2, num3, num4;
	cout << "Enter four differet integers:" << endl;
	cout << "Enter first integer: " << endl;
	cin >> num1;
	cout << "Enter second integer: " << endl;
	cin >> num2;
	cout << "Enter third integer: " << endl;
	cin >> num3;
	cout << "Enter fourth integer: " << endl;
	cin >> num4;
	if((num1>num2)&&(num1>num3)&&(num1>num4))
	{
		cout << "First number is greatest" << endl;
	}
	if ((num2 > num1) && (num2 > num3) && (num2 > num4))
	{
		cout << "Second number is greatest" << endl;
	}
	if ((num3 > num2) && (num3 > num1) && (num3 > num4))
	{
		cout << "Third number is greatest" << endl;
	}
	if ((num4 > num2) && (num4 > num3) && (num4 > num1))
	{
		cout << "Fourth number is greatest" << endl;
	}
		
	
}