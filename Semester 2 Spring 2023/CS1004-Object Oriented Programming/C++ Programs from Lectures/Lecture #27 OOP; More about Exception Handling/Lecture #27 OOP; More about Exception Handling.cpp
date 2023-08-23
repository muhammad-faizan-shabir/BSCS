#include<iostream>
using namespace std;

class A
{
	int a;
public:
	//Exception class
	class Negative
	{
		int e;
	public:
		Negative(int v)
		{
			e = v;
		}
		int getNum()
		{
			return e;
		}
	}; // end of exception class

	void set(int n)
	{
		if (n<0)
		{
			throw Negative(n);
		}
		a = n;
	}
};// end of class A

int main()
{
	A obj; 
	
	cout << "First try: " << endl;
	try
	{
		obj.set(1);
		cout << "Try successful" << endl;
	}
	catch (A::Negative n1)
	{
		cout << n1.getNum() << endl;
	}
	
	cout << endl << "Second try:" << endl;
	try
	{
		obj.set(-1);
		cout << "Try successful" << endl;
	}
	catch (A::Negative n1)
	{
		cout << n1.getNum() << endl;
	}
	
	cout << "Okay" << endl;
	cout << endl;
	system("pause");
	return 0;
}
