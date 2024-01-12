#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int> &a1, int size)
{
	int i, j, min_idx, temp; // declare indexes and temporary variables

	for (i = 0; i<size - 1; i++) // loop will run n-1 times
	{
		min_idx = i; // initially we assume cueent item is minimum

		for (j = i + 1; j<size; j++) // loop run from current index till last
		{
			if (a1[j]<a1[min_idx]) // finding minimum item in the array
			{
				min_idx = j;
			}
		}

		if (min_idx != i) // this coded exchanges current item with the minimum item that is found
		{
			temp = a1[i];
			a1[i] = a1[min_idx];
			a1[min_idx] = temp;
		}

	}
}
void print(vector<int> &a1, int size) // function to print vector
{
	for (int i = 0; i < a1.size(); i++)
	{
		cout << a1[i] << " ";
	}
	cout << endl << endl;
}
int main()
{
	vector<int> a1 = { 64, 34, 25, 12, 22, 11, 90 }; // declaring and initializing vector
	cout << "Array before sorting:" << endl;
	print(a1, a1.size());  // calling print function

	SelectionSort(a1, a1.size()); // calling selection sort function
	cout << "Array after sorting" << endl;
	print(a1, a1.size()); // calling print function
	
	cout << "T(n)= c1 +c2n +((n/2)(n+1))" << endl;
	cout << "big o is O(n^2)" << endl;
	system("pause");
	return 0;
}