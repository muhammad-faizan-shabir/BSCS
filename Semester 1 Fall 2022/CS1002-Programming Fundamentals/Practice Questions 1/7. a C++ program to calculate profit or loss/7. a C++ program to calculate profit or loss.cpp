#include <iostream>
using namespace std;
int main()
{
	float sellprice;
	float costprice;
	float profit;
	cout << "Enter cost price" << endl;
	cin >> costprice;
	cout << "Enter selling price" << endl;
	cin >> sellprice;
	profit = sellprice - costprice;
	cout << "Profit is: " << profit << endl;

}