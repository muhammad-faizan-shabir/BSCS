#include <iostream>
using namespace std;
int main()
{
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	cout << "Enter five different integers: " << endl;
	cin >> num1 >> num2 >> num3 >> num4 >> num5;
	
	if((num1>num2)&&(num1>num3)&&(num1>num4)&&(num1>num5))
	{
		cout << "Largest number is: " << num1 << endl;
	}
	if ((num2 > num1) && (num2 > num3) && (num2 > num4) && (num2 > num5))
	{
		cout << "Largest number is: " << num2 << endl;
	}
	if ((num3 > num2) && (num3 > num4) && (num3 > num5) && (num3 > num1))
	{
		cout << "Largest number is: " << num3 << endl;
	}
	if ((num4 > num1) && (num4 > num2) && (num4 > num3) && (num4 > num5))
	{
		cout << "Largest number is: " << num4 << endl;
	}
	if ((num5 > num1) && (num5 > num2) && (num5 > num3) && (num5 > num4))
	{
		cout << "Largest number is: " << num5 << endl;
	}
	
	if ((num1 < num2) && (num1 < num3) && (num1 < num4) && (num1 < num5))
	{
		cout << "Smallest number is: " << num1 << endl;
	}
	if ((num2 < num1) && (num2 < num3) && (num2 < num4) && (num2 < num5))
	{
		cout << "Smallest number is: " << num2 << endl;
	}
	if ((num3 < num2) && (num3 < num4) && (num3 < num5) && (num3 < num1))
	{
		cout << "Smallest number is: " << num3 << endl;
	}
	if ((num4 < num1) && (num4 < num2) && (num4 < num3) && (num4 < num5))
	{
		cout << "Smallest number is: " << num4 << endl;
	}
	if ((num5 < num1) && (num5 < num2) && (num5 < num3) && (num5 < num4))
	{
		cout << "Smallest number is: " << num5 << endl;
	}





}