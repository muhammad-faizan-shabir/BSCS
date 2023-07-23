#include <iostream>
#include <cstring>
#include <cstringt.h>

using namespace std;
int main()
{
	double g = 1; // initial guess for square root
	double N; // number whose square root is to be calculated
	string terminate ="0"; // variable to terminate loop

	cout << "Enter a positive number to find square root: ";
	cin >> N;

	for(;terminate!="-1";)
	{
		g = (g + N / g) / 2;
		cout << "Enter -1 to exist otherwise press any number or alphabet to continue: ";
		cin >> terminate;
	}
	cout << "The approximate square root is: " << g;
}