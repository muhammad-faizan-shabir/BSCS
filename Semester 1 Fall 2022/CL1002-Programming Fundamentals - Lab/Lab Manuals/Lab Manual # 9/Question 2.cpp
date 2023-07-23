#include <iostream>
using namespace std;

void calculateGrade(int marks, char &grade)
{
	if((marks>80)&&(marks<=100))
	{
		grade = 'A';
	}
	if ((marks > 65) && (marks <=80))
	{
		grade = 'B';
	}
	if ((marks > 50) && (marks <= 65))
	{
		grade = 'C';
	}
	if(marks<=50)
	{
		grade = 'F';
	}
}

int main()
{
	

	int marks;
	char grade= ' ';

	do
	{
		cout << "Enter marks to get grade or enter -1 to exit: ";
		cin >> marks;
		if(marks ==-1)
		{
			cout <<endl<< "The program will exit" << endl;
			break;
		}
		calculateGrade(marks, grade);
		cout << endl << "The grade is: " << grade << endl;
	} while (true);
	
}