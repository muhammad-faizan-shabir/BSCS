#include <iostream>
using namespace std;
int main()
{
	int arr1[100]; // first array
	int arr2[100]; // second array
	int sortedArr[100];// merged array
	int size1; // size of first array
	int size2; // size of second array
	int size3; // size of merged array
	int temp; 
	bool nomoreswaps = false;
	int n;

	cout << "Enter the size of the first array: ";
	cin >> size1; // inputing size of first array

	cout << "Enter the elements of the first array: " << endl;

	for(int i = 0;i<size1;i++) // inputing elements of first array
	{
		cin >> arr1[i];
	}

	cout << "Enter the size of the second array: ";
	cin >> size2; // inputting size of second array

	cout << "Enter the elements of the second array: " << endl;

	for (int i = 0; i < size1; i++) // inputting elements of second array
	{
		cin >> arr2[i];
	}

	for(int i =0;i<size1;i++) // inputing elements of first array in the merged array
	{
		sortedArr[i] = arr1[i]; 
		temp = i;
	}


	for(int i =0;i<size2;i++) // inputting elements of second array in the merged array
	{
		temp = temp + 1;
		sortedArr[temp] = arr2[i];
	}
	size3 = temp + 1; // updating size of merged array
	n = temp - 1;
	while (nomoreswaps == false) // sorting the merged array
	{
		nomoreswaps = true;
		for (int i = 0; i <= n; i++)
		{
			if (sortedArr[i] > sortedArr[i + 1])
			{
				temp = sortedArr[i];
				sortedArr[i] = sortedArr[i + 1];
				sortedArr[i + 1] = temp;
				nomoreswaps = false;
			}
		}
		n = n - 1;
	}

	cout << "The merged array is: " << endl;

	for(int i=0;i<size3;i++) // outputting the merged array
	{
		cout << sortedArr[i] << " ";
	}

}