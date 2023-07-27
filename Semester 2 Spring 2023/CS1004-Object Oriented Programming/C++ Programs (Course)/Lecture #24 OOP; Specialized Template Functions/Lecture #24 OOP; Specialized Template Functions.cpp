#include<iostream>
using namespace std;

template<class T>
void func(T a)
{
	cout << "Template Function" << endl;
}

template<>
void func<char>(char a)
{
	cout << "Specialized Template Function" << endl;
}

int main()
{
	func(5); // call goes to template function
	func(7.6); // call goes to template function
	func<int>(6); // call goes to template function
	func('A'); // call goes to specialized template function
	func<char>('B'); // // call goes to specialized template function
	
	cout << endl;
	system("pause");
	return 0;
}