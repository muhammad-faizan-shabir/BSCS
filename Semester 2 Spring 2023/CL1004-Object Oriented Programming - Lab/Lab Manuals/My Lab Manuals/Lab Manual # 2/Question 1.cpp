#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter the value of n for Fibonacci sequence: ";
	cin >> n;
	int *ptr = new int[n];
	int temp1 = 1;
	int temp2 = 1;
	int sum = 0;

	if (n == 1)
	{
		*(ptr) = 1;
	}
	else if (n == 2)
	{
		*(ptr) = 1;
		*(ptr + 1) = 1;
	}
	else
	{
		*(ptr) = 1;
		*(ptr + 1) = 1;
		for (int i = 2; i < n; i++)
		{
			sum = temp1 + temp2;
			*(ptr + i) = sum;
			temp1 = temp2;
			temp2 = sum;
		}
	}
	
	cout << endl << "The dynamic array after bieng populated by first n Fibonacci numbers: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(ptr + i) << " ";
	}

	delete[] ptr;

	cout << endl << endl;
	system("pause");

}