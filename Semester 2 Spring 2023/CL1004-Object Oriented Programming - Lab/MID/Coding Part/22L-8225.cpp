#include <iostream>
using namespace std;

class Matrix{
	char **matrix;
	int rows;
	int cols;
public:
	Matrix(int r = 0, int c = 0)
	{
		rows = r;
		cols = c;
		**matrix = NULL;
	}
	void AllocateMemory()
	{
		matrix = new char*[rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new char[cols];
		}

	}
	void inputMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << "Enter " << i + 1 << " row and " << j + 1 << " column element:" << endl;
				cin >> matrix[i][j];
			}
		}
	}
	void DisplayMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[]matrix[i];
		}
		delete[]matrix;
		matrix = NULL;
	}

	void removefromMatrix(const char rchar, char**matrix2)
	{
		int temp[10][2], a = 0, b = 0;




		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == rchar)
				{
					for (int k = i; k < cols; k++)
					{
						matrix2[i][k] = '-';
					}
					for (int k = i; k >= 0; k--)
					{
						matrix2[i][k] = '-';
					}
					for (int k = j; k < rows; k++)
					{
						matrix2[k][j] = '-';
					}
					for (int k = j; k >= 0; k--)
					{
						matrix2[k][j] = '-';
					}
				}
			}

		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix2[i][j] == matrix[i][j];
			}
		}
		
	}
	};

	int main()
	{
		int r, c;
		char	rchar;
		char **matrix2;
		
		cout << "Enter character to remove:";
		cin >> rchar;
		cout << "Enter no of rows:";
		cin >> r;
		cout << "enter no of columns:";
		cin >> c;

		
		matrix2 = new char*[r];
		for (int i = 0; i < r; i++)
		{
			matrix2[i] = new char[c];
		}

		Matrix mat1(r,c);
		mat1.AllocateMemory();
		mat1.inputMatrix();
		mat1.DisplayMatrix();
		mat1.removefromMatrix(rchar, matrix2);

		for (int i = 0; i < r; i++)
		{
			delete[]matrix2[i];
		}
		delete[]matrix2;
		matrix2 = NULL;

		system("pause");
	}
