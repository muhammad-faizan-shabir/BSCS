#include <iostream>
using namespace std;
int main()
{
	char s[] = "Fast-Nuces";
	char k[100] = "Pak";

	strncat_s(k,s,6);
	cout << k;
}