// hollow rectangle using for loop
#include <iostream>
using namespace std;
int main()
{
	int rows;
	int columns;
	cout << "Enter rows of hollow rectangle" << endl;
	cin >> rows;
	cout << "Enter columns of hollow rectangle" << endl;
	cin >> columns;

	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= columns; j++)
		{
			if ((i == 1) || i == rows)
			{
				cout << "* ";
			}
			else if (j == 1 || j == columns)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}