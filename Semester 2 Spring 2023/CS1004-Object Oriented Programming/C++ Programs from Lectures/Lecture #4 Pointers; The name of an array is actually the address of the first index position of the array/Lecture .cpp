#include <iostream>
using namespace std;
// func1, func2, func3 and func4 are all same/equivalent
// The name of an array is actually the address of the first index position of the array
void func1(int arr[], int s)
{
	cout << arr[2];
}

void func2(int arr[], int s)
{
	cout << *(arr+2);
}

void func3(int *arr, int s)
{
	cout << arr[2];
}

void func4(int *arr, int s)
{
	cout <<*(arr+2);
}

void main()
{
	int arr[5] = { 3,4,99,6,7 };
	
	func1(arr, 5);
	cout << endl;
	
	func2(arr, 5);
	cout << endl;
	
	func3(arr, 5);
	cout << endl;
	
	func4(arr, 5);
	cout << endl;
}