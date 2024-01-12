#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	// Find Minimum of a and b
	int result = min(a, b);
	while (result > 0) {
		if (a % result == 0 && b % result == 0) {
			break;
		}
		result--;
	}
	// Return gcd of a and b
	return result;
}

int main()
{
	int DiagonalNum = 1;
	int counter;
	int p;
	int q;
	for (counter = 0; counter < 1000;)
	{
		if (DiagonalNum % 2 != 0)
		{
			p = DiagonalNum;
			q = 1;
			do
			{
				if (gcd(p, q) == 1)
				{
					counter++;
					cout << counter << ":" << p << "/" << q << endl;

				}
				--p;
				++q;

			} while ((p > 0) && (q < DiagonalNum + 1) && (counter < 1000));
			++DiagonalNum;
		}
		else
		{
			p = 1; 
			q = DiagonalNum;
			do
			{
				if (gcd(p, q) == 1)
				{
					counter++;
					cout << counter << ":" << p << "/" << q << endl;
				}
				++p;
				--q;
			} while ((p < DiagonalNum + 1) && (q > 0) && (counter < 1000));
			++DiagonalNum;
		}
	}
	return 0;
}