#include <iostream>
using namespace std;

int main()
{
	int arr[100]; // declaring an array
	int size; // size of array
	int del; // index of item to be deleted

	cout << "Enter the size of the array: ";
	cin >> size; // inputting size of array

	cout << "Enter the integers of the array: " << endl;

	for (int i = 0; i < size; i++) // inputting numbers in the array
	{
		cin >> arr[i];
	}

	cout << "Enter the index of the element to be deleted: ";
	cin >> del; // inputing index of the number to be deleted

	if ((del < 0) || (del >= size)) // making sure that the index to be deleted is valid
	{
		cout << "Deletion is not possible in the array" << endl;
	}
	else
	{
		cout << "The array after deleting the element is: " << endl;
		for (int i = 0; i < size; i++) // outputing array after deletion
		{
			if (i != del)
			{
				cout << arr[i] << " ";
			}
		}
	}
}