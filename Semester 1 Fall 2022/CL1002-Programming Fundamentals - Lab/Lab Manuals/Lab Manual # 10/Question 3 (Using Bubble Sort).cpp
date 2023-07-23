#include <iostream>
using namespace std;
void BubbleSortForOdd(int arr[],int size)
{
	int temp;
	bool nomoreswaps = false;

	while(nomoreswaps==false)
	{
		nomoreswaps = true;
		for(int i =1;i<=size;i=i+2)
		{
			if(arr[i-1]<arr[i+2-1])
			{
				nomoreswaps = false;
				temp = arr[i - 1];
				arr[i - 1] = arr[i + 2 - 1];
				arr[i + 2 - 1] = temp;
			}
		}
		size = size - 2;
	}
}

void BubbleSortForEven(int arr[], int size)
{
	int temp;
	bool nomoreswaps = false;

	while (nomoreswaps == false)
	{
		nomoreswaps = true;
		for (int i = 2; i <= size; i = i + 2)
		{
			if (arr[i - 1] > arr[i + 2 - 1])
			{
				nomoreswaps = false;
				temp = arr[i - 1];
				arr[i - 1] = arr[i + 2 - 1];
				arr[i + 2 - 1] = temp;
			}
		}
		size = size - 2;
	}
}



int main()
{
	int a[] = { 7,10,11,3,6,9,2,13,0 };
	BubbleSortForEven(a,6);
	BubbleSortForOdd(a, 7);

	for(int i=0;i<9;i++)
	{
		cout << a[i] << " ";
	}
}