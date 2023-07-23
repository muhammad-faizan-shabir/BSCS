#include <iostream>
using namespace std;
int main()
{
	int spaces1 = 0; //for spaces
	int spaces2 = 1; //for spaces
	int s1=1; //for spaces
	int s2 = 2; //for spaces
	int x = 1; //for outer loop
	int y = 1; //for inner loop
	int n = 9; // for inner loop
	while(x<=5)
	{
		s1 = 1;
		while(s1<=spaces1)
		{
			cout << " ";
			s1 = s1 + 1;
		}
		
		y = 1;
		while(y<=n)
		{
			cout << y;
			y = y + 1;
		}
		
		s2 = 1;
		if(x!=1)
		{
			while(s2<=spaces2)
			{
				cout << " ";
				s2 = s2 + 1;
			}
		}
		y = 1;
		while (y <= n)
		{
			cout << y;
			y = y + 1;
		}
		spaces1 = spaces1 + 1;
		spaces2 = spaces2 + 2;
		n = n - 2;
		cout << endl;
		x = x + 1;



	}

}