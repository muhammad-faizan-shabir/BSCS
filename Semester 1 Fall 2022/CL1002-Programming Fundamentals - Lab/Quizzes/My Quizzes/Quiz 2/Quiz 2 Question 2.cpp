#include <iostream>
using namespace std;

void twoSum(int nums[], int target, int size)
{
	int ptr;
	int temp1 = size - 2;

	int temp2 = size - 1;
	int temppointer;
	int flag = false;

	for (ptr = 0; ptr <= temp1; ptr = ptr + 1)
	{
		temppointer = ptr;
		
		for (int i = 1; i <= temp2; i++)
		{
			temppointer = temppointer + 1;
			
			if ((nums[ptr]) + (nums[temppointer]) == target)
			{
				cout << ptr << " " << temppointer;
				flag = true;
				break;
			}
			
		}
		temp2--;
		if (flag == true)
		{
			break;
		}
	}

}

int main()
{
	int size;
	int arr[100];
	int target;

	cout << "Enter size of array: ";
	cin >> size;

	cout << "Enter " << size << " elements: " << endl;


	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	cout << "Enter target: ";
	cin >> target;


	twoSum(arr, target, size);

	cin >> size;
}