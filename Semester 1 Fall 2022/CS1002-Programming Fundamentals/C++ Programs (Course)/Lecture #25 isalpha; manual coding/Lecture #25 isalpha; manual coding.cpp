#include <iostream>
using namespace std;
int IsAlpha(char a)
{
	if((a>='a')&&(a<='z'))
	{
		return 1;
	}
	else if((a>='A') && (a<='Z'))
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
	char a='f';
	cout << IsAlpha(a);
}