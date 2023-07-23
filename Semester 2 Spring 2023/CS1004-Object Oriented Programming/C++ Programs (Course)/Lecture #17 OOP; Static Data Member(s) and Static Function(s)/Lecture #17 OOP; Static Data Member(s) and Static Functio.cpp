#include<iostream>
using namespace std;

class A
{
	static int a;
public:
	A(int n = 3)
	{
		a = n;
	}

	// setter and getter for a
	void Seta(int n)
	{
		a = n;
	}

	int Geta()
	{
		return a;
	}

	static void display()
	{
		cout << a << endl;
	} // end of display
}; // end of class

int A::a;

int main()
{
	A obj1, obj2;
	
	obj1.Seta(10);
	
	cout << obj2.Geta() << endl;
	
	obj1.display();
	
	A::display();
	
	cout << endl;
	system("pause");
}