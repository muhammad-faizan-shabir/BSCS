#include <iostream>
using namespace std;
int StrCmp(char a[],char b[])
{
	int suma = 0;
	int sumb = 0;

	for(int i=0;a[i]!='\0';i++)
	{
		suma = suma + a[i];
	}
	
	for (int i = 0; b[i] != '\0'; i++)
	{
		sumb = sumb + b[i];
	}
	
	if(suma>sumb)
	{
		return 1;
	}
	else if(suma<sumb)
	{
		return -1;
	}
	else if(suma=sumb)
	{
		return 0;
	}

}
int main()
{
	char s[] = "abc";
	char k[] = "abc";

	cout << StrCmp(s, k);
}