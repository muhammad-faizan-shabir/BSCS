#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float I; //cuurrent
	float E; //voltage
	float R; //resistance
	float L; //inductance
	float C; //capacitance
	float f; //frequency
	const float PI = 22.0 / 7;

	

	cout << "Enter voltage in volts: " << endl;
	cin >> E;

	cout << "Enter resistance in ohms: " << endl;
	cin >> R;

	cout << "Enter inductance in henrys: " << endl;
	cin >> L;

	cout << "Enter capacitanc in farads: " << endl;
	cin >> C;

	cout << "Enter frequency in hertz: " << endl;
	cin >> f;
	
	I = E / ((double) sqrt((R * R) + (((2 * PI * f * L) - (1 / (2 * PI * f * C))) * ((2 * PI * f * L) - (1 / (2 * PI * f * C))))));

	cout << "The current is: " << endl;
	cout<<I;

}