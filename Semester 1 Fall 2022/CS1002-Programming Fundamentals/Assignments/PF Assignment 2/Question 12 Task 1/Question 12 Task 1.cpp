#include <iostream>
using namespace std;
int main()
{
	float X1;
	float Y1;
	float X2;
	float Y2;
	float X3;
	float Y3;
	float M1;
	float M2;
	float M3;
	
	cout << "Enter X coordinate for point 1: " << endl;
	cin >> X1;
	cout << "Enter Y coordinate for point 1: " << endl;
	cin >> Y1;
	cout << "Enter X coordinate for point 2: " << endl;
	cin >> X2;
	cout << "Enter Y coordinate for point 2: " << endl;
	cin >> Y2;
	cout << "Enter X coordinate for point 3: " << endl;
	cin >> X3;
	cout << "Enter Y coordinate for point 3: " << endl;
	cin >> Y3;

	M1 = (Y2 - Y1) / (X2 - X1);
	M2 = (Y3 - Y2) / (X3 - X2);
	M3 = (Y3 - Y1) / (X3 - X1);
	
	if ((M1 == M2) && (M2 == M3) && (M3 == M1))
	{
		cout << "Points 1, 2 and 3 are collinear" << endl;
	}
	else
	{
		cout << "Points 1, 2 and 3 are NOT collinear" << endl;
	}


}