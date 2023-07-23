#include <iostream>
using namespace std;
int main()
{
	int spc = -1;
	int  N;

	cout << "Enter value of N: ";
	cin >> N;

	for (int i = 1; i <=N; i++)
	{
		cout << "*";

		for (int j = 1; j <= spc; j++)
		{
			if (i == N)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}

		if (i != 1)
		{
			cout << "*";
		}

		cout << endl;

		spc = spc + 1;
	}

	
}