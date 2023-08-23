#include <iostream>
using namespace std;
int IsLower(char a)
{
	if((a>='a') && (a<='z'))
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
	char s = 'h';
	cout << IsLower(s);
}