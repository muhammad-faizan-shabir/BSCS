#include <iostream>
using namespace std;
int main()
{
	char s[100];
	cin.getline(s, 100,'y'); // will stop till 'y' and not include 'y'
	cout << s;
}