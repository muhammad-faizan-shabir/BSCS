#include<iostream>
#include<vector>
using namespace std;

// helper function
int abs(int num1,int num2)
{
	int diff = num1 - num2;
	if(diff>=0)
	{
		return diff;
	}
	else
	{
		return (-1 * diff);
	}
}

// helper function
int min(int num1,int num2)
{
	if(num1<num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

// Top Down Recursive solution
int findMinDiff(int Arr[], int i, int SumP1, int SumP2)
{
	if(i<0)
	{
		return abs(SumP1, SumP2);
	}
	
	return min(findMinDiff(Arr,i-1,SumP1+Arr[i],SumP2),findMinDiff(Arr,i-1,SumP1,SumP2+Arr[i]));
}

// Bottom Up Iterative Solution
// Function to find the minimum absolute difference between two subset sums
int minSubsetSumDifference(vector<int> &arr, int n) 
{
	int totSum = 0;

	// Calculate the total sum of the array
	for (int i = 0; i < n; i++) 
	{
		totSum += arr[i];
	}

	// Initialize a DP table to store the results of the subset sum problem
	vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

	// Base case: If no elements are selected (sum is 0), it's a valid subset
	for (int i = 0; i < n; i++) 
	{
		dp[i][0] = true;
	}

	// Initialize the first row based on the first element of the array
	if (arr[0] <= totSum) 
	{
		dp[0][arr[0]] = true;
	}

	// Fill in the DP table using a bottom-up approach
	for (int ind = 1; ind < n; ind++) 
	{
		for (int target = 1; target <= totSum; target++) 
		{
			// Exclude the current element
			bool notTaken = dp[ind - 1][target];

			// Include the current element if it doesn't exceed the target
			bool taken = false;
			if (arr[ind] <= target)
				taken = dp[ind - 1][target - arr[ind]];

			dp[ind][target] = notTaken || taken;
		}
	}

	int mini = 1e9;
	for (int i = 0; i <= totSum; i++) 
	{
		if (dp[n - 1][i] == true) 
		{
			// Calculate the absolute difference between two subset sums
			int diff = abs(i - (totSum - i));
			mini = min(mini, diff);
		}
	}
	return mini;
}

int main() 
{
	vector<int> arr = { 10,20,15,5,25 };
	int n = arr.size();

	cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

	return 0;
}






