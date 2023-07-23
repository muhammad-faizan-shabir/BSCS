#include <iostream>
using namespace std;
void BubbleSort(int arr[],int size)
{
	int n = size - 2;
	int temp;

	bool nomoreswaps = false;

	while (nomoreswaps == false)
	{
		nomoreswaps = true;
		for (int i = 0; i <= n; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				nomoreswaps = false;
			}
		}
		n = n - 1;
	}
}

int main()
{
	int arr[] = {10,15,3,0,9};

	BubbleSort(arr, 5);

	for(int i=0;i<5;i++)
	{
		cout << arr[i] << endl;
	}
}