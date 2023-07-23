//swaping variablee without a third variable
#include <iostream>
using namespace std;
int main()
{
	int x;
	int y;
	cout << "Enter fisrt number" << endl;
	cin >> x;
	cout << "Enter second number" << endl;
	cin >> y;
	cout << "Before swap" << endl;
	cout << "First number is: " << x<<endl;
	cout << "Second number is: " << y<<endl;
	x = x + y;
	y = x - y;
	x = x - y;
	cout << "After swap" << endl;
	cout << "First number is: " << x<<endl;
	cout << "Second number is: " << y<<endl;


}