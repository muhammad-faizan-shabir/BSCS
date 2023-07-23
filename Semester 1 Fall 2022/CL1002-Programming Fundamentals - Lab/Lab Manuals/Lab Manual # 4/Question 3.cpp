#include <iostream>
using namespace std;
int main()
{
	float TotalMarks;
	float ObtainedMarks;
	float percentage;
	char grade;
	cout << "Enter the Total Marks:" << endl;
	cin >> TotalMarks;
	cout << "Enter the Obtained Marks: " << endl;
	cin >> ObtainedMarks;
	percentage = (ObtainedMarks / TotalMarks) * 100;

	if (percentage >= 90)
	{
		grade = 'A';
	}
	else if ((percentage >= 80) && (percentage < 90))
	{
		grade = 'B';
	}
	else if ((percentage >= 70) && (percentage < 80))
	{
		grade = 'C';
	}
	else if ((percentage >= 60) && (percentage < 70))
	{
		grade = 'D';
	}
	else if ((percentage >= 40) && (percentage < 60))
	{
		grade = 'E';
	}
	else
	{
		grade = 'F';
	}

	switch (grade)
	{
	case 'A':
		cout << "Your grade is A" << endl;
		break;
	case 'B':
		cout << "Your grade is B" << endl;
		break;
	case 'C':
		cout << "Your grade is C" << endl;
		break;
	case 'D':
		cout << "Your grade is D" << endl;
		break;
	case 'E':
		cout << "Your grade is E" << endl;
		break;
	case 'F':
		cout << "Your grade is F" << endl;
		break;
	}

	
}
	
	
	
	
	

