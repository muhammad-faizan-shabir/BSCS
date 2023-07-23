#include <iostream>
using namespace std;
int main()
{
	// shallow copy
	int* arr1 = new int[5];
	int* arr2 = arr1; // shallow copy
	//for loop to print contents
	//of arr1 and arr2

	// deep copy
	int* arr3 = new int[5];
	for (int i = 0; i < 5; i++)
	{
		arr3[i] = arr1[i];
	}
}