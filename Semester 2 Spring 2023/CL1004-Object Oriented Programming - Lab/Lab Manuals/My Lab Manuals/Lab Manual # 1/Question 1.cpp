#include <iostream>
using namespace std;
int main()
{
	int x = 3;
	int y = 4;

	int* p;
	int* q;

	p = &x;
	q = &y;

	cout << "Value of variable x: " << x << endl << endl;
	cout << "Value of pointer p: " << p << endl << endl;
	cout << "Value of *p: " << *p << endl << endl;
	cout << "Value of &p: " << &p << endl << endl;
	cout << "Value of &x: " << &x << endl << endl;

	cout << "Value of variable y: " << y << endl << endl;
	cout << "Value of pointer q: " << q << endl << endl;
	cout << "Value of *q: " << *q << endl << endl;
	cout << "Value of &q: " << &q << endl << endl;
	cout << "Value of &y: " << &y << endl << endl;

	system("pause");
}