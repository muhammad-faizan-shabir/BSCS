#include <iostream>
#include <string>
using namespace std;
int main()
{
	char s[15];
	string k;
	
	cin >> s;// this line works
	cin.ignore();
	getline(cin, k);// this line gets ignored if cin.ignore() is not used
}