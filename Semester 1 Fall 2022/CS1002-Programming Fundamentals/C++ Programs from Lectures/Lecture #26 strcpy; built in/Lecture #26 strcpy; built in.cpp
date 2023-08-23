#include <iostream>
using namespace std;
int main()
{
	char s[] = "Fast-Nuces";
	char k[140];

	strcpy_s(k, s);
	cout << k;
}