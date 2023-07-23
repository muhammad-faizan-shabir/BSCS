#include <iostream>
using namespace std;
void Print(int arr[][3],int rows,int col)
{
	cout << "outputing a 2d array: " << endl;

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout << arr[i][j];
			cout << endl;
		}
	}

}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	Print(arr, 3, 3);
}