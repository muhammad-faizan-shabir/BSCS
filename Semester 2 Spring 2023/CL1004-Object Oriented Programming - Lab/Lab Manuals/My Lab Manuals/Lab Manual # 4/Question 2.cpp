#include <iostream>
#include <fstream>
using namespace std;

class matrix
{
	int rows;
	int cols;

public:
	void setRows(int row)
	{
		rows = row;
	}
	void setCols(int col)
	{
		cols = col;
	}

	int getRows()
	{
		return rows;
	}

	int getCols()
	{
		return cols;
	}


	int** allocateMemory(int rows, int cols)
	{
		int** matrix = new int* [rows];

		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols];
		}

		return matrix;
	}

	int** InputMatrix(ifstream& fin, int** matrix, int rows, int cols)
	{

		char ch;
		int tempnum = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				fin.get(ch);
				while ((ch != ' ') && (ch != '\n') && (!fin.eof()))
				{
					tempnum = (tempnum * 10) + (ch - 48);

					fin.get(ch);
				}
				(*((*(matrix + i)) + j)) = tempnum;
				tempnum = 0;
			}
		}

		return matrix;
	}

	void rotateOuterLayerBy1(int** matrix, int rows,int cols)
	{
		int temp = matrix[0][0];

		for(int i=1;i<cols;i++)
		{
			matrix[0][i - 1] = matrix[0][i];
		}

		for(int i=1;i<rows;i++)
		{
			matrix[i - 1][cols - 1] = matrix[i][cols - 1];
		}

		for(int i=cols-2;i>=0;i--)
		{
			matrix[rows - 1][i+1] = matrix[rows - 1][i];
		}

		for(int i=rows-2;i>0;i--)
		{
			matrix[i+1][0] = matrix[i][0];
		}

		matrix[1][0] = temp;
	}

	void display(int **matrix,int rows,int cols)
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				cout << matrix[i][j] << "  ";
			}
			cout << endl;
		}
	}
};

int main()
{
	ifstream fin;
	fin.open("data.txt");
	int rows;
	int cols;
	matrix matrix1;
	cout << "Enter the rows: ";
	cin >> rows;
	cout << "Enter the cols";
	cin >> cols;

	matrix1.setRows(rows);
	matrix1.setCols(cols);

	int**array=matrix1.allocateMemory(rows, cols);

	array=matrix1.InputMatrix(fin,array,rows,cols);
	cout << "matrix before: " << endl;

	matrix1.display(array, rows, cols);

	matrix1.rotateOuterLayerBy1(array, rows, cols);
	cout << "matrixs after" << endl;

	matrix1.display(array, rows, cols);

	system("pause");
	



}