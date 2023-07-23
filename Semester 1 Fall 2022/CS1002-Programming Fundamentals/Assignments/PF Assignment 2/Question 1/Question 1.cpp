#include <iostream>
using namespace std;
int main()
{
	int div; 
	int dis;
	int q; 
	int r;
	
	cout << "Enter intger dividend" << endl;
	cin >> div;
	
	cout << "Enter integer divisor" << endl;
	cin >> dis;
	
	q = div / dis;
	r = div % dis;
	
	cout << "Quotient is: " << q << endl;
	cout << "Remainder is: " << r << endl;

}