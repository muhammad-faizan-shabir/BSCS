#include <iostream>
using namespace std;
int main()
{
	double arr[3][5];
	float sum = 0;
	float leastfood;
	float greatestfood;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout << "Enter pounds of food for monkey " << (i+1) << " day " << (j+1) << " : ";
			cin >> arr[i][j];
			while(arr[i][j]<0)
			{
				cout << "Please enter a positive value: ";
				cin >> arr[i][j];
			}
			sum = sum + arr[i][j];
		}
	}
	
	leastfood = arr[0][0];
	greatestfood = arr[0][0];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(arr[i][j]<leastfood)
			{
				leastfood = arr[i][j];
			}
			if(arr[i][j]>greatestfood)
			{
				greatestfood = arr[i][j];
			}
		}
	}
	cout << endl;
	cout << "Average amount of food eaten per day by the whole family of monkeys is: " << sum / 5.0;
	cout << endl << endl;
	cout << "The least amount of food eaten during the week by any one monkey is: " << leastfood;
	cout << endl << endl;
	cout << "The greatest amount of food eaten during the week by any one monkey is: " << greatestfood;
	cout << endl << endl;
}