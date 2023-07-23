#include <iostream>
using namespace std;
int main()
{
	char s[] = "cbc";
	char k[] = "cbc";

	cout<<strcmp(s, k);// returns 0 if s and k are same
	// returns -1 if k>s alphabetically
	// returns 1 if s>k alphabetically
}