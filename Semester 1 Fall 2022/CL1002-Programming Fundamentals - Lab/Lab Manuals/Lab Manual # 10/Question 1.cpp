#include <iostream>
using namespace std;
void SelectionSort(int arr[], int size)
{
	int i, j, min_idx, temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}

	}
}

int main()
{
	int arr[] = { 10,9,1,2,0 };

	SelectionSort(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Number of passes required to sort the array: " << (sizeof(arr) / sizeof(arr[0]) - 1);

}
