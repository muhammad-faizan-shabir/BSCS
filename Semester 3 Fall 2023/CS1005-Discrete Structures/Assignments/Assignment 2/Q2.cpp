#include<iostream>
using namespace std;

int F(int x);
int const n = 1;
int const m = 1;
int D[n];
int C[m];

bool OneToOne(int D[],int n,int C[],int m)
{
	int image;
	int preImageCount;
	for(int i=0;i<m;i++)
    {
		image = C[i];
		preImageCount = 0;
		for(int j=0;j<n;j++)
		{
			if(image==F(D[j]))
			{
				preImageCount++;
			}
			if(preImageCount>1)
			{
				return false;
			}
		}
	}
	return true;
}

bool Onto(int D[], int n, int C[], int m)
{
	int image;
	int preImageCount;
	for(int i=0;i<m;i++)
	{
		image = C[i];
		preImageCount = 0;
		for (int j = 0; j < n; j++)
		{
			if(image == F(D[j]))
			{
				preImageCount++;
			}
		}
		if(preImageCount==0)
		{
			return false;
		}
	}
	return true;
}

bool OneToOneCorrespondance(int D[], int n, int C[], int m)
{
	if((OneToOne(D,n,C,m)==true)&&(Onto(D,n,C,m)==true))
	{
		return true;
	}
	else
	{
		return false;
	}
}