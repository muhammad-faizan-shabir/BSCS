#include<iostream>
#include<vector>
using namespace std;

void bubblesort(vector<int> &a1, int size)
{
	int n = size - 2; // initially we go till 2nd last index

	for (int i = 0; i < size - 2; i++) // loop runs n-1 times
	{
		for (int j = 0; j <= n; j++)
		{
			if (a1[j]>a1[j + 1]) // swap if first elemnt is greater than second
			{
				int temp = a1[j];
				a1[j] = a1[j + 1];
				a1[j + 1] = temp;
			}
		}
		n = n - 1; // since last element is sorted so decrease size of loop so that no extra comparisons are made
	}

}

int binarySearch(vector<int> &a1,int size,int itemtobesearched)
{
	int high = size-1; // intial high value
	int low = 0; // initial low value
	int mid; 
	int index=-1; // to store founf index position

	bool found = false; // flag that sets when item found
	bool failed = false; // flag that sets if item not found and array searc area  is finished

	while ((found == false) && (failed == false))
	{
		mid = (high + low) / 2; // caluculate mid

		if (a1[mid] == itemtobesearched) // check if item is at mid index
		{
			found = true;
			index = mid;
		}
		else
		{
			if (low == high) // check if search area finished
			{
				failed = true;
			}
			else if (a1[mid]>itemtobesearched) // check if next search are is on left side
			{
				high = mid - 1;
			}
			else // check if next search are is on right side
			{
				low = mid + 1;
			}
		}
	}
	return index;
}
int main()
{
	vector<int> a1 = { 64, 34, 25, 12, 22, 11, 90 }; // decalaring and initialising vector

	int num; // variable for user to enter number
	int index;

	bubblesort(a1, a1.size());// calling buublesort function
	
	cout << "Enter item to be searched: ";
	cin >> num; 

	index = binarySearch(a1, a1.size(), num); // calling binary search function
	if (index != -1)
	{
		cout << endl << "Found at index: " << index << endl;
	}
	else
	{
		cout <<endl<< "Not Found" << endl;
	}
	cout << endl;
	
	cout << "T(n) = log(n)" << endl;
	cout << "big o is O(log(n))" << endl;
	system("pause");
	return 0;
}