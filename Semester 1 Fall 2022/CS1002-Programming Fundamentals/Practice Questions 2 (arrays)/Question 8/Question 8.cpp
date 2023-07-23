#include <iostream>
using namespace std;

void sort(int arr[], int size) // function to sort the array
{
	bool nomoreswaps = false;
	int temp;
	int n = size - 2;
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
	int arr[100]; // declaring array
	int size; // variable to hold the size of array
	bool flag = false;
	cout << "Enter size of array: ";
	cin >> size; // inputing size of array

	cout << "Enter " << size << " integers: " << endl;

	for (int i = 0; i < size; i++) // inputing integers into array
	{
		cout << "enter a[" << i << "] element into the array: ";
		cin >> arr[i];
	}


	sort(arr, size); // calling function to sort the array



	for (int i = 0; i < size - 1; i++)
	{
		if ((arr[i] + 1) != (arr[i + 1])) // checking for the missing number
		{
			flag = true;
			cout<<endl << "Missing number is: " << arr[i] + 1 << endl;
		}
	}


	if (flag == false) // checking if there was no missing number
	{
		cout<<endl << "No missing elements" << endl;
	}
}

