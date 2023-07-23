#include <iostream>
using namespace std;

void sort(int a[], int size) // function to sort the array
{
	size = size - 2;
	int temp;

	bool nomoreswaps = false;

	while (nomoreswaps == false)
	{
		nomoreswaps = true;
		for (int i = 0; i <= size; i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				nomoreswaps = false;
			}
		}
		size = size - 1;
	}
}


int main()
{
	int arr[100]; // declaring an array

	int size;

	cout << "How many integers you want to enter: ";
	cin >> size; // inputting size of array

	cout << "Enter integers:" << endl;

	for (int i = 0; i < size; i++) // inputing numbers in array
	{
		cin >> arr[i];
	}

	cout << "Input array elements are: " << endl;

	for (int i = 0; i < size; i++) // outputing the numbers of the array
	{
		cout << arr[i] << endl;
	}

	sort(arr, size);  // sorting the array
	cout << "Sorted list is:" << endl; // outputing the sorted array

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}

	cout << "Enter the element to be inserted: ";
	cin >> arr[size]; // enetring a number in the array

	size = size + 1;

	sort(arr, size); // resorting the array

	cout << "Final list is: " << endl;

	for (int i = 0; i < size; i++) // outputing the sorted array
	{
		cout << arr[i] << endl;
	}




}