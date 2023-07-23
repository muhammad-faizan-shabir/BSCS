#include <iostream>
using namespace std;
int main()
{
	int A[] = { 0,-1,2,-3,1 };
	int x = -2;
	int size = 5;
	bool flag = false;
	for (int i = 0; i < (size - 1); i++)
    {
		for (int j = (i + 1); j < size; j++)
		{
			if (A[i] + A[j] == x)
			{
				flag = true;
			}
		}
	}

	if (flag)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << x << endl;
	}

}