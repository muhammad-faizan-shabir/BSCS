#include <iostream>
using namespace std;

int main()
{
	int arr1[] = { 2, 5, 3, 4, 7, 9 };
	int arr2[] = { 4 ,5, 1, 9, 2, 3, 7 };

	int sum1 = 0;
	int sum2 = 0;

	for(int i=0;i<6;i++)
	{
		sum1 = sum1 + arr1[i];
	}

	for (int i = 0; i < 7; i++)
	{
		sum2 = sum2 + arr2[i];
	}

	cout << "The extra number is: " << sum2 - sum1 << endl;

}