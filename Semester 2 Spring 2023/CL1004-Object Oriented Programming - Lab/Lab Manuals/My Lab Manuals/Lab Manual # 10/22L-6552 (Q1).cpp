#include <iostream>
using namespace std;

class Faculty
{
public:
	virtual void print() = 0;
};

class Administrator : public virtual  Faculty
{
public:
	void print()
	{
		cout << "Class Administrator" << endl;
	}
};

class Teacher : public virtual Faculty
{
public:
	void print()
	{
		cout << "Class Teacher" << endl;
	}
};

class AdministratorTeacher : public Administrator, public Teacher 
{
public:
	void print()
	{
		cout << "Class AdministratorTeacher" << endl;
	}
};

int main()
{
	Faculty* arr[3];
	
	Administrator obj1;
	Teacher obj2;
	AdministratorTeacher obj3;

	arr[0] = &obj1;
	arr[1] = &obj2;
	arr[2] = &obj3;

	for (int i = 0; i < 3; i++)
	{
		arr[i]->print();
	}

	cout << endl;
	system("pause");
}

