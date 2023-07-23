#include<iostream>
using namespace std;

class Matrix
{
	char**arr;
	int rows;
	int cols;
public:
	Matrix(int r = 0, int c = 0, char**a = nullptr)
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
		arr = new char*[rows];
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
						if (arr[i][k] == rchar)
						{
							if (k == j)
							{
								arr[i][k] = '-';
							}
						}
						else
						{
							arr[i][k] = '-';
						}
					}

					for (int k = 0; k < rows; k++)
					{
						if (arr[k][j] == rchar)
						{
							if (k == i)
							{
								arr[k][j] = '-';
							}
						}
						else
						{
							arr[k][j] = '-';
						}
					}
				}
			}
		}
		
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (arr[i][j] != '-')
				{
					int tempI = i;
					int tempJ = j;
					char tempChar = arr[i][j];
					arr[i][j] = '-';

					for (; (arr[tempI][tempJ] == '-'); tempJ--)
					{
						if (tempJ == 0)
						{
							break;
						}
					}

					if (tempJ == 0)
					{
						if ((tempJ == 0) && arr[tempI][tempJ] != '-')
						{
							tempJ++;
						}
					}
					else
					{
						tempJ++;
					}
					arr[tempI][tempJ] = tempChar;
				}
			}
		}

		for (int i = 1; i < rows; i++)
		{
			if (arr[i][0] != '-')
			{
				int j;
				for (j = i - 1; (arr[j][0] == '-');)
				{
					j--;
					if (j <= -1)
					{
						break;
					}
				}
				char* temp = arr[j + 1];
				arr[j + 1] = arr[i];
				arr[i] = temp;
			}
		} 

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix2[i][j] = arr[i][j];
			}
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
	cout << endl;

	Matrix M1(rows, cols);
	M1.AllocateMemory();

	Matrix M2(rows, cols);
	M2.AllocateMemory();

	M1.InputMatrix();
	cout << endl;

	cout << "Original Matrix: " << endl;
	M1.DisplayMatrix();
	cout << endl;

	cout << "Enter the character to be removed: ";
	cin >> rchar;
	cout << endl;

	M1.removeFromMatrix(rchar, M2.getArr());

	cout << "The Matrix after removal is: " << endl;
	M2.DisplayMatrix();

	cout << endl;
	system("pause");
}