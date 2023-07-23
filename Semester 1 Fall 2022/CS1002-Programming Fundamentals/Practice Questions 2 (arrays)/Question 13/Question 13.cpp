
#include <iostream>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

// Driver Code
int main()
{
	int a[100];

	int size;

	cout << "Type the length of the array: ";
	cin >> size;

	cout << "type the integers of the array: " << endl;
	
	for(int i = 0;i<size;i++)
	{
		cin >> a[i];
	}

	// Function Call
	int max_sum = maxSubArraySum(a, size);
	cout << "Maximum contiguous sum is " << max_sum;
}
