#include <iostream>

using namespace std;
int main()
{
	
	int spaces = 0; // for spaces
	int s = 1; // for spaces
	int i = 1; //for outer loop
	int j = 5; //for inner loop
	int x = 1; //for inner loop
	int a = -1; // for inner loop
	int b = 1; // for spaces

	while(i<=9)
	{
		s = 1;
		while(s<=spaces)
		{
			cout << " ";
			s = s + 1;
		}
		x = 1;
		while(x<=j)
		{
			cout << "* ";
			x = x + 1;
		}
		if (j==1)
		{
			a = 1;
			b = -1;
		}
	
		j = j + a;
		spaces = spaces + b;
		cout << endl;
		i = i + 1;
	}
}