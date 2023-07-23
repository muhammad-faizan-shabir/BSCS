#include <iostream>
using namespace std;

bool oddEven(int num)
{
	if(num%2==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int num;
	cout << "Enter an integer number: ";
	cin >> num;

	if(oddEven(num))
	{
		cout << "The number is even" << endl;
	}
	else
	{
		cout << "The number is odd" << endl;
	}
}