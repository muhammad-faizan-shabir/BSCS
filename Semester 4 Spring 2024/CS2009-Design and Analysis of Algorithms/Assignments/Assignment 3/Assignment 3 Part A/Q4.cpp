#include <iostream>
#include<vector>
using namespace std;

const int mod = (int)1e9 + 7;

// Function to count the number of ways to achieve the target sum
int findWays(vector<int>& num, int tar) 
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
        dp[0][0] = 2;  // 2 cases - pick and not pick
    else
        dp[0][0] = 1;  // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;  // 1 case - pick

    for (int ind = 1; ind < n; ind++) 
    {
        for (int target = 0; target <= tar; target++) 
        {

            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken + taken)% mod;
        }
    }
    return dp[n - 1][tar];
}

// Function to calculate the number of ways to achieve the target sum
int targetSum(int n, int target, vector<int>& arr) 
{
    int totSum = 0;
    for (int i = 0; i < n; i++) 
    {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;  // Not possible to achieve the target sum

    return findWays(arr, (totSum - target) / 2);
}

int main() 
{
    vector<int> arr = { 1,2,3,1 };
    int target = 3;

    int n = arr.size();
    cout << "The number of ways found is " << targetSum(n, target, arr) << endl;

    return 0;  // Return 0 to indicate successful program execution
}

//Pseudocode version of above code
// Function to count the number of ways to achieve the target sum
int findWays(Arr[],N,target) 
{
    R[0...........N][0........target]={0}
    
    if (Arr[1] == 0)
        R[1][0] = 2;  // 2 cases - pick and not pick
    else
        R[1][0] = 1;  // 1 case - not pick

    if (Arr[1] != 0 && Arr[1] <= target)
        R[1][Arr[1]] = 1;  // 1 case - pick

    for (i= 2; i<= N; i++) 
    {
        for (j = 0; j<= target; j++) 
        {
            notTaken = R[i- 1][j];

            taken = 0;
            if (Arr[i] <= j)
                taken = R[i- 1][j - Arr[i]];

            R[i][j] = (notTaken + taken);//% mod;
        }
    }
    return R[N][target];
}

// Function to calculate the number of ways to achieve the target sum
int targetSum(Arr[],N,target) 
{
    totalSum = 0;
    for (i = 1; i <= N; i++) 
    {
        totalSum += Arr[i];
    }

    // Checking for edge cases
    if (totalSum - target < 0 || (totalSum - target) % 2 != 0)
        return 0;  // Not possible to achieve the target sum

    return findWays(Arr,N, (totalSum - target) / 2);
}