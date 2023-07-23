#include <iostream>
using namespace std;
int main()
{
	string arr[8][7]
	{
		{"Floor1 ","* ","* ","* ","* ","* ","* "},
		{"Floor2 ","* ","* ","* ","* ","* ","* "},
		{"Floor3 ","* ","* ","* ","* ","* ","* "},
		{"Floor1 ","* ","* ","* ","* ","* ","* "},
		{"Floor1 ","* ","* ","* ","* ","* ","* "},
		{"Floor1 ","* ","* ","* ","* ","* ","* "},
		{"Floor1 ","* ","* ","* ","* ","* ","* "},
		{"Floor1 ","* ","* ","* ","* ","* ","* "}
	};

	int f1roomcount = 6;
	int f2roomcount = 6;
	int f3roomcount = 6;
	int f4roomcount = 6;
	int f5roomcount = 6;
	int f6roomcount = 6;
	int f7roomcount = 6;
	int f8roomcount = 6;

	int statusFirstClass[2] = { 1,1 };
	int statusEconomyClassNosmoking[2] = { 3,1 };
	int statusEconomyClassSmoking[2] = {6,1};

	for(int i=0;i<8;i++)
	{
		for(int j=0;j<7;j++)
		{
			cout <<arr[i][j];
		}
		
		cout << endl;
	}
	int choice;
	cout << "Press -1 to exit or  press 1 to book a room";
	cin >> choice;
	for(;choice!=-1;)
	{
		cout << "Press 1 for First class or Press 2 for Economy class: ";
		cin >> choice;

		if(choice==1)
		{
			if((statusFirstClass[0]<=2)&&(statusFirstClass[1]<=6))
			{
				cout << "Room Booked in First Calss floor " << statusFirstClass[0] << " room " << statusFirstClass[1] << endl;
				arr[statusFirstClass[0]-1][statusFirstClass[1]] = "x ";
				statusFirstClass[1]++;
				if((statusFirstClass[1]>6)&&(statusFirstClass[0]!=2))
				{
					statusFirstClass[0] = 2;
					statusFirstClass[1] = 1;
				}
			}
			else
			{
				cout << "Error! Room not available" << endl;
			}

		}
		else if(choice==2)
		{
			cout << "Press 1 for Non-Smoking Zone or Press 2 for Smoking Zone: ";
			cin >> choice;
			if(choice==1)
			{
				if ((statusEconomyClassNosmoking[0] <= 5) && (statusEconomyClassNosmoking[1] <= 6))
				{
					cout << "Room Booked in First Calss floor " << statusEconomyClassNosmoking[0] << " room " << statusEconomyClassNosmoking[1] << endl;
					arr[statusEconomyClassNosmoking[0] - 1][statusEconomyClassNosmoking[1]] = "X ";
					statusEconomyClassNosmoking[1]++;
					if ((statusEconomyClassNosmoking[1] > 6) && (statusEconomyClassNosmoking[0] < 5))
					{
						statusEconomyClassNosmoking[0]++;
						statusEconomyClassNosmoking[1] = 1;
					}
				}
				else
				{
					cout << "Error! Room not available" << endl;
				}

			}
			else if(choice==2)
			{
				if ((statusEconomyClassSmoking[0] <= 8) && (statusEconomyClassSmoking[1] <= 6))
				{
					cout << "Room Booked in First Calss floor " << statusEconomyClassSmoking[0] << " room " << statusEconomyClassSmoking[1] << endl;
					arr[statusEconomyClassSmoking[0]-1][statusEconomyClassSmoking[1]] = "X ";
					statusEconomyClassSmoking[1]++;
					if ((statusEconomyClassSmoking[1] > 6) && (statusEconomyClassSmoking[0] < 8))
					{
						statusEconomyClassSmoking[0]++;
						statusEconomyClassSmoking[1] = 1;
					}
				}
				else
				{
					cout << "Error! Room not available" << endl;
				}
			}
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << arr[i][j];
			}

			cout << endl;
		}

		cout << endl;
		cout << "Press -1 to exit or  press 1 to book a room";
		cin >> choice;
		if (choice == -1)
		{
			cout << "You pressed -1, program will exist";
		}
	
	}

	
}