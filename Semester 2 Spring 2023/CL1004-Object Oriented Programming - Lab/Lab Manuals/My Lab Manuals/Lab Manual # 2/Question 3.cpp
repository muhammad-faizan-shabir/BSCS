#include <iostream>
using namespace std;
void input(int*&iarr, int &size, int num)
{
	*(iarr)=num;
	iarr++;
	size = size + 1;
}

void reverse(int *iarr, int size)
{
	int temp;
	iarr = iarr - (size);
	int first = 0;
	int last = size - 1;
	for (; last >= first; last--, first++)
	{
		temp = *(iarr + first);
		*(iarr + first) = *(iarr + last);
		*(iarr + last) = temp;
	}
}

void output(int *iarr, int size)
{
	cout << "The array in reverse: " << endl;
	int temp;
	iarr = iarr - (size);
	for (int i = 0; i < size; i++)
	{
		temp = *(iarr + i);
		cout << temp<< " ";
	}
}

int main()
{
	int n = 5;
	int*ptr = new int[n];
	int size = 0;
	int num;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter number: ";
		cin >> num;

		if (num == -1)
		{
			break;
		}
		else
		{
			input(ptr, size, num);
		}

		if (size >= n)
		{
			n = n * 2;
		}


	}

	reverse(ptr, size);
	output(ptr, size);


	system("pause");
}