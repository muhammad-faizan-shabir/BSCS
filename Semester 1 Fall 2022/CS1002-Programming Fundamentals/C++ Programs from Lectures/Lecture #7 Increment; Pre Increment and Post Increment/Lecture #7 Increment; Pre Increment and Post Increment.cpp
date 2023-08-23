#include <iostream>
using namespace std;
int main()
{
	int i = 0;
	// i++ is post increment
	// ++i is pre increment
	
	cout << "Value of i before post increment is: " << i << endl;
	cout << "Value of i after post increment is: " << i++ << endl << endl;

	cout << "Value of i before pre increment is: " << i << endl;
	cout << "Value of i after pre increment is: " << ++i << endl;
}