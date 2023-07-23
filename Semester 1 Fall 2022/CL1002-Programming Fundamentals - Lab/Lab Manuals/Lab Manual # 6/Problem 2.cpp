#include <iostream>
using namespace std;
int main()
{
	int i = 4; // counter for outer loop
	int j = 1; // counter for inner loop
	int k = 4; // counter for inner loop
	while(i>=1)
	{
		j = 1;
		while(j<=k)
		{
			cout <<i<<" ";
			j++;
		}
		i--; // for outer loop
		k--; // for inner loop

		cout << endl;
	}
}