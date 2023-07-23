#include <iostream>
using namespace std;
int main()
{
	int A[100];
	int N;
	int num;

	cout << "Enter how many values you want to enter? ";
	cin >> N;

	cout << "Enter " << N << " values in the list: " << endl;

	for(int i =0;i<N;i++)
	{
		cin >> num;
		A[i] = num;
	}

	for(int i =0;i<N;i= i+2)
	{
		cout << A[i] << " ";
	}
}