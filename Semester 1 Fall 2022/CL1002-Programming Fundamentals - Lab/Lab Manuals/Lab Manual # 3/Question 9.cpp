#include <iostream>
using namespace std;
int main() 
{
	float grade;
	cout << "Enter your grade points" << endl;
	cin >> grade;
	if ((grade>=0.0)&&(grade<=0.99))
	{
		cout << "Failed semester-registration suspended" << endl;
	}
	else if ((grade >= 1.0) && (grade <= 1.99)) 
	{
		cout << "On probation for next semester" << endl;
	}
	else if((grade>=2.0)&&(grade<= 2.99))
	{
		cout << "(no message)" << endl;
	}
	else if ((grade >=3.0)&&(grade<= 3.49))
	{
		cout << "Dean's list for semester" << endl;
	}
	else 
	{
		cout << "Highest honors for semester" << endl;
	}
}