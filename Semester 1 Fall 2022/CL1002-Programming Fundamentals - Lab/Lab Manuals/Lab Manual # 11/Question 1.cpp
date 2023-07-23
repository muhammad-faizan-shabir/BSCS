#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;
void upper(char ar[])
{
	for(int i=0;ar[i]!='\0';i++)// loop will run until back slash zero comes in the array
	{
		if((ar[i]!=' ')&&((ar[i]>='a')&&(ar[i]<='z'))) // checking for space character and also if the letter is already lower case
		{
			ar[i] = ar[i] - 32;// converting to lowercase by -32
		}

	}
}
int main()
{
	char ar[100];

	cout << "Enter a sentence in lower case: ";
	cin.getline(ar, 100); // inputing sentence in lower case

	upper(ar); // calling the function

	cout<<endl << "The sentence in upper case is: ";
	cout << ar << endl << endl; // outputing the sentence in uppercase
}