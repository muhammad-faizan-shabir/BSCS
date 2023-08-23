// a program that prints a matrix of numbers 
#include <iostream>
using namespace std;
int main()
{
	int i;
	int j;
	int x=1;
	int y=1;

	cout << "Enter the number of rows: " << endl;
	cin >> i;

	cout << "Enter the number of columns" << endl;
	cin >> j;

	while(x<=i)
	{
		y = 1;
		while(y<=j)
		{
			cout << y;
			y++;
		}
		cout << endl;
		x++;

	}

}