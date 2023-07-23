#include <iostream>
using namespace std;
int main()
{
	char s[] = "Fast-Nuces";
	char k[100] = "Pak";
	strcat_s(k, s);
	cout << k;
}