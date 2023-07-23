#include <iostream>
using namespace std;
void BubbleSort(int arr[], int size)
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

void search(int arr[],int size)
{
	int num;
	cout << "Enter number to be searched: ";
	cin >> num;
	int index;
	bool found = false;

	for(int i =0;i<size;i++)
	{
		if(arr[i]==num)
		{
			found = true;
			index = i;
			break;
		}
	}

	if (found == true)
	{
		cout << "Number found at index: " << index;
	}
	else
	{
		cout << "Number not found";
	}
}

void insert(int arr[],int size)
{
	int num;
	cout << "Enter number to insert in array: ";
	cin >> num;

	arr[size] = num;

	BubbleSort(arr, size + 1);
}

void Delete(int arr[],int size)
{
	int num;
	cout << "Enter number to be deleted: ";
	cin >> num;
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==num)
		{
			break;
		}
	}

	for(int j=i;j<size-1;j++)
	{
		arr[j] = arr[j + 1];
	}
}

int main()
{
	int choice;
	int arr[100] = {1,2,3,4,5,6};
	cout << "Current condition of array: " << endl;
	for(int i=0;i<6;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Press 1 to search array" << endl;
	cout << "Press 2 to insert data in array" << endl;
	cout << "Press 3 to delete data from array" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		search(arr,6);
		break;
	case 2:
		insert(arr,6);
		cout << endl;
		cout << "Updated condition of array: " << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << arr[i] << " ";
		}
		break;
	case 3:
		Delete(arr, 6);
		cout << endl;
		cout << "Updated condition of array: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << arr[i] << " ";
		}
		break;
	}
	
	
}