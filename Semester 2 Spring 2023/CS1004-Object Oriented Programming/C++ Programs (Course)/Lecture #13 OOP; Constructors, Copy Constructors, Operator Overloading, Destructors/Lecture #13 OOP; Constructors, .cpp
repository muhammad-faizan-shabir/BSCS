#include <iostream>
using namespace std;

class A
{
	int a;
public:
	A(int n=3)
	{
		a = n;
		cout << "Parameterized Constructor" << endl;
	}

	A(const A&obj)
	{
		cout << "Copy Constructor" << endl;
	}

	int getA()
	{
		return a;
	}

	void operator=(const A&obj)
	{
		cout << "Overloaded Assignment Operator" << endl;
	}

	A myFunc(A obj)
	{
		A ans;
		ans.a = obj.a;
		return ans;
	}
	
	void SetA(int);

	~A()
	{
		cout << "Destructor" << endl;
	}
};

void A::SetA(int a)
{
	(*this).a = a;
	// or this->a=a;
}

int main()
{
	A obj1, obj2 = obj1;
	
	A obj3;
	
	obj3 = obj2.myFunc(obj1);
}

