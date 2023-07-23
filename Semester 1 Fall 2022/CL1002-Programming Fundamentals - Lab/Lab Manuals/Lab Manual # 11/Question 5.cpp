#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
using namespace std;
struct MonthlyBudget
{
	float housing;
	float utilities;
	float householdExpenses;
	float transportation;
	float food;
	float medical;
	float insurance;
	float entertainment;
	float clothing;
	float miscellaneous;
};

void input(MonthlyBudget &budget)
{
	cout << "Enter the housing expense: ";
	cin >> budget.housing;

	cout << "Enter the utilities expense: ";
	cin >> budget.utilities;

	cout << "Enter the household Expenses : ";
	cin >> budget.householdExpenses;

	cout << "Enter transportation expense: ";
	cin >> budget.transportation;

	cout << "Enter food expense: ";
	cin >> budget.food;

	cout << "Enter medical expense: ";
	cin >> budget.medical;

	cout << "Enter insurance expense: ";
	cin >> budget.insurance;

	cout << "Enter entertainment expense: ";
	cin >> budget.entertainment;

	cout << "Enter clothing expense: ";
	cin >> budget.clothing;

	cout << "Enter miscellaneous expense: ";
	cin >> budget.miscellaneous;
}

void displayReport(MonthlyBudget &budget)
{
	float originalTotal;
	float userTotal;
	cout << endl << endl;

	originalTotal = 500 + 150 + 65 + 50 + 250 + 30 + 100 + 150 + 75 + 50;
	userTotal = budget.housing + budget.utilities + budget.householdExpenses + budget.transportation + budget.food + budget.medical + budget.insurance + budget.entertainment + budget.clothing + budget.miscellaneous;

	if (budget.housing > 500)
	{
		cout << "Housing is above the normal expense" << endl;
	}
	else if (budget.housing < 500)
	{
		cout << "Housing is below the normal expense" << endl;
	}
	else
	{
		cout << "Housing is equal to normal expense" << endl;
	}

	if (budget.utilities > 150)
	{
		cout << "Utilities is above the normal expense" << endl;
	}
	else if (budget.utilities < 150)
	{
		cout << "Utilities is below the normal expense" << endl;
	}
	else
	{
		cout << "Utilities is equal to normal expense" << endl;
	}

	if (budget.householdExpenses > 65)
	{
		cout << "HouseholdExpenses is above the normal expense" << endl;
	}
	else if(budget.householdExpenses<65)
	{
		cout << "HouseholdExpense is below the normal expense" << endl;
	}
	else
	{
		cout << "Household Expenses is equal to normal expense" << endl;
	}

	if(budget.transportation>50)
	{
		cout << "Transportation is above the normal expense" << endl;
	}
	else if(budget.transportation<50)
	{
		cout << "Transportation is below the normal expense" << endl;
	}
	else
	{
		cout << "Transportation is equal to normal expense" << endl;
	}

	if(budget.food>250)
	{
		cout << "Food is above the normal expense" << endl;
	}
	else if(budget.food<250)
	{
		cout << "Food is below the normal expense" << endl;
	}
	else
	{
		cout << "Food is equal to normal expense" << endl;
	}

	if(budget.medical>30)
	{
		cout << "Medical is above the normal expense" << endl;
	}
	else if (budget.medical<30)
	{
		cout << "Medical is below the normal expense" << endl;
	}
	else
	{
		cout << "Medical is equal to normal expense" << endl;
	}

	if(budget.insurance>100)
	{
		cout << "Insurance is above the normal expense" << endl;
	}
	else if (budget.insurance<100)
	{
		cout << "Insurance is below the normal expense" << endl;
	}
	else
	{
		cout << "Insurance is equal to normal expense" << endl;
	}

	if(budget.entertainment>150)
	{
		cout << "Entertainment is above the normal expense" << endl;
	}
	else if(budget.entertainment<150)
	{
		cout << "Entertainment is below the normal expense" << endl;
	}
	else
	{
		cout << "Entertainment is equal to normal expense" << endl;
	}

	if(budget.clothing>75)
	{
		cout << "Clothing is above the normal expense" << endl;
	}
	else if(budget.clothing<75)
	{
		cout << "Clothing is below the normal expense" << endl;
	}
	else
	{
		cout << "Clothing is equal to normal expense" << endl;
	}

	if(budget.miscellaneous>50)
	{
		cout << "Miscellaneous is above the normal expense" << endl;
	}
	else if(budget.miscellaneous<50)
	{
		cout << "Miscellaneous is below the normal expense" << endl;
	}
	else
	{
		cout << "Miscellaneous is equal to normal expense" << endl;
	}
	cout << endl;
	if(originalTotal<userTotal)
	{
		cout << "The total budget entered is above the normal entire monthly budget" << endl;
	}
	else if(originalTotal>userTotal)
	{
		cout << "The total budget entered is below the normal entire monthly budget" << endl;
	}
	else
	{
		cout << "The total budget entered is equal to the normal entire monthly budget" << endl;
	}

	cout << endl << endl;
}

int main()
{
	MonthlyBudget budget;

	input(budget);
	displayReport(budget);
}



