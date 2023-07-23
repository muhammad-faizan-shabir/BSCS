// a program that prints all even numbers beween 1 and 100
#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	while (n<=100)
	{
		n = n + 1;
		if (n % 2 == 0)
		{
			cout << n << endl;
		}
	}
}