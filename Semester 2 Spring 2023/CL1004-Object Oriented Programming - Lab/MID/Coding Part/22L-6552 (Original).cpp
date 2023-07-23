#include<iostream>
using namespace std;

class Matrix
{
	char**arr;
	int rows;
	int cols;
public:
	Matrix(int r = 0, int c = 0,char**a=nullptr)
	{
		rows = r;
		cols = c;
		arr = nullptr;
	}

	char** getArr()
	{
		return arr;
	}


	void AllocateMemory()
	{
		arr= new char*[rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new char[cols];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j << cols; j++)
			{
				arr[i][j] = '-';
			}
		}
	}

	void InputMatrix()
	{
		cout << "Enter characters in the matrix: " << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << "Enter value at: " << i << " " << j << ": ";
				cin >> arr[i][j];
			}
		}
	}

	void DisplayMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}

	void removeFromMatrix(const char rchar, char**matrix2)
	{

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (arr[i][j] == rchar)
				{
					for (int k = 0; k < cols; k++)
					{
						arr[i][k] = '-';
					}

					for (int k = 0; k < rows; k++)
					{
						arr[k][j] = '-';
					}
				}
			}
		}


		int k = 0;
		int l = 0;
		for (int i = 0; i < rows; i++)
		{
			l = 0;
			for (int j = 0; j < cols; j++)
			{
				if (arr[i][j] != '-')
				{
					matrix2[k][l] = arr[i][j];
				}
				l++;
			}
			k++;
		}
	}

	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
			arr[i] = nullptr;
		}
		delete[] arr;
		arr = nullptr;
	}
};

int main()
{
	char rchar;
	int rows;
	int cols;
	cout << "Enter rows: ";
	cin >> rows;

	cout << "Enter cols: ";
	cin >> cols;
	Matrix M1(rows, cols);
	Matrix M2(rows, cols);
	M2.AllocateMemory();
	M1.AllocateMemory();
	
	M1.InputMatrix();
	cout << "Original Matrix: " << endl;
	M1.DisplayMatrix();
	cout << "Enter the character to be removed: ";
	cin >> rchar;
	M1.removeFromMatrix(rchar,M2.getArr());
	cout << "The Matrix after removal is: " << endl;
	
	M2.DisplayMatrix();



	cout << endl;
	system("pause");
}