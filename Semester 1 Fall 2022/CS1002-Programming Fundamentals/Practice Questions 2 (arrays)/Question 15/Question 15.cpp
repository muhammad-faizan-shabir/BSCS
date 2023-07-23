# include <iostream>
using namespace std;
int main()
{
	int arr[100]; // declaring array to intially store all numbers
	int DistinctArray[100]; // declaring array to store non-repeated numbers
	int size = 0; // variable to store size of first array
	int temp; // variable to store element of first array
	int num; // variable to stored the entered numbers 
	int size2; // variable to store the size of the second array


	cout << "Enter the size of array: ";
	cin >> size; // inputting size of array


	cout << "Enter " << size << " integers: " << endl;

	for (int i = 0; i < size; i++) // inputting elemnts in the first array
	{
		cin >> num;
		arr[i] = num;
	}

	DistinctArray[0] = arr[0]; // assigning first element of fisrt array to first index of second array
	size2 = 1; //updating size of second array

	for (int i = 1; i < size; i++) // loop will run for the number of elements in the first array    
	{
		temp = arr[i];
		bool flag = true;

		for (int j = 0; j < size2; j++) // loop will run for the number of elements in second array
		{
			if (temp == DistinctArray[j])
			{
				flag = false; // flag will become fasle if the current element is a repeated element
				break;

			}
		}

		if (flag == true)
		{
			DistinctArray[size2] = temp; // storing a non-repeated element in the second array
			size2++;
		}
		else
		{
			cout << endl << temp << " is duplicate " << endl;// outputing the repeated element
		}
	}

}