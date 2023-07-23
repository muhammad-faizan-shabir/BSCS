#include <iostream>
using namespace std;
int ToUpper(char a)
{
	if((a>='A')&&(a<='Z'))
	{
		return a;
	}
	else
	{
		a = a - 32;
		return a;
	}
}
int main()
{
	char s = 'y';
	cout << (char)ToUpper(s);
}