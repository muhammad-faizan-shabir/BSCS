#include <iostream>
using namespace std;
int main()
{
	int rows;
	int i;
	int j;
	int k;
	int spc1= 0;
	int spc2;

	cout << "Enter no of rows for hollow inverted triangle" << endl;
	cin >> rows;

	spc2 = rows + (rows-3);

	for(i=1;i<=rows;i++)
	{
		for(j=1;j<=spc1;j++)
		{
			cout << " ";
		}
		cout << "*";
		for(k=1;k<=spc2;k++)
		{
			if(i==1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}

		}
		if(i!=rows)
		{
			cout << "*";
		}
		spc1++;
		spc2 = spc2 - 2;
		cout << endl;
	}

}