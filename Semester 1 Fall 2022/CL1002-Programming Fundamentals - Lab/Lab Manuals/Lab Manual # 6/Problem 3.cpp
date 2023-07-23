#include <iostream>
using namespace std;
int main()
{
	int i = 1; // counter for outer loop
	int j = 1; // counter for inner loop

	do
	{
		j = 1;
		do
		{
			cout << i << " " << j << endl;
			j++;
		} while (j <= 3);
		i++;
	} while (i <= 3);
}