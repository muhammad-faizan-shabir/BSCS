#include <iostream>
using namespace std;

int min(int a[],int s,int e)
{
	int smallestIndex = s;
	int smallest = a[s];

	for (int i = s; i <= e; i++)
	{
		if (a[i] < smallest)
		{
			smallest = a[i];
			smallestIndex = i;
		}
	}

	return smallestIndex;
}

void swap(int &x,int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void Sort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		int m = min(a, i, n - 1);
		swap(a[i], a[m]);
	}
}

int main()
{
	int a[] = {21,54,12,87,23,44,56,36,37,39};
	int size = 10;

	cout << "Original array: " << endl;
	for(int i=0;i<size;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;

	Sort(a, size);

	cout << "Array after bieng sorted:" << endl;
	for(int i =0;i<size;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;

	return 0;
}