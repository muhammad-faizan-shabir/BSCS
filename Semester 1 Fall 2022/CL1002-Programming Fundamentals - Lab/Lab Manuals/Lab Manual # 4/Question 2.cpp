#include <iostream>
using namespace std;
int main()
{
	float num1;
	float num2;
	float result;
	char operation;

	cout << "Enter first number" << endl;
	cin >> num1;
	cout << "Enter second number" << endl;
	cin >> num2;

	cout << "Enter operation: +,-,*,/" <<endl;
	cin >> operation;

	switch (operation)
	{
	case '+':
		result = num1 + num2;
		cout << "The sum is: " << result << endl;
		break;
	case '-':
		result = num1 - num2;
		cout << "The difference is: " << result << endl;
		break;
	case '*':
		result = num1 * num2;
		cout << "The product is: " << result << endl;
		break;
	case '/':
		if(num2!=0)
		{
			result = num1 / num2;
			cout << "The quotient is: " << result << endl;
		}
		else
		{
			cout << "Error! Division by zero is not possible" << endl;
		}
		break;
	default:
		cout << "Error! wrong operation is entered" << endl;
		break;
	}
}