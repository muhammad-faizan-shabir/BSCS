#include <iostream>
using namespace std;

void InsertionSortForEven(int arr[], int size)
{
	int ItemToBeInserted;
	int CurrentItemIdx;

	for (int i = 4; i <= size; i = i + 2)
	{
		ItemToBeInserted = arr[i-1];
		CurrentItemIdx = i - 2;
		while ((arr[CurrentItemIdx - 1] > ItemToBeInserted) && (CurrentItemIdx >1))
		{
			arr[CurrentItemIdx + 2 - 1] = arr[CurrentItemIdx - 1];
			CurrentItemIdx = CurrentItemIdx - 2;
		}

		arr[CurrentItemIdx + 2 - 1] = ItemToBeInserted;
	}
}

void InsertionSortForOdd(int arr[], int size)
{
	int ItemToBeInserted;
	int CurrentItemIdx;

	for (int i = 3; i <= size; i = i + 2)
	{
		ItemToBeInserted = arr[i - 1];
		CurrentItemIdx = i - 2;
		while ((arr[CurrentItemIdx - 1] < ItemToBeInserted) && (CurrentItemIdx > 0))
		{
			arr[CurrentItemIdx + 2 - 1] = arr[CurrentItemIdx - 1];
			CurrentItemIdx = CurrentItemIdx - 2;
		}

		arr[CurrentItemIdx + 2 - 1] = ItemToBeInserted;
	}
}

int main()
{
	int a[] = { 7,10,11,3,6,9,2,13,0 };
	
	InsertionSortForEven(a, 8);
	
	InsertionSortForOdd(a, 9);

	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << " ";
	}
}