#include<iostream>
using namespace std;

void ComputeTransitiveClosure(int M[n][n],int TransitiveClosure[n][n])
{
	int tempMatrix[n][n]; // temporary matrix
	int powerMatrix[n][n]; // matrix to hold matrix powers
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			powerMatrix[i][j] = M[i][j]; // initialize power matrix with M[n][n]
			TransitiveClosure[i][j] = M[i][j]; // initialize transitive closure matrix with M[n][n]
		}
	}
	
	for(int counter=1;counter<n;counter++) // loop runs n-1 times
	{ 
		for (int i = 0; i < n; i++) // loop to calculate powers of matrix
		{
			for (int j = 0; j < n; j++)
			{
				tempMatrix[i][j] = 0; // reset temporary matrix entry to zero
				for (int k = 0; k < n; k++)
				{
					tempMatrix[i][j] += powerMatrix[i][k] * M[k][j]; // calculation of one entry of the power matrix
				}
				
				if (tempMatrix[i][j] != 0)
				{
					tempMatrix[i][j] = 1; 
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				powerMatrix[i][j] = tempMatrix[i][j]; // copy the calculated power matrix into the powerMatrix
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				TransitiveClosure[i][j] += powerMatrix[i][j]; // taking union of matrices
				if(TransitiveClosure[i][j]!=0)
				{
					TransitiveClosure[i][j] = 1;
				}
			}
		}
	}
}