#include<iostream>
using namespace std;

class grandparent
{
public:
	grandparent(int x)
	{
		cout << x;
		cout << "Constructor grandparent" << endl;
	}

	grandparent()
	{
		cout << "Constructor grandparent default" << endl;
	}
	~grandparent()
	{
		cout << "Destructor grandparent" << endl;
	}

	virtual void forp()
	{
		cout << "grandparent " << endl;
	}

	virtual void forc()
	{
		cout << "grandparent" << endl;
	}
};

class parent:  virtual public grandparent
{
public:
	parent() :grandparent(0)
	{
		cout << "Constructor parent" << endl;
	}
	~parent()
	{
		cout << "Destructor parent" << endl;
	}

	void forp()
	{
		cout << "parent ";
	}
};

class child:  virtual  public grandparent
{
public:
	child() :grandparent(5)
	{
		cout << "Constructor child" << endl;
	}
	~child()
	{
		cout << "Destructor child" << endl;
	}

	void forc()
	{
		cout << "child " << endl;
	}

};

class grandchild : public parent,public child
{
public:
	grandchild()
	{
		cout << "constructor grandchild" << endl;
	}

	~grandchild()
	{
		cout << "Destructor grandchild" << endl;
	}
};

int main()
{
	{
		grandchild obj;
		obj.forc();
	}
	cout << endl;
	system("pause");
}