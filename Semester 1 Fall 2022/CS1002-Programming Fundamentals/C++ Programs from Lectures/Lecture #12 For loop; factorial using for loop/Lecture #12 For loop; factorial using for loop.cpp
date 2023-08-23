// factorial using for loop
#include <iostream>
using namespace std;
int main()
{
	long long int fact = 1;
	int i;
	cout << "Enter number to get its factorial" << endl;
	cin >> i;
	for(i;i>=1;i--)
	{
		fact = fact * i;
	}
	cout << "Factorial is: " << fact;
}