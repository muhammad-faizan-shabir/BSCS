#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));

	int arr[5];
	int sum = 0;

	for(int i =0;i<5;i++)
	{
		arr[i] = (rand() % 6) + 1;

	}

	for(int i=0;i<5;i++)
	{
		sum = sum + arr[i];
	}

	cout << "Sum is: " << sum;
}