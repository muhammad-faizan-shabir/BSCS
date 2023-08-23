#include <iostream>
using namespace std;
int main()
{
	char s[] = "Fast-Nuces";
	char k[140];

	strncpy_s(k,s,3);
	cout << k;
}