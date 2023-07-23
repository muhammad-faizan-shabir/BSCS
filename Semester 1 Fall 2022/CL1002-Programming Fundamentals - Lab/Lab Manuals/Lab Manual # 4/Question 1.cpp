#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
	char alphabet;
	
	cout << "Enter an alphabet: " << endl;
	cin >> alphabet;

	if (isalpha(alphabet))
	{
		cout << "The alphabet entered is a consonant" << endl;
		if ((alphabet == 'a') || (alphabet == 'A') || (alphabet == 'e') || (alphabet == 'E') || (alphabet == 'i') || (alphabet == 'I') || (alphabet == 'o') || (alphabet == 'O') || (alphabet == 'u') || (alphabet == 'U'))
		{
			cout << "The alphabet entered is also a vowel" << endl;
		}
	}
	else
	{
		cout << "The character entered is not an alphabet so it is neither a consonant nor a vowel " << endl;
	}
}