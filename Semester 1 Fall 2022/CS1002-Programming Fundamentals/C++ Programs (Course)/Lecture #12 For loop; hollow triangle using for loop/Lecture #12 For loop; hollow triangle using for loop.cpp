// hollow triangle using for loop
#include <iostream>
using namespace std;
int main()
{
	int rows;
	int i;
	int j;
	int k;
	int spc1;
	int spc2=-1;
	

	cout << "Enter no of rows of hollow triangle" << endl;
	cin >> rows;

	spc1 = rows - 1;

	for(i=1;i<=rows;i++)
	{
		for(j=1;j<=spc1;j++)
		{
			cout << " ";
		}
		cout << "*";
		for(k=1;k<=spc2;k++)
		{
			if(i==rows)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		if(i!=1)
		{
			cout << "* ";
		}
		spc1--;
		spc2 = spc2 + 2;
		cout << endl;
	}

}