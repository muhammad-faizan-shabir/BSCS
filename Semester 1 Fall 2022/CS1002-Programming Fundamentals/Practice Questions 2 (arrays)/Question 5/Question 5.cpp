#include <iostream>
using namespace std;

void shiftLeft(int arr[],int size) // function to cyclically permute elements of array
{
	int temp = arr[0];

	for(int i =0;i<=size-2;i++) // shifting elemets to previous indexes
	{
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = temp;
	

}

int main()
{
	int a[100]; // declaring array
	int size; // variable to hold size of array

	cout << "Enter size of array:";
	cin >> size; // inputing size of array

	cout << "Enter the numbers" << endl;

	for(int i=0;i<size;i++) // inputting elements of array
	{
		cin >> a[i];
	}
	
	shiftLeft(a, size); // calling the function to cyclically permute the array
	 
	

	cout << "Cyclically permuted numbers are given below: " << endl;

	for (int i = 0; i < size; i++) // outputing the cyclically permuted array 
	{
		cout << a[i] << endl;
	}
	
}