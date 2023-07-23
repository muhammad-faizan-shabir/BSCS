#include <iostream>
using namespace std;
int main()
{
	const float discount1 = 0.1; //10 percent
	const float discount2 = 0.2; //20 percent
	const float discount3 = 0.3; //30 percent
	const float AdditionalDiscount = 0.05; //5 percent
	float discountApplicable =0.0;
	float CostPerRoom;
	int NumOfRooms;
	int NumOfDays;
	float SaleTaxPerc;
	float TotalCost;
	float SaleTaxAmt;
	float TotalPayable;

	cout << "Enter the cost of renting one room: " << endl;
	cin >> CostPerRoom;

	cout << "Enter the number of rooms booked: " << endl;
	cin >> NumOfRooms;

	cout << "Enter the number of days the rooms are booked: " << endl;
	cin >> NumOfDays;

	cout << "Enter the sales tax (as a percent): " << endl;
	cin >> SaleTaxPerc;

	cout << "The cost of renting one room is: " << CostPerRoom<<endl;

	if((NumOfRooms>=10)&&(NumOfRooms<=19))
	{
		cout << "10% discount is applicable" << endl;
		discountApplicable = discountApplicable + discount1;
	}
	else if((NumOfRooms >= 20) && (NumOfRooms <= 29))
	{
		cout << "20% discount is applicable" << endl;
		discountApplicable = discountApplicable + discount2;
	}
	else if((NumOfRooms >= 30))
	{
		cout << "30% discount is applicable" << endl;
		discountApplicable = discountApplicable + discount3;
	}
	
	if(NumOfDays>=3)
	{
		cout << "You will get additional 5% discount" << endl;
		discountApplicable = discountApplicable + AdditionalDiscount;
	}

	cout << "The discount on each room as a percent is: " << (discountApplicable * 100) << "%" << endl;

	cout << "The number of rooms booked are: " << NumOfRooms << endl;

	cout << "The number of days the rooms are booked: " << NumOfDays << endl;

	TotalCost = NumOfRooms * CostPerRoom * NumOfDays;

	cout << "The total cost of the rooms is: " << TotalCost << endl;

	SaleTaxAmt = TotalCost * (SaleTaxPerc / 100.0);

	cout << "The sale tax in addition to total cost is: " << SaleTaxAmt << endl;

	TotalPayable = (TotalCost + SaleTaxAmt) * (1.0 - discountApplicable);

	cout << "Total payable amount after any available discount is: " << TotalPayable << endl;


}