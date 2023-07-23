#include <iostream>
using namespace std;
int main()
{
	int i;
	int arr[10] = {};
	int num;
	cout << "Enter 10 elements in ascending order" << endl;
	for (i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	cout << "\nEnter Element to be serached: ";
	cin >> num;

	int high = 9;
	int low = 0;
	int mid;
	int index;
	
	bool found = false;
	bool failed = false;

	while ((found == false) && (failed == false))
	{
		mid = (high + low) / 2;

		if(arr[mid]== num)
		{
			found = true;
			index = mid;
		}
		else 
		{
			if (low == high)
			{
				failed = true;
			}
			else if(arr[mid]>num)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}


	
		
	

	if(found == true)
	{
		cout << "Element is found at index " << index << endl;

	}
	else
	{
		cout << "Number not found" << endl;
	}
}