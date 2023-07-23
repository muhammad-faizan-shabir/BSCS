#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
using namespace std;
int main()
{
	struct division
	{
		string divName;
		float first_quarter_sales;
		float second_quarter_sales;
		float third_quarter_sales;
		float fourth_quarter_sales;
		float total_annual_sales;
		float avg_quarterly_sales;

		void input()
		{
			cout << "Enter data for " << divName << " divison: " << endl;
			cout << "Enter the first quarterly sales for "<<divName<<": ";
			cin >> first_quarter_sales;
			while (first_quarter_sales<0)
			{
				cout << "Please enter a positive value: ";
				cin >> first_quarter_sales;
			}
			cout << "Enter the second quarterly sales for " << divName << ": ";
			cin >> second_quarter_sales;
			while (second_quarter_sales < 0)
			{
				cout << "Please enter a positive value: ";
				cin >> second_quarter_sales;
			}
			cout<< "Enter the third quarterly sales for " << divName << ": ";
			cin >> third_quarter_sales;
			while (third_quarter_sales < 0)
			{
				cout << "Please enter a positive value: ";
				cin >> third_quarter_sales;
			}
			cout << "Enter the fourth quarterly sales for " << divName << ": ";
			cin >> fourth_quarter_sales;
			while (fourth_quarter_sales < 0)
			{
				cout << "Please enter a positive value: ";
				cin >> fourth_quarter_sales;
			}

			total_annual_sales = first_quarter_sales + second_quarter_sales + third_quarter_sales + fourth_quarter_sales;
			
			avg_quarterly_sales = total_annual_sales / 4.0;
			cout << "Total annunal sales are: " << total_annual_sales << endl;
			cout << "Average quarterly sale is: " << avg_quarterly_sales << endl << endl;
        }

	};

	division EastDiv;
	EastDiv.divName = "East";

	division WestDiv;
	WestDiv.divName = "West";

	division NorthDiv;
	NorthDiv.divName = "North";

	division SouthDiv;
	SouthDiv.divName = "South";

	EastDiv.input();
	WestDiv.input();
	NorthDiv.input();
	SouthDiv.input();
}

