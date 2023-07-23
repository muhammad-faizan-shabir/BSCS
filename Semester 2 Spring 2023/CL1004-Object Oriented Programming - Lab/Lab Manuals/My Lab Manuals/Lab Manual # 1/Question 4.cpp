#include<iostream>
using namespace std;
int main()
{
	int a = 20;
	int* b;
	b = &a;

	cout << "Value of 'a' using 'b': " << *b << endl << endl;

	int** c;
	c = &b;

	cout << "Value of 'a' using 'c': " << **c << endl << endl;
	system("pause");
}