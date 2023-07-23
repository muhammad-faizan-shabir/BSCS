#include <iostream>
using namespace std;
int main()
{
	double g = 1.0; // initial guess of square root
	double N; // number whose square root is to be found

	cout << "Enter a positive number to calculate its square root: ";
	cin >> N;

	for(int i=1;i<=10;i++)
	{
		g = (g + N / g) / 2;
	}
	cout << "The approximate square root is: " << g;
}