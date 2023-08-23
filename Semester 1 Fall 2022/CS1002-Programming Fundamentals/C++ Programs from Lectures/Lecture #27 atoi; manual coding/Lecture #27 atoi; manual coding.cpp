#include <iostream>
using namespace std;
int ATOI(char a[])
{
	int num = 0;
	for(int i=0;a[i]!='\0';i++)
	{
		num = (num * 10) + (a[i]-48);
	}
	return num;
}
int main()
{
	char s[] = "33";
	cout << ATOI(s) + 1;
}