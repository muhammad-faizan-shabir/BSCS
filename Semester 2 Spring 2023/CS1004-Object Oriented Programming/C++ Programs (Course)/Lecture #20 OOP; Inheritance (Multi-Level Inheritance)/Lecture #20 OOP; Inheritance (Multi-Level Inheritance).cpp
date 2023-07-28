#include<iostream>
using namespace std;

class Extra
{
public:
	Extra(int n = 0)
	{
		cout << "Constructor Extra " <<n<< endl;
	}

	~Extra()
	{
		cout << "Destructor Extra" << endl;
	}
};

class A
{
	int x;
protected:
	int y;
public:
	int z;

	A(int n = 3) :x(1), y(2), z(3)
	{
		cout << "Constructor A" << endl;
	}
	// any other function(s)

	~A()
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
	int b;
public:
	B() :A(7)
	{
		cout << "Constructor B" << endl;
	}

	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C :public B
{
	Extra e =8;// value 8 has less priority than l
public:
	C(int l = 3) :e(l)
	{
		cout << "Constructor C" << endl;
	}

	~C()
	{
		cout << "Destructor C" << endl;
	}
};

int main()
{
	{
		C obj(6);
	}
	cout << endl;
	system("pause");
}