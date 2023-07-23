#include <iostream>
#include <fstream>
using namespace std;

int** InputMatrix(ifstream& fin,int& rows,int&cols)
{
	char ch;
	int tempnum = 0;

	fin.get(ch);
	while ((ch != ' ') && (ch != '\n')&&(!fin.eof()))
	{
		tempnum = (tempnum*10) + (ch - 48);

		fin.get(ch);
	}
	rows = tempnum;
	tempnum = 0;
	fin.get(ch);
	while ((ch != ' ') && (ch != '\n') && (!fin.eof()))
	{
		tempnum = (tempnum * 10) + (ch - 48);

		fin.get(ch);
	}
	cols = tempnum;
	tempnum = 0;

	int** matrix = new int* [rows];
	for(int i=0;i<rows;i++)
	{
		(* (matrix + i)) = new int[cols];
	}

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			fin.get(ch);
			while ((ch != ' ')&&(ch != '\n') && (!fin.eof()))
			{
				tempnum = (tempnum * 10) + (ch - 48);
			
				fin.get(ch);
			}
			(* ((*(matrix + i)) + j)) = tempnum;
			tempnum = 0;
		}
	}

	return matrix;
}

void OutputMatrix(int**matrix,const int&ROWS,const int&COLS)
{
	for(int i=0;i<ROWS;i++)
	{
		for(int j=0;j<COLS;j++)
		{
			cout << *((*(matrix + i)) + j);
			if((*((*(matrix + i)) + j))>9)
			{
				cout << "    ";
			}
			else
			{
				cout << "     ";
			}
		}
		cout << endl;
	}
}

int**AddMatrix(int**matrixA,int**matrixB,const int&ROWS,const int&COLS)
{
	int** R = new int* [ROWS];

	for (int i = 0; i < ROWS; i++)
	{
		(*(R + i)) = new int[COLS];
	}


	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			(*((*(R + i)) + j)) = (*((*(matrixA + i)) + j)) + (*((*(matrixB + i)) + j));
		}
	}

	return R;
}

int**TransposeMatrix(int**matrix,const int&ROWS,const int&COLS)
{
	int** transpose = new int*[COLS];

	for(int i=0;i<COLS;i++)
	{
		transpose[i] = new int[ROWS];
	}

	for(int i=0;i<COLS;i++)
	{
		for(int j=0;j<ROWS;j++)
		{
			(*((*(transpose + i)) + j)) = (*((*(matrix + j)) + i));
		}
	}
	return transpose;
}

bool IsSymmetric(int**matrix,const int &ROWS,const int &COLS)
{
	bool IsSymmetric = 1;
	if (ROWS == COLS)
	{
		for(int i=0;i<ROWS;i++)
		{
			for(int j=0;j<COLS;j++)
			{
				if(!((*((*(matrix + i)) + j))== (*((*(matrix + j)) + i))))
				{
					IsSymmetric = 0;
				}
			}
		}
	}
	return IsSymmetric;
}

void InterchangeRows(int* &row1, int*  &row2)
{
	int* temp;
	temp = row1;
	row1 = row2;
	row2 = temp;
}

void InterchangeRows(int** matrix,const int&ROWS,const int&COLS)
{
	cout << "row1: 1" << endl; // hard coded row number
	cout << "row2: 3" << endl; // hard coded row number
	InterchangeRows(*(matrix + 0), *(matrix + 2));
}



int main()
{
	ifstream fin;
	fin.open("InputFile.txt");
	
	
	int rowsA;
	int colsA;
	int **matrixA=InputMatrix(fin, rowsA, colsA);

	int rowsB;
	int colsB;
	int** matrixB = InputMatrix(fin, rowsB, colsB);

	int rowsC;
	int colsC;
	int** matrixC = InputMatrix(fin, rowsC, colsC);

	cout << "Matrix A =" << endl;
	OutputMatrix(matrixA,rowsA,colsA);
	cout << endl;

	cout << "Matrix B =" << endl;
	OutputMatrix(matrixB, rowsB, colsB);
	cout << endl;

	cout << "Matrix C =" << endl;
	OutputMatrix(matrixC, rowsC, colsC);
	cout << endl;

	fin.close();

	if((rowsA==rowsB)&&(colsA==colsB))
	{
		cout << "A + B = " << endl;
		OutputMatrix(AddMatrix(matrixA, matrixB, rowsA, colsA), rowsA, colsA);
	}
	else
	{
		cout << "A + B = " << endl;
		cout << "Addition not possible." << endl << endl;
	}

	if((rowsA == rowsC) && (colsA == colsC))
	{
		cout << "A + C = " << endl;
		OutputMatrix(AddMatrix(matrixA, matrixC, rowsA, colsA), rowsA, colsA);
	}
	else
	{
		cout << "A + C = " << endl;
		cout << "Addition not possible." << endl << endl;
	}

	cout << "Transpose of A =" << endl;
	OutputMatrix(TransposeMatrix(matrixA, rowsA, colsA), colsA, rowsA);

	cout << "Transpose of C =" << endl;
	OutputMatrix(TransposeMatrix(matrixC, rowsC, colsC), colsC, rowsC);

	if(IsSymmetric(matrixA, rowsA,colsA))
	{
		cout << "Matrix A is Symmetric" << endl << endl;
	}
	else
	{
		cout << "Matrix A is NOT Symmetric" << endl << endl;
	}

	if (IsSymmetric(matrixB, rowsB, colsB))
	{
		cout << "Matrix B is Symmetric" << endl << endl;
	}
	else
	{
		cout << "Matrix B is NOT Symmetric" << endl << endl;
	}

	cout << "Interchanging Rows of Matrix A: " << endl;
	InterchangeRows(matrixA, rowsA, colsA);
	cout << "After interchanging Rows Matrix A=" << endl;
	
	OutputMatrix(matrixA, rowsA, colsA);

	system("pause");
}



