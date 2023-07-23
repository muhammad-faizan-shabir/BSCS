#include <iostream>
using namespace std;
int SumOfN(int arr[],int ind,int N,int size)
{
	int sum = 0;
	for (int i = ind; (i < (ind + N)) && (i < size);i++)
	{
		sum = sum + (arr[i]);
	}
	return sum;
}
int main()
{
	int arr[100];
	int ind;
	int N;
	int size;
	int sum;

	cout << "Enter size of array: ";
	cin >> size;

	cout << "Enter " << size << " integers:" << endl;

	for(int i=0;i<size;i++)
	{
		cin >> arr[i];
	}
	cout << endl;
	cout << "Enter the index number idx: ";
	cin >> ind;
	cout << "Enter the value of  N: ";
	cin >> N;
	cout << endl;

	sum = SumOfN(arr,ind,N,size);

	cout << "The sum is: " << sum;
	cout << endl << endl;
}