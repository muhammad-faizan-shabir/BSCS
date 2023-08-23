#include <iostream>
using namespace std;
int main()
{
	int num;
	cout << "enter a number:" << endl;
	cin >> num;
	if ((num % 2) == 0)
	{
		cout << "Number is even" << endl;
	}
	else
	{
		cout << "Number is odd";
	}
}