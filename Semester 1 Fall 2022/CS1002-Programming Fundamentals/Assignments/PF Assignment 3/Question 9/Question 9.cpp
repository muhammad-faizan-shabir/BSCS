#include <iostream>
using namespace std;
int main()
{
	int N; // number entered by user
	int tempSteps; // to store number of steps temporarily
	int longestSteps = -99; // initializing longestSteps with a very small value
	int maxNum; // Will store the largest number with longest collatz steps
	int n; // will store number whose steps are to be calculated


	cout << "Enter a positive number N to get the largest number with longest collatz sequence" << endl;
	cout << "in the range 1 to N : ";

	cin >> N;
	cout << endl;

	for(int i =1;i<=N;i++) // loop will run for each number in the range 1 to N
	{
		tempSteps = 0;
		for(n=i;n!=1;) // loop will run until n becomes 1
		{
			if((n%2)==0) // if number is even
			{
				n = n / 2;
				tempSteps++;
			}
			else  // if number is odd
			{
				n = (3 * n) + 1;
				tempSteps++;
			}
		}

		if(tempSteps>=longestSteps) // finding largest number with longest collatz steps
		{
			longestSteps = tempSteps;
			maxNum = i;
		}
	}

	cout << maxNum << " is the largest number in the range 1 to " << N << endl;
	cout<<"that has longest collatz sequence with "<<longestSteps<<" steps" << endl;
}