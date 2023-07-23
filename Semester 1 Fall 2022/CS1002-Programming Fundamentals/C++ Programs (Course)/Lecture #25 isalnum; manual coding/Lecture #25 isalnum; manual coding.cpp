#include <iostream>
using namespace std;

int IsAlnum(char a)
{
	if((a>='a') && (a<='z'))
	{
		return 1;
	}
	else if((a>='A') && (a<='Z'))
	{
		return 1;
	}
	else if((a>='0') && (a<='9'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char s = 'O';
	cout << IsAlnum(s);
}