#include <iostream>
using namespace std;
int balance(int arr[5][5],int array[])
{
	int index = 0;
	int countleft = 0;
	int countright = 0;
	int countup = 0;
	int countdown = 0;
	int counter = 0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<=j-1;k++)
			{
				countleft = countleft + (arr[i][k]);
			}

			for(int k=j+1;k<5;k++)
			{
				countright = countright + (arr[i][k]);
			}

			for(int k=0;k<=i-1;k++)
			{
				countup = countup + (arr[k][j]);
			}

			for(int k=i+1;k<5;k++)
			{
				countdown = countdown + (arr[k][j]);
			}
			
			if((countleft==countright)&&(countup==countdown))
			{
				counter++;
				array[index] = i;
				++index;
				array[index] = j;
				++index;
			}

			countleft = 0;
			countright = 0;
			countup = 0;
			countdown = 0;

		}
	}
	array[index] = -1;
	return counter;
}

int main()
{
	int result;
	int array[50];
	int arr[5][5] =
	{
		{0,2,3,4,5},
		{6,7,8,-9,0},
		{1,2,3,4,5},
		{6,7,8,9,0},
		{1,2,3,-4,5}
	};

	result = balance(arr, array);
	
	if(result>0)
	{
		cout << "There are " << result << " balance points" << endl;
		for(int i=0;array[i]!=-1;i++)
		{
			cout << "(" << array[i] << ", ";
			i = i + 1;
			cout<< array[i] << ")" << endl;
		}
	}
	else
	{
		cout << "The array has no balance points" << endl << endl;
	}
}
