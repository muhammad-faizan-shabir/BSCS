#include <iostream>
using namespace std;

void copyArray(int *arr,int *&arr1,int size)
{
	for(int i=0;i<size;i++)
	{
		arr1[i] = *(arr);
		arr = arr + 1;
	}
}

void reduceArray(int* arr, int*& arr1, int size)
{
	copyArray(arr,arr1,size);
}

int main()
{
	int size;
	cout << "Please enter size: ";
	cin >> size;

	int* arr = new int[size];

	cout << "Please enter elements: " << endl;
	
	for(int i=0;i<size;i++)
	{
		cin >> *(arr+i);
	}

	int temp;
	cout << endl << "Please enter the reduced size of array: ";
	cin >> temp;

	int* arr1 = new int[temp];

	reduceArray(arr+(size-temp), arr1, temp);

	cout <<endl<< "Array after reduction is: " << endl;

	for (int i = 0; i < temp; i++)
	{
		cout << *(arr1 + i) << endl;
	}
	
	delete[] arr;
	arr = 0;

	delete[] arr1;
	arr1 = 0;
}