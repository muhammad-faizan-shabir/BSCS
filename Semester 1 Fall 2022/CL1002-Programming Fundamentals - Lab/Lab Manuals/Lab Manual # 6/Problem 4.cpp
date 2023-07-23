#include <iostream>
using namespace std;
int main()
{
	int i = 1; // for outer loop
	int j = 1; // for inner sibling loop
	int k = 1; // for inner sibling loop
	int spaces = 3; // for spaces
	int stars = 1; // for number of stars

	for(i;i<=4;i++)
	{
		for(j=1;j<=spaces;j++)
		{
			cout << " ";
		}

		for(k=1;k<=stars;k++)
		{
			cout << "*";
		}
		spaces = spaces -1;
		stars = stars + 2;

		cout << endl;
	}
	

}