#include <iostream>
using namespace std;
struct carspec
{
	int seatingCapacity;
	float tankCapacity;
	char engine[500];

	void input()
	{
		cout << "Enter the seating capacity: ";
		cin >> seatingCapacity;
		cout << "Enter the tank capacity: ";
		cin >> tankCapacity;
		cout << "Enter the engine name: ";
		cin.ignore();// imp 
		cin.getline(engine, 500);

		cout << endl;
		cout << "The seating capacity is: ";
		cout << seatingCapacity << endl;
		cout << "The tank capacity is: ";
		cout << tankCapacity << endl;
		cout << "The engine name is: ";
		cout << engine;
	}
};
int main() 
{
	carspec KiaClassic;
	KiaClassic.input();
}