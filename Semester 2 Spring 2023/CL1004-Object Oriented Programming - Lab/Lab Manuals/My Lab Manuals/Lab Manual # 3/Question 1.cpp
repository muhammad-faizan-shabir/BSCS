#include <iostream>
using namespace std;

int** AllocateMemory(int& rows, int& cols)
{
	int** arr = nullptr;

	arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	return arr;
}

void InputMatrix(int** matrix, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter value at " << i << " " << j << " index: ";
			cin >> matrix[i][j];
		}
	}
}

void DisplayMatrix(int** matrix, const int& rows, const int& cols)
{
	cout << "The array is: " << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int* maxCol(int** matrix, const int rows, const int cols)
{
	int* maxCol = new int[cols];
	int temp = 0;
	
	for (int j = 0; j < cols; j++)
	{
		temp = matrix[0][j];
		for (int i = 1; i < rows; i++)
		{
			if (matrix[i][j] > temp)
			{
				temp = matrix[i][j];
			}
		}
		maxCol[j] = temp;
	}

	return maxCol;
}

void DeallocateMemory(int** matrix, const int rows)
{
	for (int i = 0; i < rows; i++)\
	{
		delete[] matrix[i];
		matrix[i] = 0;
	}
	delete[] matrix;
	matrix = 0;
}

int** concat_table(int** table1, int** table2, int row1, int col1, int row2, int col2, bool axis)
{
	if (axis == 0)
	{
		int** arr = nullptr;

		arr = new int* [row1];

		for (int i = 0; i < row1; i++)
		{
			arr[i] = new int[col1 + col2];
		}
		int x;
		for (int i = 0; i < row1; i++)
		{
			x = -1;
			for (int j = 0; j < col1; j++)
			{
				arr[i][(++x)] = table1[i][j];
			}
			for (int k = 0; k < col2; k++)
			{
				arr[i][(++x)] = table2[i][k];
			}
		}
		return arr;
	}
	else
	{
		int** arr = nullptr;

		arr = new int* [row1 + row2];

		for (int i = 0; i < (row1 + row2); i++)
		{
			arr[i] = new int[col1];
		}

		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				arr[i][j] = table1[i][j];
			}
		}
		int k = 0;
		for (int i = row1; i < (row1 + row2);i++)
		{
			for (int j = 0; j < col1; j++)
			{
				arr[i][j] = table2[k][j];
			}
			k++;
		}

		return arr;
	}
}

void main() {
	int rows, cols;
	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter colums: ";
	cin >> cols;

	int** matrix = AllocateMemory(rows, cols);

	InputMatrix(matrix, rows, cols);
	DisplayMatrix(matrix, rows, cols);
	cout << endl;
	
	int* maxColValues = maxCol(matrix, rows, cols);

	cout  << "Max cols are: ";
	for (int i = 0; i < cols; i++)
		cout << *(maxColValues + i) << " ";
	
	cout << endl << endl;

	int row1, col1;
	cout << "Enter row 1: ";
	cin >> row1;
	cout << "Enter col 1: ";
	cin >> col1;
	int** table1 = AllocateMemory(row1, col1);
	InputMatrix(table1, row1, col1);
	
	int row2, col2;
	cout<<endl << "Enter row2 :";
	cin >> row2;
	cout << "Enter col2: ";
	cin >> col2;
	int** table2 = AllocateMemory(row2, col2);
	InputMatrix(table2, row2, col2);

	bool axis;
	cout <<endl<< "Enter 0 for X-axis and 1 for Y-axis: ";
	cin >> axis;

	if(((axis==0)&&(row1==row2))||((axis==1)&&(col1==col2)))
	{
		int** result = concat_table(table1, table2, row1, col1, row2, col2, axis);
		if(axis==0)
		{
			DisplayMatrix(result, row1, col1 + col2);
			DeallocateMemory(result,row1);
		}
		else if(axis==1)
		{
			DisplayMatrix(result,row1+row2,col1);
			DeallocateMemory(result,row1+row2);
		}
		
	}
	else
	{
		cout << "Row/Col mismatch so concatination not possible" << endl;
	}

	DeallocateMemory(matrix,rows);
}

