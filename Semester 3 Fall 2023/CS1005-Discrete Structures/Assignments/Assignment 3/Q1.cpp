#include<iostream>
using namespace std;

int const n=8;
int M[n][n];

bool IsTransitive(int M[n][n])
{
    int MSquared[n][n];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MSquared[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                MSquared[i][j] += M[i][k] * M[k][j];
            }

            if (MSquared[i][j] != 0)
            {
                MSquared[i][j] = 1;
            }
        }
    }
    
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(MSquared[i][j] == 1 && M[i][j]==0)
            {
                return false;
            }
        }
    }
    return true;
}







   



