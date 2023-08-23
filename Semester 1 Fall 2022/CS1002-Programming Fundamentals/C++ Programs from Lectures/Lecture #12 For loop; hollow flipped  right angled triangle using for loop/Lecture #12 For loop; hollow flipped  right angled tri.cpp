#include <iostream>
using namespace std;
int main()
{
	int rows;
	int stars=1;
	int spaces;

	cout << "Enter no of rows for flipped hollow right angled triangle" << endl;
	cin >> rows;

	spaces = rows - 1;

	for(int i=1;i<=rows;i++)
	{
		for(int j=1;j<=spaces;j++)
		{
			cout << " ";
		}

		for(int k =1; k<=stars;k++)
		{
			if (i == 1 || k == 1 || k == stars || i == rows)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		stars++;
		spaces--;
		cout << endl;
	}

}