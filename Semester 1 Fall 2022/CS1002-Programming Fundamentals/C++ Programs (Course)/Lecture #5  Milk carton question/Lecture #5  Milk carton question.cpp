#include <iostream>
using namespace std;

int main()
{
    float TotalAmt;
    float NoOfCartons;
    float cost;
    float profit;
    
    cout << "Enter amount of milk in litres" <<endl;
    cin >> TotalAmt;
    
    NoOfCartons = (TotalAmt / 3.78);
    cout << "Number of cartons needed are: " << NoOfCartons<<endl;
    
    cost = 0.38 * TotalAmt;
    cout << "Total cost is:" << cost << endl;
    
    profit = 0.27 * TotalAmt;
    cout << "Total profit is: " << profit << endl;








}