#include <iostream>
using namespace std;

void max(int a,int b,int c)
{
	if((a>b)&&(a>c))
	{
		cout << "First number is greatest" << endl;
	}
	if((b>c)&&(b>a))
	{
		cout << "Second number is greatest" << endl;
	}
	if((c>a)&&(c>b))
	{
		cout << "Third number is greatest" << endl;
	}
}

int main()
{
	int a, b, c;

	cout << "Enter first number" << endl;
	cin >> a;

	cout << "Enter second number" << endl;
	cin >> b;

	cout << "Enter third number" << endl;
	cin >> c;

	max(a, b, c);
}