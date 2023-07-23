#include <iostream>

using namespace std;
int main()
{
	double temperature;

	for (; 1;)
	{
		cout << "Enter temperature";
		cin >> temperature;

		if (temperature > 102.5)
		{
			cout << "Temperature exceeded limit of 102.5" << endl;
			break;

		}
		else
		{
			cout << "Temperarture within limit " << endl;
		}
	}




}