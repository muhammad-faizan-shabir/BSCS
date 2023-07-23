//do while loop
#include <iostream>
using namespace std;
int main()
{
	char c;
	
	do
	{
		cout << "Enter +,-,*" << endl;
		cout << "Enter q to quit" << endl;
		cin >> c;
		if (c=='+')
		{
			cout << "Addition" << endl;
		}
		if(c=='-')
		{
			cout << "Subtraction" << endl;
		}
		if(c=='*')
		{
			cout << "Product" << endl;
		}
	} while (c != 'q');
}