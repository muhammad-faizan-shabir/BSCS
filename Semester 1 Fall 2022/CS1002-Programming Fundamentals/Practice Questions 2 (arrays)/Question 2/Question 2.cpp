#include <iostream>
using namespace std;
int main()
{
	int ar[100] = {}; // array to hold all numbers
	int oar[100] = {}; // array to hold odd numbers
	int ear[100] = {}; // array to hold even numbers
	int size; // size of the array to hold all numbers
	int temp1 = 0; // size of even array
	int temp2 = 0; // size of odd array

	cout << "Enter the size of array AR: ";
	cin >> size;
	cout << "Enter " << size << " integers " << endl;
	for(int i=0;i<size;i++) // Inputing all numbers in array
	{
		cin >> ar[i];
	}


	for(int i = 0; i < size;i++ ) // putting even numbers and odd numbers in seperate arrays
	{
		if((ar[i]%2)==0)
		{
			ear[temp1] = ar[i];
			temp1++;
		}
		else
		{
			oar[temp2] = ar[i];
			temp2++;
		}
	}
	
	cout << "The elements of OAR are: " << endl;
	for(int i=0;i<temp2;i++) // Outputing elements of odd array
	{
		cout << oar[i] << endl;

	}

	cout << "The elements of EAR are: " << endl;

	for(int i=0;i<temp1;i++) // outputing elements of even array
	{
		cout << ear[i] << endl;
	}
}