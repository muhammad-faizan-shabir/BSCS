#include <iostream>
using namespace std;
int main()
{
	int choice;
	cout << "Enter month numbner" << endl;
	cin >> choice;
	if((choice<1)||(choice>12))
	{
		cout << "Invalid month number" << endl;
	}
	else if(choice==2)
	{
		cout << "28 or 29 days" << endl;
	}
	else if((choice==4)||(choice==6)||(choice==9)||(choice==11))
	{
		cout << "30 days" << endl;
	}
	else
	{
		cout << "31 days" << endl;
	}
}