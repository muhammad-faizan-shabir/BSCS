#include <iostream>
using namespace std;
int ATOL(char a[])
{
	long int num = 0;
	for (int i = 0; a[i] != '\0'; i++)
	{
		num = (num * 10) + (long int)(a[i] - 48);
	}
	return num;
}
int main()
{
	char s[] = "34";
	cout << ATOL(s) + 1;
}