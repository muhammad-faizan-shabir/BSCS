#include <iostream>
using namespace std;
int main()
{
	int AmtDue;
	int AmtRecieved;
	int AmtInReturn;
	int dollars;
	int quarters;
	int dimes;
	int nickels;
	int pennies;

	cout << "Enter amount due in pennies only for example 274 instead of 2.74" << endl;
	cin >> AmtDue;

	cout << "Enter the amount received in pennies only" << endl;
	cin >> AmtRecieved;

	if(AmtDue==AmtRecieved)
	{
		cout << "The customer should recieve 0 Dollars, 0 Quarters, 0 Dimes, 0 Nickels and 0 pennies" << endl;
	}
	else
	{
		AmtInReturn = AmtRecieved - AmtDue;
		dollars = AmtInReturn / 100;
		quarters = (AmtInReturn % 100) / 25;
		dimes = ((AmtInReturn % 100) % 25) / 10;
		nickels = (((AmtInReturn % 100) % 25) % 10) / 5;
		pennies = ((((AmtInReturn % 100) % 25) % 10) % 5);

		cout << "The customer should receive: " << endl;
		cout << "Dollars: " << dollars << endl;
		cout << "Quarters: " << quarters << endl;
		cout << "Dimes: " << dimes << endl;
		cout << "Nickels: " << nickels << endl;
		cout << "Pennies: " << pennies << endl;
	}
}