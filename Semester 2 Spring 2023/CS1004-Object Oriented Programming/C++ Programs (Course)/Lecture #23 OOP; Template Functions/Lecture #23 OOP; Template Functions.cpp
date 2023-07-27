#include<iostream>
using namespace std;

template<class T>
T calculate(T a)
{
	return a*a;
}

int main()
{
	cout << calculate(4)   << endl;
	cout << calculate(7.6) << endl;
	cout << int(calculate('c')) << endl;

	cout << endl;
	system("pause");
	return 0;
}