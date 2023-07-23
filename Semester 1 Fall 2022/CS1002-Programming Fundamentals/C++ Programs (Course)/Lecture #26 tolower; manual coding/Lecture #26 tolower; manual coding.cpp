#include <iostream>
using namespace std;
int ToLower(char a)
{
	if((a>='a') && (a<='z'))
	{
		return a;
	}
	else
	{
		a = a + 32;
		return a;
	}
}
int main() 
{
	char s = 'T';
	cout << (char)ToLower(s);
}