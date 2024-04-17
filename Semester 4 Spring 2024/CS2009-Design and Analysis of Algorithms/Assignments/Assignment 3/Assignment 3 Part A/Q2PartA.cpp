#include<iostream>
#include<vector>
using namespace std;

// Top Down Recursive Solution
int LIS(int Arr[], int currIdx, int prev)
{
	if (currIdx < 0)
	{
		return 0;
	}

	int length = LIS(Arr, currIdx - 1, prev);

	if (prev == -1 || Arr[currIdx] < Arr[prev])
	{
		length = max(length, 1 + LIS(Arr, currIdx - 1, currIdx));
	}

	return length;
}

// Bottom Up Iterative Solution
int LIS(int Arr[],int n)
{
	vector<int> R(n, 1);

	int maxLIS = 1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(Arr[j]<Arr[i])
			{
				R[i] = max(R[i],R[j]+1);
				maxLIS = max(maxLIS,R[i]);
			}
		}
	}
	return maxLIS;
}

int main()
{
	int Arr[] = { 3,10,2,1,20 };
	
	cout << LIS(Arr,5);
	return 0;
}