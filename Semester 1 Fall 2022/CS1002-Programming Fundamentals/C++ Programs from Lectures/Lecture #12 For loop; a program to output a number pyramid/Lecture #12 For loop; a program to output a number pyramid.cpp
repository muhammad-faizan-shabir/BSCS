// a program to output a number pyramid
#include <iostream>
using namespace std;
int main()
{
	int i, j, k, rows, spc;
	i = 1;
	j = 1;

	cout << "Enter rows" << endl;
	cin >> rows;
	spc = rows - 1;
	for(i;i<=rows;i++)
	{
		for(k=spc;k>=1;k--)
		{
			cout << " ";
		}
		for(j=1;j<=i;j++)
		{
			cout << i << " ";
		}
		cout << endl;
		spc--;
	}
}