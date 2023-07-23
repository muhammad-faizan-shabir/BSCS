#include <iostream>
using namespace std;
int main()
{
	
	int x = 1; // for outer loop
	int y = 1; //for inner loop

	while(x<=4)
	{
		if (x % 2 == 0)
		{
			cout << " ";

		}
		y = 1;
		while(y<=11)
		{
			cout << "-" << " ";
			y = y + 1;
		}
		cout << endl;
		x = x + 1;
	}
}