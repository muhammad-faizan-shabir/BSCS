#include<iostream>
using namespace std;

template<class T>
class Matrix // template class
{
	int **matrix;
	int rows, columns;
public:
	Matrix(int rows = 0, int columns = 0) // overloaded constructo
	{
		this->rows = rows;
		this->columns = columns;

		matrix = new int*[rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[columns];
		}
	}

	Matrix(Matrix const&obj) // copy constructor
	{
		rows = obj.rows;
		columns = obj.columns;

		matrix = new int*[rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[columns];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matrix[i][j] = obj.matrix[i][j];
			}
		}
	}

	void insertElement(T const& element, int rowNo, int colNo) // insert function
	{
		matrix[rowNo][colNo] = element;
	}

	Matrix<T> operator+(Matrix const&obj) // overloaded + operator
	{
		if ((rows == obj.rows) && (columns == obj.columns))
		{
			Matrix<T> sum(rows, columns);

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					sum.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
				}
			}
			return sum;
		}
		else
		{
			cout << "Addition not possible" << endl;
			Matrix<T> sum(0, 0);
			return sum;
		}
	}

	void print() // print function
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void transpose() // transpose function
	{
		int **tempMatrix = new int*[columns];
		for (int i = 0; i < columns; i++)
		{
			tempMatrix[i] = new int[rows];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				tempMatrix[j][i] = matrix[i][j];
			}
		}

		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;

		matrix = tempMatrix;
		int temp = rows;
		rows = columns;
		columns = temp;
	}

	~Matrix() // destructor
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
};

template<>
class Matrix<char*> // specialized template
{
	char*** matrix;
	int rows;
	int columns;
public: 
	Matrix(int rows = 0, int columns = 0) // constructor
	{
		this->rows = rows;
		this->columns = columns;

		matrix = new char**[rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new char*[columns];
			for (int j = 0; j < columns; j++)
			{
				matrix[i][j] = nullptr;
			}
		}
	}
	
	void insertElement(char * element, int rowNo, int colNo)  // insert function
	{
		if (matrix[rowNo][colNo] != nullptr)
		{
			delete [] matrix[rowNo][colNo];
		}

		int i;
		for (i = 0; element[i] != '\0'; i++)
		{
		}

		matrix[rowNo][colNo] = new char[i + 1];

		for (int j = 0; j < i + 1; j++)
		{
			matrix[rowNo][colNo][j] = element[j];
		}
	}
	 
	void assign(char * element, int rowNo, int colNo)  // variation of insert function
	{
		int i;
		for (i = 0; element[i] != '\0'; i++)
		{
		}

		matrix[rowNo][colNo] = new char[i + 1];

		for (int j = 0; j < i + 1; j++)
		{
			matrix[rowNo][colNo][j] = element[j];
		}
	}

	Matrix(Matrix const &obj) // copy constructor
	{
		rows = obj.rows;
		columns = obj.columns;

		matrix = new char**[rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new char*[columns];
			for (int j = 0; j < columns; j++)
			{
				matrix[i][j] = nullptr;
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				insertElement(obj.matrix[i][j],i,j);
			}
		}
	}

	Matrix operator+(Matrix const&obj) // overloaded + operator
	{
		if ((rows == obj.rows) && (columns == obj.columns))
		{
			Matrix sum(rows, columns);
			
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					int size1;
					for (size1 = 0; this->matrix[i][j][size1] != '\0'; size1++)
					{
					}
					
					int size2;
					for (size2 = 0; obj.matrix[i][j][size2] != '\0'; size2++)
					{
					}

					sum.matrix[i][j] = new char[size1+size2+1];
					
					int k;
					for (k = 0; k < size1; k++)
					{
						sum.matrix[i][j][k] = matrix[i][j][k];
					}

					for (int l = 0; k<size1+size2+1; k++, l++)
					{
						sum.matrix[i][j][k] = obj.matrix[i][j][l];
					}
				}
			}
			return sum;
		}
		else
		{
			cout << "Addition not possible" << endl;
			Matrix sum(0,0);
			return sum;
		}
	}
	 
	void print() // print function
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matrix[i][j] << "     ";
			}
			cout << endl;
		}
	}

	void transpose() // transpose function
	{ 
		char*** tempMatrix = new char**[columns];
		for (int i = 0; i < columns; i++)
		{
			tempMatrix[i] = new char*[rows];
			for (int j = 0; j < rows; j++)
			{
				tempMatrix[i][j] = nullptr;
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				int k;
				for (k = 0; matrix[i][j][k] != '\0'; k++)
				{
				}

				tempMatrix[j][i] = new char[k + 1];

				for (int l= 0; l < k + 1; l++)
				{
					tempMatrix[j][i][l] = matrix[i][j][l];
				}
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				delete[] matrix[i][j];
			}
			delete[] matrix[i];
		}
		delete[] matrix;

		matrix = tempMatrix;
		int temp = rows;
		rows = columns;
		columns = temp;
	}
	
	Matrix operator=(const Matrix & obj) // overloaded assignment operator
	{
		if (this != &obj)
		{
			if (matrix != nullptr)
			{
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < columns; j++)
					{
						delete[] matrix[i][j];
					}
					delete[] matrix[i];
				}
				delete[] matrix;
			}

			rows = obj.rows;
			columns = obj.columns;

			matrix = new char**[rows];
			for (int i = 0; i < rows; i++)
			{
				matrix[i] = new char*[columns];
				for (int j = 0; j < columns; j++)
				{
					assign(obj.matrix[i][j], i, j);
				}
			}
		}
		return obj;
	}
	
	~Matrix() // destructor
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				delete[] matrix[i][j];
			}
			delete[] matrix[i];
		}
		delete[] matrix;
	}
};

int main()
{
	Matrix<char*> mA(2, 2); // Matrix mA
	mA.insertElement((char*)"Computer", 0, 0);
	mA.insertElement((char*)"Electrical", 0, 1);
	mA.insertElement((char*)"Business", 1, 0);
	mA.insertElement((char*)"Civil", 1, 1);
	cout << "Matrix mA:" << endl;
	mA.print();
	cout << "--------------------------------" << endl;

	Matrix<char*> mB(2, 2);  // Matrix mB
	mB.insertElement((char*)"Science", 0, 0);
	mB.insertElement((char*)"Engineering", 0, 1);
	mB.insertElement((char*)"Administration", 1, 0);
	mB.insertElement((char*)"Engineering", 1, 1);
	cout << "Matrix mB:" << endl;
	mB.print();
	cout << "--------------------------------" << endl;

	Matrix<char*> mC(1, 1);  // Matrix mC
	mC = mA + mB;
	cout << "Matrix mC = mA + mB:" << endl;
	mC.print();
	cout << "--------------------------------" << endl;

	cout << "Matrix mC after transpose:" << endl;
	mC.transpose();
	mC.print();
	cout << "--------------------------------" << endl;

	cout << endl;
	system("pause");
	return 0;
}
