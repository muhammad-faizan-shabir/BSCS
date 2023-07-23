#include<iostream>
using namespace std;

template<class T>
T performOperation(T a, T b, char op)
{
	if (op == '*')
	{
		return(a*b);
	}
	else if (op == '+')
	{
		return (a + b);
	}
	else if (op == '-')
	{
		return(a - b);
	}
	else if (op == '/')
	{
		return(a / b);
	}
	else
	{
		cout << "Wrong operation" << endl;
	}
}

void main()
{
	int a, b; // this can be float, int or double too
	char op;
	cout << "Enter first operand: ";
	cin>>a;
	cout<<"Enter second operand: ";
	cin>>b;
	cout<<"Enter operation(*,+,-,/): ";
	cin>>op; // op can be +, -, * or /
	cout << endl;
	if (op == '*' || op == '+' || op =='-'|| op =='/')
	{
		cout << "Operation performed" << endl;
		cout << "Answer is: "<<performOperation(a, b, op);
	}
	else
	{
		cout << "Wrong operation" << endl;
	}

	cout << endl << endl;
	system("pause");

}

