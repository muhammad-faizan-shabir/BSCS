#include <iostream>
using namespace std;

int IsDigit(char a)
{
	if((a>='0') && (a<='9'))
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
	char a = '/';
	cout << IsDigit(a);
}
