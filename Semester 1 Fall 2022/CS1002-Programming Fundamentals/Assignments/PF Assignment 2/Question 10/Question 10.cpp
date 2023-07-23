#include <iostream>
using namespace std;
int main()
{
	float A1;
	float A2;
	float A3;
	float A4;
	float A5;
	float BodyWeight;
	float WristMeasurement;
	float WaistMeasurement;
	float HipMeasurement;
	float ForearmMeasurement;
	float B;
	float BodyFat;
	float BodyFatPercentage;
	char choice;
	
	cout << "Enter 'w' for women fat" << endl;
	cout << "Enter 'm' for men fat" << endl;
	cin >> choice;
	
	if ((choice == 'w') || (choice == 'W')) 
	{
		cout << "You selected women fat" << endl;
		
		cout << "Enter Body Weight: " << endl;
		cin >> BodyWeight;

		cout << "Enter wrist measurement at fullest point: " << endl;
		cin >> WristMeasurement;

		cout << "Enter waist measurement at fullest point: " << endl;
		cin >> WaistMeasurement;

		cout << "Enter hip measurement at fullest point:" << endl;
		cin >> HipMeasurement;

		cout << "Enter forearm measurement at fullest point: " << endl;
		cin >> ForearmMeasurement;

		A1 = (BodyWeight * 0.732) + 8.987;
		A2 = WristMeasurement / 3.140;
		A3 = WaistMeasurement * 0.157;
		A4 = HipMeasurement * 0.249;
		A5 = ForearmMeasurement * 0.434;
		B = A1 + A2 - A3 - A4 + A5;
		BodyFat = BodyWeight - B;
		BodyFatPercentage = (BodyFat * 100) / BodyWeight;

		cout << "Body fat is: " << BodyFat << endl;
		cout << "Body fat percentage is: " << BodyFatPercentage<<"%" << endl;
	}
	else if((choice=='m') || (choice=='M'))
	{
		cout << "You selected men fat" << endl;
		
		cout << "Enter Body Weight: " << endl;
		cin >> BodyWeight;

		cout << "Enter wrist measurement at fullest point: " << endl;
		cin >> WristMeasurement;

		A1 = (BodyWeight * 1.082) + 94.42;
		A2 = WristMeasurement * 4.15;
		B = A1 - A2;
		BodyFat = BodyWeight - B;
		BodyFatPercentage = (BodyFat * 100) / BodyWeight;

		cout << "Body fat is: " << BodyFat << endl;
		cout << "Body fat percentage is: " << BodyFatPercentage<<"%" << endl;
	}
	else
	{
		cout << "Error! wrong input" << endl;
	}

}