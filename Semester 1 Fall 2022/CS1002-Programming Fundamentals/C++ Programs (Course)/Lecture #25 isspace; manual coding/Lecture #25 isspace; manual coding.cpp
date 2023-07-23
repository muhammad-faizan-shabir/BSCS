#include <iostream>
using namespace std;
int IsSpace(char a)
{
	if(a==' ')
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
	char s = ' ';
	cout << IsSpace(s);
}