#include <iostream>
using namespace std;
int main()
{
	int rows; // rows entered by user
	int totalRows; // total rows
	int spaces = 2; // number of spaces
	int stars; // number of stars
	int st = -1; // variable to control number of stars
	int spc = 2; // variable to control number of spaces

	cout << "Please enter the number of rows: ";
	cin >> rows;

	totalRows = 2 * rows; // calculating total rows
	
	stars = rows - 1; // calculating initial number of stars 

	for(int i =1;i<=totalRows;i++) // loop will print first row
	{
		cout << "*";
	}
	cout << endl;

	for(int i =1;i<=(totalRows-2);i++) // loop will print rows from second row till second last row
	{
		for(int j =1;j<=stars;j++) // loop will print stars in a row
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

		if(i==rows-1) // if iterations reach mid of loop/shape
		{
			i++; // skipping one iteration
			cout << endl;
			for (int j = 1; j <= (stars + stars + spaces);j++) // printing one of the two rows in the middle   
			{
				if((j==1)||(j== (stars + stars + spaces)))
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}

			}
			st = 1; // changing value of variable that controls number of stars
			spc = -2; // changing value of variable that controls number of spaces
		}

		stars = stars + st; //updating number of stars
		spaces = spaces + spc; // updating number of stars
		cout << endl;
	}

	for (int i = 1; i <= totalRows; i++) // loop will print last row
	{
		cout << "*";
	}

}