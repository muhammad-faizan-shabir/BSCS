#include <iostream>
using namespace std;
int main()
{
	float BMI;
	float weight;
	float height;
	cout << "Enter your weight in pounds: " << endl;
	cin >> weight;
	cout << "Enter your hieght in inches: ";
	cin >> height;
	BMI = (weight * 703) / (height * height);
	if((BMI>=18.5)&&(BMI<=25))
	{
		cout << "Your weight is optimal" << endl;

	}
	else if(BMI < 18.5)
	{
		cout << "You are underweighted" << endl;
	}
	else 
	{
		cout << "You are overweighted" << endl;
	}



}