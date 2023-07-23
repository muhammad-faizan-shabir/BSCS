#include <iostream>
using namespace std;

void shiftLeft(int arr[], int size) // function to cyclically permute elements of array
{
	int temp = arr[0];

	for (int i = 0; i <= size - 2; i++) // shifting elemets to previous indexes
	{
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = temp;


}

int main()
{
	int a[100]; // declaring array
	int size; // variable to hold size of array
	int split;
	cout << "Enter size of array:";
	cin >> size; // inputing size of array

	cout << "Enter "<<size<<" numbers:" << endl;

	for (int i = 0; i < size; i++) // inputting elements of array
	{
		cin >> a[i];
	}
	
	cout << "Enter the index position of the element to split the array: ";
	cin >> split; // inputing index position of splitting

	for(int i =1;i<=split;i++) // splitting the array
	{
		shiftLeft(a,size);
	}


	cout << endl<<"The resultant array is:" << endl;

	for(int i =0;i<size;i++) // outputin the splitted array
	{
		cout << a[i] << endl;
	}
}