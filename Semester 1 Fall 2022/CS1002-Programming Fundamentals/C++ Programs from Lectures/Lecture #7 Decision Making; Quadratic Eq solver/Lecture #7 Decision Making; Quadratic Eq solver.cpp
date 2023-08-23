#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a, b, c;
	double discriminant, r1, r2, img;
	cout << "Enter values of a, b and c" << endl;
	cin >> a >> b >> c;
	if(a==0)
	{
		cout << "Invalid value of a" << endl;
	}
	else
	{
		discriminant = (b * b) - (4 * a * c);

		if(discriminant>0)
		{
			r1 = (-b + sqrt(discriminant)) / (2 * a);
			
			r2 = (-b - sqrt(discriminant)) / (2 * a);

			cout << "Root 1 is: " << r1 << endl;

			cout << "Root 2 is: " << r2 << endl;
		}
		else if(discriminant==0)
		{
			r1 = -b / (2 * a);

			cout << "Root 1 is: " << r1<<endl;
			
			cout << "Root 2 is: " << r1<<endl;
		}
		else //for discriminant less than 0 i.e. negative
		{
			discriminant = -1 * discriminant;// making discriminant positive

			img = sqrt(discriminant) / (2 * a);

			r1 = -b / (2 * a);

			cout << "Root 1 is: " << r1 << " + " << img <<"i"<< endl;

			cout << "Root 2 is:  " << r1 << " - " << img <<"i"<< endl;


		}
	}
}