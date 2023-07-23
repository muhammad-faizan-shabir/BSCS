#include<iostream>
#include<string>
using namespace std;

class String
{
	string s;
	int length;
public:

	void SetString(string temp)
	{
		s = temp;
		length = s.length();
	}
	friend bool operator==(String s1,String s2)
	{
		int val1 = 0;
		int val2 = 0;
		for (int i = 0; i < s1.length; i++)
		{
			val1 = val1 + s1.s[i];
		}

		for (int i = 0; i < s2.length; i++)
		{
			val2 = val2 + s2.s[i];
		}

		if (val1 == val2)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
};

int main()
{
	String obj1;
	String obj2;

	string temp;
	



	cout << "Enter string 1: ";
	getline(cin,temp);
	obj1.SetString(temp);

	cout << "Enter string 2: ";
	getline(cin, temp);
	obj2.SetString(temp);


	if (obj1== obj2)
	{
		cout<<endl << "Strings are equal" << endl;
	}
	else
	{
		cout<<endl << "Strings are NOT equal" << endl;
	}

	cout << endl;


	system("pause");
}