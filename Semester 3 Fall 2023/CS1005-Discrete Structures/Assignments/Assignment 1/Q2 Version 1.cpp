#include<iostream>
using namespace std;
int const n = 1;
int const m = 1;
bool P(int x, int y);

int D1[n];// x
int D2[m];// y
bool xyHitEveryTime = true;
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++)
	{
		if (P(D1[i], D2[j]) == false)
		{
			xyHitEveryTime = false;
			j = m;
			i=n
		}
	}
}
cout << "Truth value is: " << xyHitEveryTime;;

int D1[n];// x
int D2[m];// y
bool yHitOnce;
for (int i = 0; i < n; i++)
{
	yHitOnce = false;
	for (int j = 0; j < m; j++)
	{
		if (P(D1[i], D2[j]) == true)
		{
			yHitOnce = true;
			j = m;
		}
	}
	if (yHitOnce == false)
	{
		break;
	}
}
cout << "Truth value is: " << yHitOnce;

int D1[n];// x
int D2[m];// y
bool xHitOnce;
for (int i = 0; i < n; i++)
{
	xHitOnce = true;
	for (int j = 0; j < m; j++)
	{
		if (P(D1[i], D2[j]) == false)
		{
			xHitOnce =false;
			j = m;
		}
	}
	if (xHitOnce == true)
	{
		break;
	}
}
cout << "Truth value is: " << xHitOnce;

int D1[n];// x
int D2[m];// y
bool xyHitOnce=false;
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++)
	{
		if (P(D1[i], D2[j]) == true)
		{
			xyHitOnce = true;
			j = m;
			i = n;
		}
	}
}
cout << "Truth value is: " << xyHitOnce;