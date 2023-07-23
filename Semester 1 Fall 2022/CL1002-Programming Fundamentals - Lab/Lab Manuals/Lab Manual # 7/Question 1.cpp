#include <iostream>
using namespace std;
int main()
{
	double hours[6]; // array to store hours
	double tempHours; // temporary variable to store hour of a single employee

	for(int i = 0; i < 6; i++) // loop will add hours in the array
	{
		cout << "Enter hours of employee # " << i + 1 << ": ";
		cin >> tempHours;

		hours[i] = tempHours;
	}

	cout << endl;
	for (int i = 0; i < 6; i++) // loop will output the hours in the array
	{
		cout << "Hours of employee # " << i + 1 << " are: ";
		cout << hours[i] << endl;
	}

	
}