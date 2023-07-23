// a program that prints sum of numbers from 1-10
#include <iostream>
using namespace std;
int main()
{
	int sum = 0;
	int i = 1;
	while(i<=10)
	{
		sum = sum + i;
		i = i + 1;
	}
	cout << "Sum of numbers 1-10 is:" << sum << endl;
}