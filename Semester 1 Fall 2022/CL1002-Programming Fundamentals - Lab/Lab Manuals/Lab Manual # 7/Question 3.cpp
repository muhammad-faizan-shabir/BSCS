#include <iostream>
using namespace std;
int main()
{
	int num;
	int remainder;
	cout << "Please enter an integer: ";
	cin >> num;
	


	switch (num)
	{
	case 0:
		cout << "Number entered is zero and even" << endl;
		break;
	default:
		remainder = num % 2;
		switch (remainder)
		{
		case 0:
			if (num > 0)
			{
				cout << "Number entered is positive and even" << endl;
			}
			else if (num < 0)
			{
				cout << "Number entered is negative and even " << endl;
			}
			break;
		default:
			if (num > 0)
			{
				cout << "Number entered is positive and odd" << endl;
			}
			else if (num < 0)
			{
				cout << "Number entered is negative and odd " << endl;
			}
			break;
		}
		break;
	}

	
	
}