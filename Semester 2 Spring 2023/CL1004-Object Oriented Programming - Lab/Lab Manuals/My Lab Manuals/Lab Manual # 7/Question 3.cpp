#include<iostream>
using namespace std;

#include <iostream>
using namespace std;
class A;
class B;
class C;

class A
{
	int number1;
	
	friend class C;
public:
	
	A(int num = 0)
	{
		number1 = num;
	}

	void setnumber1(int num)
	{
		number1 = num;
	}


};

class B
{
	int number2;
public:
	B(int num = 0)
	{
		number2 = num;
	}

	void setnumber2(int num)
	{
		number2 = num;
	}
};


class C
{
	int number3;
public:
	C(int num = 0)
	{
		number3 = 0;
	}
	
	void setnumber3(int num)
	{
		number3 = num;
	}

	int ADD(A obj1)
	{
		return(number3 + obj1.number1);
	}
};

int main()
{
	A obj1;
	C obj2;
	int temp;

	cout << "Enter number 1: ";
	cin >> temp;
	obj1.setnumber1(temp);

	cout << "Enter number 2: ";
	cin >> temp;
	obj2.setnumber3(temp);

	cout << endl;
	cout << "The sum is: ";

	cout << obj2.ADD(obj1);

	cout << endl << endl;
	system("pause");


}

