#include <iostream>
using namespace std;
int main()
{
	int i = 1; // for outer loop
	int j = 5; //for inner loop
	int x = 1; //for spaces
	int a = -1; //for inner loop

	while(i<=9)
	{
		x = 1;
		while(x<=j)
		{
			cout << "*";
			x = x + 1;
		}
		if(j==1)
		{
			a = 1;
			
		}
		j = j + a;
		i = i + 1;
		cout << endl;



	}
}