#include <iostream> //program to enter day number and print day of week
using namespace std;
int main()
{
	int daynum;
	cout << "Enter day number of the week" << endl;
	cin >> daynum;
	if((daynum>=1)&&(daynum<=7))
	{
		switch(daynum)
		{
		case 1:
			cout << "Monday" << endl;
			break;
		case 2:
			cout << "Tuesday" << endl;
			break;
		case 3:
			cout << "Wednesday" << endl;
			break;
		case 4:
			cout << "Thursday" << endl;
			break;
		case 5:
			cout << "Friday" << endl;
			break;
		case 6:
			cout << "Saturday" << endl;
			break;
		case 7:
			cout << "Sunday" << endl;
			break;
		}
	}
	else
	{
		cout << "Invalid day number" << endl;
	}

}