#include <iostream>
using namespace std;
int main()
{
	int num; // number entered by user
	int totalRows; // total number of rows
	char symbol; // symbol that will be used to print the pattern
	int sideSymbols=0; // number of symbols to be printed on the sides
	int middleSymbols; // number of symbols to be printed in the middle
	int ss=1;// variable to control the number of side symbols
	int ms=-2;// variable to control the number of middle symbols

	cout << "Enter Number: ";
	cin >> num;

	cout << "Enter character to print with: ";
	cin >> symbol;

	if((num%2)==0) // if number entered is even
	{
		totalRows = num + 1;
		middleSymbols = totalRows - 2;
	}
	else // if number entered is odd
	{
		totalRows = num+2;
		middleSymbols = totalRows - 2;
	}
	

	for(int i =1;i<=totalRows;i++) // loop will run for the total number of rows
	{
		for(int j =1;j<=sideSymbols;j++) // loop prints symbols on the left side
		{
			cout << symbol;
		}
		
		cout << " ";

		for(int j=1; j<=middleSymbols;j++) // loop prints symbols in the middle
		{
			cout << symbol;
		}

		cout << " ";

		for(int j=1;j<=sideSymbols;j++) // loop prints symbols on the right side
		{
			cout << symbol;
		}

		if(i==(totalRows/2)) // if mid of the shape s reached
		{
			i = i + 2; // skipping two iterartions
			cout << endl; // movving on the next line
			
			for(int j=1;j<=(sideSymbols+1);j++) // printing symbols in the middle row
			{
				cout << symbol;
			}
			
			cout << " ";

			for (int j = 1; j <= (sideSymbols + 1); j++) // printing symbols in the middle row
			{
				cout << symbol;
			}
			
			cout << endl; // moving on the next line

			for (int j = 1; j <= sideSymbols; j++) // printing left side symbols in the row below the middle row
			{
				cout << symbol;
			}

			cout << " ";

			for (int j = 1; j <= middleSymbols; j++) // printing middle symbols in the row below the middle row
			{
				cout << symbol;
			}

			cout << " ";

			for (int j = 1; j <= sideSymbols; j++)// printing right side symbols in the row below the middle row
			{
				cout << symbol;
			}
			
			ss = -1; // changing value of the variable that controls the number of side symbols
			ms = +2; // changing value of the variable that controls the number of middle symbols
		}
		
		sideSymbols = sideSymbols + ss; // updating the number of side symbols
		middleSymbols = middleSymbols + ms; // updating the number of middle symbols
		cout << endl;
	}
}