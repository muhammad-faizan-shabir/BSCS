#include <iostream>
using namespace std;
int main()
{
	int sum = 0;
	int counter = 0;
	int max = -999999;
	int min = 999999;

	int num;

	for (;1;)
	{
		cout << "Enter an intger value:";
		cin >> num;
		if (num < 0)
		{
			break;
		}
		else
		{
			counter++;
			sum = sum + num;

			if (num>max)
			{
				max = num;
			}

			if (num < min)
			{
				min = num;
			}
		}

	}

	cout << endl;

	cout << "Sum = " << sum << endl;
	cout << "average = " << sum / counter << endl;
	cout << "Maximum = " << max << endl;
	cout << "Minimum = " << min << endl;

	
}