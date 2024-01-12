#include<iostream>
using namespace std;

bool P(int x, int y)
{
	if (x == y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int D1[5] = {0,0,1,0,0};
	int D2[5] = {1,2,2,2,2};
	
	bool xyHitEveryTime = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (P(D1[i], D2[j]) == false)
			{
				xyHitEveryTime = false;
				j = 5;
				i = 5;
			}
		}
	}
	cout << "Truth value is: " << xyHitEveryTime;*/
	
	bool yHitOnce;
	for (int i = 0; i < 5; i++)
	{
		yHitOnce = false;
		for (int j = 0; j < 5; j++)
		{
			if (P(D1[i], D2[j]) == true)
			{
				yHitOnce = true;
				j = 5;
			}
		}
		if (yHitOnce == false)
		{
			break;
		}
	}
	cout << "Truth value is: " << yHitOnce;

	bool xHitOnce;
	for (int i = 0; i < 5; i++)
	{
		xHitOnce = true;
		for (int j = 0; j < 5; j++)
		{
			if (P(D1[i], D2[j]) == false)
			{
				xHitOnce = false;
				j = 5;
			}
		}
		if (xHitOnce == true)
		{
			break;
		}
	}
	cout << "Truth value is: " << xHitOnce;
	
	bool xyHitOnce = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (P(D1[i], D2[j]) == true)
			{
				xyHitOnce = true;
				j = 5;
				i = 5;
			}
		}
	}
	cout << "Truth value is: " << xyHitOnce;
	
	cout << endl;
	system("pause");
	return 0;
}