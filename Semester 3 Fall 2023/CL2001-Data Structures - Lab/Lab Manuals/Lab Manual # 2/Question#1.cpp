#include<iostream>
#include<vector>
using namespace std;

void bubblesort(vector<int> &a1,int size)
{
	int n = size - 2; // initially we go till 2nd last index

	for (int i = 0; i < size - 2; i++) // loop runs n-1 times
	{
		for (int j = 0; j <= n; j++) 
		{
			if (a1[j]>a1[j + 1]) // swap if first elemnt is greater than second
			{
				int temp = a1[j];
				a1[j] = a1[j+1];
				a1[j + 1] = temp;
			}
		}
		n = n - 1; // since last element is sorted so decrease size of loop so that no extra comparisons are made
	}

}

void print(vector<int> &a1, int size) // function to print vector array
{
	for (int i = 0; i < a1.size(); i++)
	{
		cout << a1[i] << " ";
	}
	cout << endl << endl;
}
int main()
{
	vector<int> a1 = {64,34,25,12,22,11,90}; // decalaring and initialising vector
	cout << "Array before sorting:" << endl;
	print(a1, a1.size()); // calling print function

	bubblesort(a1, a1.size());// calling buublesort function
	cout << "Array after sorting" << endl;
	print(a1, a1.size()); // calling print function
	
	    
	cout << "time complexity t(n)= c1 + c2n +((n/2)(n+1))" << endl;
	cout << "big o is O(n^2)" << endl;
	system("pause");
	return 0;


}