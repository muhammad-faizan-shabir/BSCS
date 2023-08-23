#include <iostream>
using namespace std;

double area(double r)
{
	return ((22.0 / 7) * r * r);
}

int main()
{
	double r;
	double a;

	cout << "Enter radius of ring: ";
	cin >> r;

	a = area(r);
	cout << "Area is :" << a;
}