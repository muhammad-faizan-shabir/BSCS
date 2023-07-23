#include <iostream>
using namespace std;
int main()
{
	int arr[100]; // declaring array
	int size; // variable to store size of array
	bool flag = false; 

	cout << "Enter size of array: ";
	cin >> size; // inputing size of array

	cout << "Enter " << size << " integers:" << endl;

	for(int i =0;i<size;i++) // inputing integers into array
	{
		cin >> arr[i];
	}
	cout << endl;
	for(int i =0;i<size;i++) 
	{
		if((arr[i]%2)!=0) // checking for odd integers
		{
			cout << "Odd number is: " << arr[i] << endl;
			flag = true;
		}
	}

	if(flag==false) // checking if there were no odd integers
	{
		cout << "No odd numbers" << endl;
	}
}