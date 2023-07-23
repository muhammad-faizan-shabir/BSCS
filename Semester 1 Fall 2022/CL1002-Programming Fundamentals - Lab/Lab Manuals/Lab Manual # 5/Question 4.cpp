#include <iostream>
#include <string>
using namespace std;
int main()
{
	int spaces1 = 0; // for spaces
	int spaces2 = -1; //for spaces
	int s1=1; //for spaces
	int s2=1; //for spaces
	int i; //for outer loop
	int x =1; //for outer loop
	int a = -1; //for spaces
	int b = 2; //for spaces
	int rows;
	string symbol;

	cout << "Enter number of rows: " << endl;
	cin >> rows;

	cout << "Enter symbol to draw with:" << endl;
	cin >> symbol;

	i = rows + (rows - 1);
	spaces1 = rows - 1;
	while(x<=i)
	{
		s1 = 1;
		while(s1<=spaces1)
		{
			cout << " ";
			s1 = s1 + 1;
		}
		
		cout << symbol;

		s2 = 1;
		while(s2<=spaces2)
		{
			cout << " ";
			s2 = s2 + 1;
		}
		
		if((x!=1)&&(x!=i))
		{
			cout << symbol;
		}
		
		if (x == rows)
		{
			a = 1;
			b = -2;
		}
		spaces1 = spaces1 + a;
		spaces2 = spaces2 + b;
		cout << endl;
		x = x + 1;
	}


}
