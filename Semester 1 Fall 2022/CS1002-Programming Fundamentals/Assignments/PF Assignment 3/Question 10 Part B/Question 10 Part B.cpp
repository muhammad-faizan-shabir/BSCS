#include <iostream>
using namespace std;
int main()
{
	int rows; // rows entered by the user
	int totalRows; // total number of rows
	int stars=1; // initial number of stars
	int spaces;// number of spaces
	int st = 1; // variable to control number of stars
	int spc = -2; // variable to control number of spaces

	cout << "Please enter number of rows: ";
	cin >> rows;

	totalRows = 2 * rows; // calculating total number of rows

	spaces = totalRows - 2; // calculating initial number of spaces

	for(int i =1;i<=totalRows;i++) // loop will run for total number of rows
	{
		for(int j=1;j<=stars;j++) // loop will print stars in a row
		{
			cout << "*";
		}

		for(int j =1;j<=spaces;j++) // loop will print spaces in a row
		{
			cout << " ";
		}

		for (int j = 1; j <= stars; j++) // loop will print stars in a row
		{
			cout << "*";
		}

		if(i==(rows-1)) // if mid of loop/shape reached
		{
			i = i + 3; // skipping 3 iterations
			cout << endl; // moving to next line

			for(int j=1;j<=totalRows;j++) // printing row with all stars
			{
				cout << "*";
			}
			cout << endl;

			for (int j = 1; j <= totalRows; j++) // printing row with all stars
			{
				cout << "*";
			}
			cout << endl;

			for (int j = 1; j <= stars; j++) // printing rows just after row with all stars
			{
				cout << "*";
			}

			for (int j = 1; j <= spaces; j++) // printing rows just after row with all stars
			{
				cout << " ";
			}

			for (int j = 1; j <= stars; j++) // printing rows just after row with all stars
			{
				cout << "*";
			}
			
			st = -1; // changing value of variable that controls number of stars
			spc = 2; // changing value of variable that controls number of spaces
		}
		
		stars = stars + st; // updating number of stars
		spaces = spaces + spc; // updating number of spaces
		cout << endl;
	}
}