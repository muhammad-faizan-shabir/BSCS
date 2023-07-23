#include<iostream>
using namespace std;

char** AllocateMemory(int &rows, int &cols)
{
	char**arr = new char*[rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new char[cols];
	}

	return arr;
}

void InputMatrix(char** matrix, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter char at index " << i <<"  " << j << ": ";
			cin >> matrix[i][j];
		}
	
	}
}


void DisplayMatrix(char**matrix, const int&rows, const int&cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


bool isAllDiagonal(char**matrix, const int&rows, const int&cols)
{
	bool flag = true;
	if (rows == cols)
	{
		int temp = matrix[0][0];

		for (int i = 0; i < rows; i++)
		{
			for (int j =0; j < cols; j++)
			{
				if (i == j)
				{
					if (temp != matrix[i][j])
					{
						flag = false;
					}
				}

				if ((i + j) == (rows - 1))
				{
					if (temp != matrix[i][j])
					{
						flag = false;
					}
				}
			}
		}
		return flag;
	}
	else
	{
		return false;
	}
}

void rotateAntiClockWise(char**matrix, const int&rows, const int&cols)
{
	if (isAllDiagonal(matrix, rows, cols))
	{
		char**temp = new char*[rows];
		for (int i = 0; i < rows; i++)
		{
			temp[i] = new char[cols];
		}

		int k = 0;
		int l = 0;
		for (int i = rows-1; (i >=0) ; i--)
		{
			l = 0;
			for (int j = 0; (j <cols); j++)
			{
				temp[k][l] = matrix[j][i];
				l++;
			}
			k++;
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = temp[i][j];
			}
		}

		for (int i = 0; i < rows; i++)
		{
			delete[] temp[i];
			temp[i] = nullptr;
		}
		delete[]  temp;
		temp = nullptr;


	}
	else
	{
		cout << "Rotation not possible" << endl;
	}
}



int main()
{
	int rows=6;
	int cols = 6;

	char **temp  = AllocateMemory(rows, cols);

	InputMatrix(temp, rows, cols);
	
	DisplayMatrix(temp, rows, cols);

	rotateAntiClockWise(temp, rows, cols);
	cout << endl;
	DisplayMatrix(temp, rows, cols);

	system("pause");


}

