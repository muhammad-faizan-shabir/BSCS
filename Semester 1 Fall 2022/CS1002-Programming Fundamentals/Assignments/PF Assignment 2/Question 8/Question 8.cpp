#include <iostream>
using namespace std;
int main()
{
	int age1;
	int age2;
	int age3;
	
	cout << "Enter age of first person: " << endl;
    cin >> age1;
	
	cout << "Enter age of second person: " << endl;
	cin >> age2;

	cout << "Enter age of third person: " << endl;
	cin >> age3;

	if((age1>age2)&&(age1>age3))
	{
		cout << "First person is the oldest" << endl;
	}
	if ((age2 > age3) && (age2 > age1))
	{
		cout << "Second person is the oldest" << endl;
	}
	if ((age3 > age2) && (age3 > age1))
	{
		cout << "Third person is the oldest" << endl;
	}

	
	if ((age1 < age2) && (age1 < age3))
	{
		cout << "First person is the youngest" << endl;
	}
	if ((age2 < age3) && (age2 < age1))
	{
		cout << "Second person is the youngest" << endl;
	}
	if ((age3 < age2) && (age3 < age1))
	{
		cout << "Third person is the youngest" << endl;
	}
}