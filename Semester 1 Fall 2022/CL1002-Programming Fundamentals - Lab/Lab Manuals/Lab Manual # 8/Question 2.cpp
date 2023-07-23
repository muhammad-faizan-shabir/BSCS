#include <iostream>
using namespace std;

void rectangle(int h, int w)
{
	if ((h <= 0) || (w <= 0))
	{
		cout << "Reactangle printing is not possible" << endl;
	}
	else
	{
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
}

int main()
{
	int height;
	int width;

	cout << "Enter integer value of height for rectangle: ";
	cin >> height;
	cout << endl;

	cout << "Enter integer value of width fpr rectangleL ";
	cin >> width;
	cout << endl;

	rectangle(height, width);
	
}