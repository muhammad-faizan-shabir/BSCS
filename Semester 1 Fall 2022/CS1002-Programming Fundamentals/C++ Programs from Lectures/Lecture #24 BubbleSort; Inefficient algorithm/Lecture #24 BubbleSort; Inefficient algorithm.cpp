#include <iostream>
using namespace std;

void BubbleSort(int a[],int size)
{
	int n = size - 2;
	int temp;

	for (int i=0;i<=size-2;i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		n--;
	}
}

int main()
{
	int a[] = { 5,4,3,2,1 };

	BubbleSort(a, 5);

	for(int i=0;i<5;i++)
	{
		cout << a[i] << " ";
	}
}