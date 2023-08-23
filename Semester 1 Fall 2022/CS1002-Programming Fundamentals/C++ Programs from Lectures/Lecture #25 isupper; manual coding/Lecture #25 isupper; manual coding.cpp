#include <iostream>
using namespace std;
int IsUpper(char a)
{
	if((a>='A') && (a<='Z'))
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
	char s = 'F';
	cout << IsUpper(s);
}