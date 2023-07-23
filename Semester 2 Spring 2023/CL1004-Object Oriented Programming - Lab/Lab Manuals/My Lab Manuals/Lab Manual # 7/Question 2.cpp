#include <iostream>
using namespace std;
class A;
class B;
int sum(A obj1, B obj2);

class A
{
	int number1;
	friend int sum(A , B );
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
	friend int sum(A, B);
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

int sum(A obj1, B obj2)
{
	return(obj1.number1 + obj2.number2);
}

int main()
{
	A obj1;
	B obj2;
	int temp;

	cout << "Enter number 1: ";
	cin >> temp;
	obj1.setnumber1(temp);

	cout << "Enter number 2: ";
	cin >> temp;
	obj2.setnumber2(temp);

	cout << endl;
	cout << "The sum is: ";

	cout << sum(obj1, obj2);

	cout << endl << endl;
	system("pause");


}

