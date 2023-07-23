#include <iostream>
using namespace std;
int main()
{
	int n;
	float largest;
	float SecondLargest;
	int SecondLargestIndex;
	cout << "Please enter size: ";
	cin >> n;
	float *ptr = new float[n];
	cout << "Please enter elements: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> *(ptr + i);
	}

	largest = *(ptr);
	for (int i = 1; i < n; i++)
	{
		if (*(ptr + i)>largest)
		{
			largest = *(ptr + i);
		}
	}

	SecondLargest = *(ptr);
	SecondLargestIndex = 0;
	for (int i = 1; i < n; i++)
	{
		if ((*(ptr + i)<largest) && (*(ptr + i)>SecondLargest))
		{
			SecondLargest = *(ptr + i);
			SecondLargestIndex = i;
		}
	}

	cout << "Second Largest element is: " << SecondLargest << endl;
	cout << "Index of second largest element is: " << SecondLargestIndex << endl << endl;

	delete[] ptr;

	system("pause");


}