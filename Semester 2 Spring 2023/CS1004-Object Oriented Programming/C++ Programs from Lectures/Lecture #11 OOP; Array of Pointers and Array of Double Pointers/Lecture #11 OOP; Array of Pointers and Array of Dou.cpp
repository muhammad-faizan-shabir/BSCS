#include <iostream>
using namespace std;
int main()
{
	int x = 8;
	int* ptr = &x;

	int** arr[5]; // array of double integer pointers
	int* arr1[5]; // array of integer pointers

	arr[0] = &ptr;
	arr1[0] = &x;
}