#include<iostream>
#include<string>
using namespace std;

class tornadoException
{
	string message;
public:
	tornadoException()
	{
		message = "Tornado: Take cover immediately!";
	}

	tornadoException(int m)
	{
		message = "Tornado: " + to_string(m) + " miles away; and approaching!";
	}

	string what()
	{
		return message;
	}
};

int main()
{
	cout << "Exception thrown with the DEFAULT constructor:" << endl;
	try
	{
		throw tornadoException();
	}
	catch (tornadoException obj)
	{
		cout<<obj.what()<<endl;
	}
	
	cout << endl;
	cout << "Exception thrown with the PARAMETERIZED constructor:" << endl;
	try
	{
		throw tornadoException(10);
	}
	catch (tornadoException obj)
	{
		cout<<obj.what() << endl;
	}

	cout << endl;
	system("pause");
}