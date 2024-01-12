#include<iostream>
#include<vector>
using namespace std;


void InsertionSort(vector<int> &a1, int size)
{
	int ItemToBeInserted; // item to be inserted 
	int CurrentItemIdx; // current item index

	for (int i = 1; i<size; i++)
	{
		ItemToBeInserted = a1[i]; // fetching item to be inserted
		CurrentItemIdx = i - 1; // current index 
		while ((a1[CurrentItemIdx]>ItemToBeInserted) && (CurrentItemIdx>=0)) // loop runs while the item to be inserted is less than current index and we do no reach the start of the array
		{
			a1[CurrentItemIdx + 1] = a1[CurrentItemIdx]; // mov current item one posiotion ahead
			CurrentItemIdx = CurrentItemIdx - 1; // update current item index
			if (CurrentItemIdx == -1) // if end of array is reached than exit loop
			{
				break;
			}
		}
		
		a1[CurrentItemIdx + 1] = ItemToBeInserted; // put the item to be inserted at its final place
	}
}

void print(vector<int>&a1, int size) // function to print vector
{
	for (int i = 0; i < a1.size(); i++)
	{
		cout << a1[i] << " ";
	}
	cout << endl << endl;
}

int main()
{
	vector<int> a1 = { 64, 34, 25, 12, 22, 11, 90 }; // declaring and initialinzing vector
	cout << "Array before sorting:" << endl;
	print(a1, a1.size());  // calling print function

	InsertionSort(a1, 7); // calling insertion sort function
	cout << "Array after sorting" << endl;
	print(a1, a1.size()); // calling print function
	cout << endl << endl;
	
	cout << "T(n)= c1+ c2N +((n/2)(n+1))" << endl;
	cout << "O(n^2)" << endl;
	system("pause");
	return 0;

}