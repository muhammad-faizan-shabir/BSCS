#include <iostream>
using namespace std;
int main()
{
	float num=0;
	float sum = 0;

	while(1)
	{
		cout << "Enter a positive number" << endl;
		cin >> num;
		if (num < 0)
		{
			cout << "You entered a negative number, the program will end" << endl;
			break;
		}
		sum = sum + num;

	}
	cout << "The sum is: " << sum << endl;
}