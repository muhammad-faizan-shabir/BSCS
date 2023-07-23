#include <iostream>
using namespace std;
int main()
{
	double num1;
	double num2;
	double num3;
	double avg;

	double* p1;
	double* p2;
	double* p3;

	cout << "Enter first numeber: ";
	cin >> num1;

	cout << "Enter second number: ";
	cin >> num2;

	cout << "Enter third number: ";
	cin >> num3;

	p1 = &num1;
	p2 = &num2;
	p3 = &num3;

	avg = ((*p1) +(*p2)+(*p3) ) / 3;

	cout << "Average is: " << avg << endl << endl;

	system("pause");
}