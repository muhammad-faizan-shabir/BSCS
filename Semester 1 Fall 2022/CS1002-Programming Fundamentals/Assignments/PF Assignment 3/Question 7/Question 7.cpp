#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
int main()
{
	int Ylow; // starting position of needle
	int AngleInDeg; // angle of needle in degrees
	double AngleInRad; // angle of needle in radians
	double Yhigh; // position of upper end of needle
	int hits = 0; // number of successful hits
	
	srand(time(0)); // initializing srand with time 
	
	for (int i = 1; i <= 500; i++) // loop will run for 500 tries
	{
		Ylow = (rand() % 3); // calculating starting position of needle
		
		AngleInDeg = (rand() % 181); // calculating angle of needle in degrees

		AngleInRad = (AngleInDeg * 3.14159) / 180; // calculating angle of needle in radians

		Yhigh = Ylow + (sin(AngleInRad)); // claculating position of upper end of needle
		

		if (Yhigh>=2) // checking whether a hit ot not 
		{
			hits = hits + 1;
		}

	}
	
	cout <<"Total number of hits are: " <<hits<< endl;
	
	if(hits==0) // checking if there were zero successfull hits
	{
		cout << "There were zero hits so the quotient of tries/hits is not possible" << endl;
	}
	else // outputing quotient of tries/hits 
	{
		cout << "The quotient of tries/hits is: " << 500 / hits << endl;
	}
}