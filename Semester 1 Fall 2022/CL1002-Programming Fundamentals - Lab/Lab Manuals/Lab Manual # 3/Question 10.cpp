#include <iostream>
using namespace std;
int main()
{
	char operation;
	int num1;
	int num2;
	float result;
	
	cout << "Enter first integer number: " << endl;
	cin >> num1;
	
	cout << "Enter second integer number: " << endl;
	cin >> num2;
	
	cout << "Enter operator: +,-,*,%,/" << endl;
	cin >> operation;
	
	if (operation == '+')
	{
		result = num1 + num2;
		cout << "The sum is: " << result << endl;
	}
	else if (operation=='-')
	{
		result = num1 - num2;
		cout << "The difference is: " << result << endl;
	}
	else if (operation == '*')
	{
		result = num1 * num2;
		cout << "The product is: " << result << endl;
	}
	else if (operation =='%')
	{
		result = num1 % num2;
		cout << "The remainder from the division is: " << result << endl;
	}
	else if(operation== '/')
	{
		if (num2!=0)
		{
			result = (num1 / num2);
			cout << "The quotient is: " << result << endl;
		}
		else
		{
			cout << "Error! Division by zero is not possible" << endl;
		}
	}
	else
	{
		cout << "Error! Wrong operator is chosen" << endl;
	}
}