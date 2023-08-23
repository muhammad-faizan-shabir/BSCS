#include<iostream>
using namespace std;

template<class T>
T calculate(T a)
{
	return a*a;
}

int main()
{
	cout << calculate(4)   << endl; // for integer
	cout << calculate(7.6) << endl; // for float/double

	cout << endl;
	system("pause");
	return 0;
}