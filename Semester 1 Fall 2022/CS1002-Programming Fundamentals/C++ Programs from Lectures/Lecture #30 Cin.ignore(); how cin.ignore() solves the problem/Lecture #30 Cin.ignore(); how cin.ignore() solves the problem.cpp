#include <iostream>
using namespace std;
int main()
{
	char s[15];
	char k[100];

	cin >> s;// this line works
	cin.ignore();
	cin.getline(k, 100);// this line gets ignored if cin.ignore() is not used
}