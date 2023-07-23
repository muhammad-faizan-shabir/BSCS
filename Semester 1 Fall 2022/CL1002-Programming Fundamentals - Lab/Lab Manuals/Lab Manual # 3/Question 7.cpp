#include <iostream>
using namespace std;
int main()
{
	char choice;
	float side;
	float area;
	float radius;
	
	cout << "Enter capital S for area of square or capital C for area of circle" << endl;
	cin >>choice;
	if (choice == 'S') 
	{
		cout << "Enter side of the square: " << endl;
		cin >> side;
		area = side * side;
		cout << "Area of square is:" << area << endl;
	}
	else if(choice == 'C')
	{
		cout << "Enter radius of the circle: " << endl;
		cin >> radius;
		area = (22 / 7) * (radius * radius);
		cout << "Area of circle is: " << area << endl;

	}
	else
	{
		cout << "wrong input" << endl;
	}
}