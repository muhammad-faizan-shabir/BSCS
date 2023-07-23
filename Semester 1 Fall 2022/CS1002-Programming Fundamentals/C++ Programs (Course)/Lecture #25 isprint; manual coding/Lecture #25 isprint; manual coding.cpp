#include <iostream>
using namespace std;
int IsPrint(char a) // non printable characters have ascii from 0 to 31
{
	if((a>=0)&&(a<=31))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	char a = '\n';
	cout << IsPrint(a);
}