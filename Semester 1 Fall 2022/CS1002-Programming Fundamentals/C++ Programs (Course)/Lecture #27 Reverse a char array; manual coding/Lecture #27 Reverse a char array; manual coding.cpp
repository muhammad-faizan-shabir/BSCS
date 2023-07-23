#include <iostream>
using namespace std;
int Length(char a[])
{
	int i = 0;
	int count = 0;
	for(;a[i]!='\0';i++)
	{
		count++;
	}
	return count;
}

void reverse(char a[])
{
	int length = Length(a);
	int i;
	int start = 0;
	int end = length - 1;
	char temp;
	for(i=0;end>start;++start,--end)
	{
		temp = a[end];
		a[end] = a[start];
		a[start] = temp;
	}
}

int main()
{
	char a[] = "FASTNUO";
	reverse(a);

	cout << a;
}