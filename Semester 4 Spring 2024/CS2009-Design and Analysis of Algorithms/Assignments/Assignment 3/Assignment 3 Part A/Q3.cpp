#include <iostream>
#include<vector>
#include<string>
using namespace std;

// Function to check if a substring is a palindrome.
bool isPalindrome(int i, int j, string& s) 
{
    while (i < j) 
    {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Recursive Solution
// Recursive function to find the minimum number of partitions to make palindromes.
int minPartitions(int i, int n, string& str) 
{
    // Base case: If we've reached the end of the string.
    if (i == n) return 0;

    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++) 
    {
        if (isPalindrome(i, j, str)) 
        {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + minPartitions(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

// Main function to find the minimum number of partitions for palindrome partitioning.
int palindromePartitioning(string str) 
{
    int n = str.size();
    // Calling the recursive function and subtracting 1 as it counts partitions, not cuts.
    return minPartitions(0, n, str) - 1;
}

// Iterative Solution
// Function to find the minimum number of partitions for palindrome partitioning.
int palindromePartitioning(string str) 
{
    int n = str.size();
    // Create a DP array to store the minimum number of partitions.
    vector<int> dp(n + 1, 0);
    dp[n] = 0; // Initialize the last element to 0.

    // Loop through the string in reverse order.
    for (int i = n - 1; i >= 0; i--) 
    {
        int minCost = INT_MAX;
        // Consider all possible substrings starting from the current index.
        for (int j = i; j < n; j++) 
        {
            if (isPalindrome(i, j, str)) 
            {
                // If the substring is a palindrome, calculate the cost and minimize it.
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    // Subtract 1 as it counts partitions, not cuts.
    return dp[0] - 1;
}

int main() 
{
    string str = "BABABCBADCEDE";
    int partitions = palindromePartitioning(str);
    cout << "The minimum number of partitions: " << partitions << "\n";
    return 0;
}

