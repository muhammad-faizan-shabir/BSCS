#include <iostream>
using namespace std;

void fibonacciSeries(int n)
{
	int x = 1;
	int prev1 = 0;
	int prev2 = 1;
	int temp = 0;

	cout << "The Fibonacci sequence is:";
	cout << prev1;
	cout << "," << prev2;

	while (x <= n - 2)
	{
		temp = prev1 + prev2;
		prev1 = prev2;
		prev2 = temp;
		cout << "," << temp;
		x = x + 1;
	}
	
}

int main()
{
	int N;
	cout << "Enter the value of N to print first N number of Fibonacci Sequence: ";
	cin >> N;
	cout << endl;

	fibonacciSeries(N);
}