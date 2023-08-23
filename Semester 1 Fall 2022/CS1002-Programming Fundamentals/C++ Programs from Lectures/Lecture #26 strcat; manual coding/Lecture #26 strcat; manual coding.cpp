#include <iostream>
using namespace std;
void StrCat(char a[],char b[])
{
	int i;
	int j;
	for(i=0;a[i]!='\0';i++)
	{
	}

	for(j=0;b[j]!='\0';j++)
	{
		a[i] = b[j];
		i++;
	}
}
int main()
{
	char s[] = "Fast-Nuces";
	char k[100] = "Lahore";

	StrCat(k, s);
	cout << k;
}
