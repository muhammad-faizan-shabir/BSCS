#include <iostream>
using namespace std;
int main()
{
	int num;
	cout << "Enter an integer" << endl;
	cin >> num;
	if(num>=0)
	{
		cout << "The number entered is positive" << endl;
		if ((num >= 0) && (num <= 10))
		{
			cout << "Number is in the range 0-10"<<endl;
		}
		else if ((num >= 11) && (num <= 20)) 
		{
			cout << "Number is in the range 11-20" << endl;
		}
		else if((num>=21)&&(num<=30))
		{
			cout << "number is in the range 21-30" << endl;
		}
		else if ((num >= 31) && (num <= 40))
		{
			cout << "number is in the range 31-40" << endl;
		}
		else if ((num >= 41) && (num <= 50)) 
		{
			cout << "number is in the range 41-50" << endl;
		}
		else
		{
			cout << "number is greater than 50" << endl;
		}
		
		
		if((num%2)==0)
		{
			cout << "Number is even" << endl;

		}
		else
		{
			cout << "Number is odd" << endl;
		}
	}
	else
	{
		cout << "The number entered is not positive" << endl;
	}
}