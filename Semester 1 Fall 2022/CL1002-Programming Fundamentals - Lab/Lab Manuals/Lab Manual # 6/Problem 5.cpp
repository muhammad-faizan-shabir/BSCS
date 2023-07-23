#include <iostream>
using namespace std;
int main()
{
	int i = 1; // for outer loop
	int j = 1; // for inner sibling loop
	int k = 1; // for inner sibling loop
	int spaces = 3; // for spaces
	int stars = 1; // for number of stars
	int spaces2 =6 ; 

	for (i; i <= 4; i++)
	{
		for (j = 1; j <= spaces; j++)
		{
			cout << " ";
		}

		for (k = 1; k <= stars; k++)
		{
			cout << "*";
		}
		for (j = 1; j <= spaces2; j++)
		{
			cout << " ";
		}
		for (k = 1; k <= stars; k++)
		{
			cout << "*";
		}
		spaces = spaces - 1;
		stars = stars + 2;
		spaces2 = spaces2 - 2;

		cout << endl;
	}
	cout << "**FAIZAN6552**" << endl;

	spaces = 0;
	stars = 14;
	for(i=1;i<=7;i++)
	{
		for(j=1;j<=spaces;j++)
		{
			cout << " ";
		}
		for(j=1;j<=stars;j++)
		{
			cout << "*";
		}
		spaces++;
		stars = stars - 2;
		cout << endl;
	}

	
}
