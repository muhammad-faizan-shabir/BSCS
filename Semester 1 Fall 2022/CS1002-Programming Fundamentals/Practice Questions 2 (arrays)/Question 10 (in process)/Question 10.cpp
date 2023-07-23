#include <iostream>
using namespace std;
int main()
{
	int arr[100];
	int num[100];
	int freq[100];
	bool flag = false;
	int size=0;
	int maxindex = size - 1;
	int index1_2=-1;
	int temp;
	int prev = -1;
	
	int loop;
	int count;
	int largest = -99999999;


	cout << "Enter size of array: ";
	cin >> size;

	cout << "Enter set of " << size << " numbers: " << endl;

	for(int i =0;i<size;i++)
	{
		cin >> arr[i];
	}
	cout << endl;
	for(int i=0;i<size-1;i++)
	{
		flag = false;
		temp = arr[i];
		for(int j=0;j<=prev;j++)
		{
			if(temp == arr[j])
			{
				flag = true;
				break;
			}
		}
		++prev;
		if(flag == false)
		{
			count = 1;
			++index1_2;
			loop = maxindex - i;
			num[index1_2] = arr[i];
			temp = i;
			for(int k =1;k<=loop;k++)
			{
				temp = temp + 1;
				if(arr[i]==arr[temp])
				{
					count = count + 1;
				}
			}

			freq[index1_2] = count;
			
			
		}
	}

	
	cout << "Mode = ";
	largest = freq[0];
	for(int i =1;i<=index1_2;i++)
	{
		if(freq[i]>largest)
		{
			largest = freq[i];
		}
	}

	for(int i=0;i<index1_2;i++)
	{
		if(largest==freq[i])
		{
			cout << num[i] << " ";
		}
	}

}