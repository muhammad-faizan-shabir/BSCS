#include <iostream>
using namespace std;
int main()
{
	int rows, cols;
	cout << "Enter size of rows: ";
	cin >> rows;
	cout << "Enter size of cols: ";
	cin >> cols;

	int** arr = nullptr;
	arr = new int* [rows];
	for(int i=0;i<rows;i++)
	{
		arr[i] = new int[cols];
	}

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout << "Enter value at: " << i << " " << j << " index: ";
			cin >> arr[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i=0;i<rows;i++)
	{
		delete[]arr[i];
		arr[i] = 0;
	}
	delete[]arr;
	arr = 0;
}