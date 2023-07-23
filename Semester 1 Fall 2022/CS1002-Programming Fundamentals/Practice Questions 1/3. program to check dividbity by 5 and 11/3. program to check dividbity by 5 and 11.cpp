//program to check dividbity by 5 and 11
#include <iostream>
using namespace std;
int main()
{
	int num;
	cout << "Enter an integr" << endl;
	cin >> num;
	if(num%5==0)
	{
		cout << "Number is divisible by 5" << endl;
	}
	else if (num % 11 == 0)
	{
		cout << "Number is divisible by 11" << endl;
	}
	else
	{
		cout << "Number is not divisble by either 5 or 11" << endl;
	}

}