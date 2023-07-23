#include <iostream>
using namespace std;

double findMedianSortedArrays(int nums1[], int nums2[])
{
	int medianIndex;
	double median;
	int arr[8];
	bool flag = false;

	for(int i = 0; i < 4; i++)
	{
		arr[i] = nums1[i];
	}
	
	int x = 0;
	for (int i = 4; i < 8; i++)
	{

		arr[i] = nums2[x];
		x = x + 1;
	}

	cout << "Merged array is: " << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	while (flag == false)
	{
		int temp;
		flag = true;
		int index = 6;
		for (int i = 0; i <= index; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = false;
			}
		}
		index--;
	}

	cout << "The sorted array is: " << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	
	medianIndex = ((8 + 1) / 2)-1;

	median = (arr[medianIndex] + arr[medianIndex + 1]) / 2.0;

	return median;





}

int main()
{
	int nums1[] = {5,6,2,3};
	int nums2[] = {7,9,8,1};


	cout << "Array 1 is: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << nums1[i] << " ";
	}

	cout << endl;
	cout << "Array 2 is: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << nums2[i] << " ";
	}
	cout << endl;
	

	cout << "Median is: " << findMedianSortedArrays(nums1, nums2);
	int x;
	cin >> x;



}