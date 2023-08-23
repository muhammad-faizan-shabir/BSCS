#include <iostream>
using namespace std;
int StrLen(char a[])
{
	int count = 0;
	for(int i=0;a[i]!='\0';i++)
	{
		count++;
	}
	return count;
}
int main()
{
	char a[] = "abcdefgh";
	cout<<StrLen(a);
}