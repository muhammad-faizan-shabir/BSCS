#include <iostream>
using namespace std;
int main()
{
	double hours[5];
	double PayperHour;
	double tempHour;

	cout << "Enter pay per hour: ";
	cin >> PayperHour;

	for(int i =0;i<5;i++)
	{
		cout << "Enter hours of employee# " << i+1<<" : ";
		cin >> tempHour;
		
		hours[i] = tempHour;

	}
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout << "Wage of employee# " << i + 1 << " is " << hours[i] * PayperHour << endl;
	}
}