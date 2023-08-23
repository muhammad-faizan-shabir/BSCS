#include <iostream>
using namespace std;
void StrnCat(char a[], char b[],int n)
{
	int i;
	int j;
	for (i = 0; a[i] != '\0'; i++)
	{
	}

	for (j = 0; (b[j] != '\0')&&(j<n); j++)
	{
		a[i] = b[j];
		i++;
	}
}
int main()
{
	char s[] = "Fast-Nuces";
	char k[100] = "Lahore";

	StrnCat(k, s,7);
	cout << k;
}
