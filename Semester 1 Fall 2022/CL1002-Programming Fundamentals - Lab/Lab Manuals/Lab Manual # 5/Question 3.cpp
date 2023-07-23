#include <iostream>
using namespace std;
int main()
{
	int spaces = 0; // for spaces
	int s = 1;      //for spaces
	int i;  // for outer loop
	int x = 1;  //for outer loop
	int j = 1; //for inner loop
	int y = 1; //for inner loop
	int a = 1; //for inner loop
	int b = -1; //for spaces
	int rows;

	cout << "Enter number of rows: " << endl;
	cin >> rows;

	i = rows + (rows - 1);
	spaces = rows - 1;
	while(x<=i)
	{
		s = 1;
		while(s<=spaces)
		{
			cout << " ";
			s++;
		}
		y = 1;
		while(y<=j)
		{
			cout << "* ";
			y = y + 1;
		}
		
		if(j==rows)
		{
			a = -1;
			b = 1;
		}
		j = j + a;
		spaces = spaces + b;
		cout << endl;
		x = x + 1;

	}
}