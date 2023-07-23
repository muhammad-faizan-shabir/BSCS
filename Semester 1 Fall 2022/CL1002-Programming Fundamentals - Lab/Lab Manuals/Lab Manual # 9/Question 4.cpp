#include <iostream>
using namespace std;

int search(int num,int l[])
{
	int high = 9;
	int low = 0;
	int mid;
	int index;

	bool found = false;
	bool failed = false;

	while ((found == false) && (failed == false))
	{
		mid = (high + low) / 2;

		if (l[mid] == num)
		{
			found = true;
			index = mid;
		}
		else
		{
			if (low >= high)
			{
				failed = true;
			}
			else if (l[mid] > num)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}
	
	if (found == true)
	{
		return index;

	}
	else
	{
		return -1;
	}


}

int main()
{
	int num;
	int temp;
	int arr[] = { 10,20,30,40,50,60,70,80,90,100 };

	cout << "The current situation of arary is:" << endl;

	for(int i =0;i<10;i++)
	{
		cout << arr[i] << " ";
	}

	cout <<endl<< "Enter the number you want to find: ";
	cin >> num;
	temp = search(num, arr);
	cout << "The Number is found at index : " << temp << endl;
}