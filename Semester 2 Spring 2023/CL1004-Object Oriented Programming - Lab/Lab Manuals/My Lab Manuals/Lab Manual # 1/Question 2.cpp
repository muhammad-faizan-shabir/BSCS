#include <iostream>
using namespace std;

int SUM(int& num1, int& num2)
{
	return(num1 + num2);
}

int main()
{
	int num1;
	int num2;

	cout << "Enter fisrt integer: ";
	cin >> num1;

	cout << "Enter second integer: ";
	cin >> num2;

	cout << "The value returned by the SUM function is: " << SUM(num1, num2) << endl << endl;

	system("pause");
}