// a program that calulates x raise to power y
#include <iostream>
using namespace std;
int main()
{
	int x;
	int y;
	int result = 1;
	int n = 1;
	
	cout << "Enter integer base x: " << endl;
	cin >> x;

	cout << "Enter integer exponent y: " << endl;
	cin >> y;

	while(n<=y)
	{
		result = result * x;
		n = n + 1;
	}

	cout << "The answer is: " << result << endl;

}
