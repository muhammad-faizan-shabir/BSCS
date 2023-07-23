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
	if (age1 > age2)
	{
		if (age1 > age3)
		{
			cout << "First person is oldest" << endl;
		}
		else
		{
			cout << "Third person is oldest" << endl;
		}
	}
	else if (age2 > age3)
	{
		cout << "Second person is oldest" << endl;
	}
	else
	{
		cout << "Third person is oldest" << endl;
	}

	if (age1 < age2)
	{
		if (age1 < age3)
		{
			cout << "First person is youngest" << endl;
		}
		else
		{
			cout << "Third person is youngest" << endl;
		}
	}
	else if (age2 < age3)
	{
		cout << "Second person is youngest" << endl;
	}
	else
	{
		cout << "Third person is youngest" << endl;
	}
}
