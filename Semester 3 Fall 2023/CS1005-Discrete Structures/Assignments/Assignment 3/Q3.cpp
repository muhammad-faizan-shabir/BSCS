#include<iostream>
using namespace std;

void ComputeJ5(int R1[5][10],int R2[5][8], int J5[5][10 + 8 - 5])
{
	for(int i=0;i<5;i++)
	{
		for (int j = 0; j < 10 + 8 - 5;j++) 
		{
			J5[i][j] = -1; // initialize J5 matrix with -1
		}
	}
	
	int ptr = 0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if((R1[i][5]==R2[j][0])&&(R1[i][6]==R2[j][1])&&(R1[i][7] == R2[j][2])&&(R1[i][8] == R2[j][3])&&(R1[i][9] == R2[j][4]))// match last 5 fields of R1 with first 5 fields of R2
			{
				for(int k=0;k<10;k++)
				{
					J5[ptr][k] = R1[i][k]; // get first 10 fields for J5 from 10 fields of R1
				}

				for(int k=10,int l=5;k< 10 + 8 - 5;k++,l++)
				{
					J5[ptr][k] = R2[j][l]; // get last 3 fields for J5 from last 3 fields of R2
				}
			
				ptr++;
				j = 5;
			}
		}
	}
}