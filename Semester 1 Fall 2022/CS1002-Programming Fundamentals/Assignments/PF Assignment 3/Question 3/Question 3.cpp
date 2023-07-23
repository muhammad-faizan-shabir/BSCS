#include <iostream>
using namespace std;
int main()
{
	int totalRows; // total number of rows in kite
	int upperRows; // number of rows in upper portion of kite 
	int spc1; // spaces before the boundary of kite
	int spc2 = -1; // spaces between the boundaries of kite
	int s1 = -2; // variable to control spc1
	int s2 = 4; // variable to control spc2

	cout << "Enter height of the upper portion of the kite: "; 
	cin >> upperRows;

	totalRows = upperRows + upperRows + (upperRows - 2); // calculating total number of rows in kite
	
	spc1= upperRows + (upperRows - 2); // calculating spaces before the boundary of kite


	for(int i=1;i<=totalRows;i++) // loop will run for total number of rows
	{
		for(int j=1;j<=spc1;j++) // loop for spaces before the boundary of kite
		{
			cout << " ";
		}
		
		cout << "*"; // printing boundary star
		
		for(int k=1;k<=spc2;k++) // loop for spaces between the boundaries of kite
		{
			if(k==((spc2+1)/2))
			{
				cout << "|";
			}
			else if (i == upperRows)
			{
				if (k == ((spc2 + 1) / 2))
				{
					cout<<"|";
				}
				else
				{
					cout<<"-";
				}
			}
			else
			{
				cout << " ";
			}
			
		}
		
		if((i!=1)&&(i!=totalRows)) // printing boundary star
		{
			cout << "*";
		}

		if(i==upperRows) // When mid of kite is reached there is changing in the spaces
		{
			s1 = 1;
			s2 = -2;
		}

		spc1 = spc1 + s1; // updating spaces before the boundary of kite
		spc2 = spc2 + s2; // updating spaces between the boundaries of kite

		cout << endl; // moving to the next line
	}

}