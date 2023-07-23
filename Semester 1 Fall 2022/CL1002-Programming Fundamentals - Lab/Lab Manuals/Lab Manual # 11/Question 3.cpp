#include <iostream>
using namespace std;
int main()
{
	struct circle // structure named circle
	{
		float diameter;
		float radius;
		float area;

		void input() // function inside the structure
		{
			cout << "Input the diameter: ";
			cin >> diameter;
			cout <<endl<< "The radius is: ";
			radius = diameter / 2.0;
			cout << radius << endl;
			cout <<endl<< "The area is: ";
			area = (3.142) * radius * radius;
			cout << area << endl;
		}
	};

	circle circle; // creating a variable named circle of type circl
	circle.input(); // calling the input function of the circle
}