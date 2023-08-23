#include <iostream>
using namespace std;
int main()
{
	int rows;
	int stars = 1;

	cout << "Enter number of rows of hollow right angled triangle" << endl;
	cin >> rows;

	for(int i =1;i<=rows;i++)
	{
		for(int j =1;j<=stars;j++)
		{
			if(i==1||j==1||j==stars||i==rows)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
			
		}
		cout << endl;
		stars++;
	}
}