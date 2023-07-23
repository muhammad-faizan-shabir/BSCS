#include <iostream>
using namespace std;
int main()
{
	int sum = 0;
	int arr[3][4] =
	{
		{5,8,7,1},
		{7,3,1,9},
		{6,7,4,8}
	};
	int brr[4][3] =
	{
		{4,7,6},
		{9,3,2},
		{8,2,1},
		{9,4,6}
	};
	int crr[3][3] =
	{
		{0,0,0},
		{0,0,0},
		{0,0,0}
	};
	int l = 0;
	for(int i=0;i<=2;i++)
	{
		l = 0;
		for(int j=0;j<=2;j++)
		{
			for(int k=0;k<=3;k++)
			{
				sum = sum + ((arr[i][k]) * (brr[k][l]));
			}
			l++;
			crr[i][j] = sum;
			sum = 0;
		
		}
	}

	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{
			cout << crr[i][j] << " ";
		}
		cout << endl;
	}
}