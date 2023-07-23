#include <iostream>
using namespace std;
int main()
{
	int NumOfDays;
	double RunningTotal=0;
	double DailySale;
	cout << "Enter number of days: ";
	cin >> NumOfDays;
	cout << endl;

	for (int i = 1; i <= NumOfDays; i++)
	{
		cout << "Enter Sale for day " << i << ": ";
		cin >> DailySale;

		RunningTotal = RunningTotal + DailySale;
		cout << endl;
	}

	cout << "Running Total for " << NumOfDays << " days is: " << RunningTotal;

	


}