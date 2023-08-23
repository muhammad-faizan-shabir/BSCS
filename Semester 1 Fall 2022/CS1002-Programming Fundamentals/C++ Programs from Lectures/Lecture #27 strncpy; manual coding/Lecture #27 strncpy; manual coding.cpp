#include <iostream>
using namespace std;
void StrnCpy(char a[], char b[], int n)
{
	int i;
	for (i = 0; (b[i] != '\0')&&(i<n); i++)
	{
		a[i] = b[i];
	}
	a[i] = '\0';
}
int main()
{
	char s[] = "Fast-Nuces";
	char k[140];

	StrnCpy(k, s,4);
	cout << k;
}