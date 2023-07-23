# include <iostream>
using namespace std;
int main()
{
	int quantity;
	float totalcost;
	cout << "Enter the number of items purchased(quantity): " << endl;
	cin >> quantity;
	totalcost = 50 * quantity;
	if (totalcost > 600)
	{
		cout << "You will get the discount" << endl;
		totalcost = totalcost * 0.7;
	}
	else
	{
		cout << "You will not get any discount" << endl;
	}
	cout << "Total Payable amount is: " << totalcost;

}