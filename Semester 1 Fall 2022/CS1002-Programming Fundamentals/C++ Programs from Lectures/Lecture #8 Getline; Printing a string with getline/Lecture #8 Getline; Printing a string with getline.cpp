#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main()
{
	string x;
	cout << "Write a sentence: " << endl;
	getline(cin, x);
	cout << "Printing your sentence using getline: " << endl;
	cout << x;
}