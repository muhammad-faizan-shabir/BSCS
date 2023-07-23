#include <iostream>
using namespace std;
void StrCpy(char a[],char b[])
{
	int i;
	for(i =0;b[i]!='\0';i++)
	{
		a[i] = b[i];
	}
	a[i] = '\0';
}
int main()
{
	char s[] = "Fast-Nuces";
	char k[140];

	StrCpy(k, s);
	cout << k;
}
