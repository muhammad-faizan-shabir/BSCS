#include <iostream>
using namespace std;

void InsertionSort(int arr[], int size)
{
	int ItemToBeInserted;
	int CurrentItemIdx;

	for (int i = 1; i < size; i++)
	{
		ItemToBeInserted = arr[i];
		CurrentItemIdx = i - 1;
		while ((arr[CurrentItemIdx] > ItemToBeInserted) && (CurrentItemIdx > -1))
		{
			arr[CurrentItemIdx + 1] = arr[CurrentItemIdx];
			CurrentItemIdx = CurrentItemIdx - 1;
		}

		arr[CurrentItemIdx + 1] = ItemToBeInserted;
	}
}

int main()
{
	int arr[] = { 53,21,60,18,42,19 };

	InsertionSort(arr, 6);

	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}

}