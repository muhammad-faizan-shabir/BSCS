#include<iostream>
using namespace std;

template<class T>
class Matrix // template class
{
	int **matrix;
	int rows, columns;
public:
	Matrix(int rows = 0, int columns = 0) // overloaded constructor
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
			Matrix<T> sum(0,0);
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
			delete [] matrix[i];
		}
		delete [] matrix;

		matrix = tempMatrix;
		int temp = rows;
		rows = columns;
		columns = temp;
	}

	~Matrix() // destructor
	{
		for (int i = 0; i < rows; i++)
		{
			delete [] matrix[i];
		}
		delete[] matrix;
	}
};

int main()
{
	Matrix<int> m1(2, 3); // Matrix M1
	m1.insertElement(1, 0, 0);
	m1.insertElement(1, 0, 1);
	m1.insertElement(1, 0, 2);
	m1.insertElement(0, 1, 0);
	m1.insertElement(0, 1, 1);
	m1.insertElement(0, 1, 2);
	cout << "Matrix M1:" << endl;
	m1.print();
	m1.transpose();
	cout << "Matrix M1 after transpose:" << endl;
	m1.print();
	cout <<"--------------------------------"<< endl;
	
	Matrix<int> m2(2, 3); // Matrix M2
	m2.insertElement(-1, 0, 0);
	m2.insertElement(-1, 0, 1);
	m2.insertElement(-1, 0, 2);
	m2.insertElement(10, 1, 0);
	m2.insertElement(5, 1, 1);
	m2.insertElement(1, 1, 2);
	cout << "Matrix M2:" << endl;
	m2.print();
	m2.transpose();
	cout << "Matrix M2 after transpose:" << endl;
	m2.print();
	cout << "--------------------------------" << endl;
	
	Matrix<int> m3(m2); // Matrix M3
	cout << "Matrix M3:" << endl;
	m3.print();
	cout << "--------------------------------" << endl;
	
	Matrix<int> m4(m1 + m3); // Matrix M4
	cout << "Matrix M4: " << endl;
	m4.print();
	m4.transpose();
	cout << "Matrix M4 after transpose:" << endl;
	m4.print();
	cout << "--------------------------------" << endl;
	
	system("pause");
	return 0;
}