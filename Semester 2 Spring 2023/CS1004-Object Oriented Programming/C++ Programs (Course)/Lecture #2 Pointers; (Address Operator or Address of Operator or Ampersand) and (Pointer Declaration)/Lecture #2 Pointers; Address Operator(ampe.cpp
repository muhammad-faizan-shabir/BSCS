#include <iostream>
using namespace std;
void main()
{
	int a;
	a = 9;
	
	cout << "Size of variable 'a' (in bytes): ";
	cout << sizeof(a) << endl << endl; // returns answer in bytes

	cout << "Content of variable 'a': ";
	cout << a << endl << endl;

	//address of variable is allocated as soon as a variable is declared
	cout << "Adress of variale 'a'(in hexa-decimal): ";
	cout << &a << endl << endl; // '&' is called address operator/ampersand

	cout << "Scenario 1: What if I want to store content of  variable 'a' to another variable" << endl;
	int b = a;
	cout << "Content of variable 'b' that now stores the content of variable 'a': ";
	cout << b << endl << endl;

	// Pointer declaration
	cout << "Declaring a pointer that points to variable 'a'" << endl;
	int* pointer;
	pointer = &a;
	cout << "Value of pointer(that points to variable 'a'): ";
	cout << pointer << endl << endl;
}