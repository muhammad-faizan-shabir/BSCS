#include <iostream>
using namespace std;
int main()
{
	int day;
	int duration;
	double time = 0;
	int choice = 1;
	double cost;

	
	
	for (;;)
	{
		cout << "Enter the day number of week: ";
		cin >> day;

		if ((day != 6) && (day != 7))
		{
			cout << "Enter start time of call e.g 13.30 or 8.40: ";
			cin >> time;
		}

		

		cout << "Enter the duration of call in minutes: ";
		cin >> duration;
		
		
		if (choice == 1)
		{
			if (((time >= 8) && (time <= 18)) && ((day >= 1) && (day <= 5)))
			{
				cost = duration*0.4;
			}

			if (((time < 8) || (time >18)) && ((day >= 1) && (day <= 5)))
			{
				cost = duration*0.25;
			}
			
			if ((day == 6) || (day == 7))
			{
				cost = duration*0.15;
			}
		}
		

		cout << "The cost of the call is: " << cost << endl;

		cout << "Enter 1 to continue and 0 to exit: ";
		cin >> choice;

		if (choice != 1)
		{
			break;
		}
		
	}

	
}