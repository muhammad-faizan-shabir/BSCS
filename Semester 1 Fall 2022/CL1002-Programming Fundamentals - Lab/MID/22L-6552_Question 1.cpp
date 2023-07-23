//Question 1
#include <iostream>
using namespace std;
int main()
{	
	int spc;
	int stars=1;

	int rows;

	cout << "Enter the number of rows: ";
	cin >> rows;

	

	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= stars; j++)
		{
			cout << "*";
		}
		stars = stars + 1;
		cout << endl;
	}
	
	cout << endl << endl;

	stars = rows;

	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= stars; j++)
		{
			cout << "*";
		}
		stars = stars - 1;
		cout << endl;
	}
	
	cout << endl << endl;

	spc = 0;
	stars = rows;

	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= spc; j++)
		{
			cout << " ";
		}
		
		for (int j = 1; j <= stars;j++)
		{
			cout << "*";
		}

		cout << endl;
		stars = stars - 1;
		spc = spc + 1;

	}

	cout << endl << endl;

	spc = rows - 1;
	stars = 1;
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= spc; j++)
		{
			cout << " ";
		}

		for (int j = 1; j <= stars; j++)
		{
			cout << "*";
		}
		cout << endl;

		spc = spc - 1;
		stars = stars + 1;
	}
	
}