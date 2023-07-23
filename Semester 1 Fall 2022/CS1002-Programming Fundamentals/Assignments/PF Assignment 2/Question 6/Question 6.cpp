#include <iostream>
using namespace std;
int main()
{
	int num;
	cout << "Enter an integer" << endl;
	cin >> num;
	if(num== 0)
	{
		cout << "The number entered is zero" << endl;
	}
	else if(num>0)
	{
		cout << "The number entered is positive" << endl;
	}
	else
	{
		cout << "The number entered is negative" << endl;
	}
}