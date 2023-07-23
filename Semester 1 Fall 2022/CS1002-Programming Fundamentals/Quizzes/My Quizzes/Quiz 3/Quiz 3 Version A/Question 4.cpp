#include <iostream>
using namespace std;
int main()
{
	int previous = 700, current = 1000, consumption;
	float total, dollar;
	consumption = current - previous;
	cout << endl << "Consumption = " << consumption << " KW" << endl;
	if (consumption < 70)
	{

		total = consumption * 350;
		dollar = total / 4100;
		cout << endl << "Total Due (riel) = " << total << " riel";
		cout << endl << "Total Due (dollar) = " << dollar << " dollar" << endl;
	}
	else if (consumption < 100)
	{
		total = (consumption - 70) * 500 + (70 * 350);
		dollar = total / 4100;
		cout << endl << "Total Due (riel)= " << total << " riel";
		cout << endl << "Total Due (dollar)= " << dollar << " dollar" << endl;
	}
	else if (consumption < 450)
	{
		total = (consumption - 100) * 770 + (100 * 500) + (70 * 350);
		dollar = total / 4100;
		cout << endl << "Total Due (riel =)" << total << " riel";
		cout << endl << "Total Due (dollar) = " << dollar << " dollar" << endl;
	}
	else
	{
		total = (consumption - 450) * 840 + (450 * 770) + (100 * 500) + (70 * 350);
		dollar = total / 4100;
		cout << endl << "Total Due (riel =)" << total << " riel";
		cout << endl << "Total Due (dollar) = " << dollar << " dollar" << endl;
	}
}