#include <iostream>
using namespace std;
int main()
{
	int NumOfShares;
	float PricePerShare;
	float commision1;
	float commision2;
	float AmtPaid;
	float AmtSold;
	float profit;

	cout << "Enter the number of shares bought: " << endl;
	cin >>NumOfShares;

	cout << "Enter the price per share: " << endl;
	cin >> PricePerShare;

	AmtPaid = NumOfShares * PricePerShare;
	cout << "The amount of money paid for the stock: " <<AmtPaid<< endl;

	commision1 = AmtPaid * 0.02;
	cout << "The amount of commission paid to broker for the purchase is: " << commision1 << endl;

	cout << "Enter the number of shares sold: " << endl;
	cin >> NumOfShares;

	cout << "Enter the price per share: " << endl;
	cin >> PricePerShare;

	AmtSold = NumOfShares * PricePerShare;
	cout << "The amount that the stocks were sold for is: " << AmtSold << endl;

	commision2 = AmtSold * 0.02;
	cout << "The amount of commission paid to broker for the sale of stocks is: " << commision2 << endl;

	profit = (AmtSold)-(AmtPaid + commision1 + commision2);
	cout << "The amount of profit made after selling the stock and paying the two commissions to the broker is: " << profit << endl;


	 

}