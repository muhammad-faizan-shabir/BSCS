#include <iostream>
using namespace std;
void main()
{
	int num = 10;
	int* ptr1 = &num;
	cout << num << endl;
	
	*ptr1 = 20;
	cout << num << endl;

	int** ptr2 = &ptr1;
	cout << *ptr2<< endl;
	cout << **ptr2 << endl;

	int arr[5] = { 7,5,4,9,8 };
	cout << arr << endl;
	cout << arr[2] << endl;
	cout << *(arr + 2) << endl;
}