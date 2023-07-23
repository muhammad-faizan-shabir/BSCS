#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;
int search(char paragraph[],char substring[])
{
	int lengthOfSubstring = 0; // length of sub string
	int counter = 0; // counter
	int occurence = 0; // counts the number of occurences of the substring
	
	for(int i=0;substring[i]!='\0';i++) // calulating the length of substring
	{
		lengthOfSubstring++;
	}

	for(int i=0;paragraph[i]!='\0';i++) // checking each element of the paragraph
	{
		if((paragraph[i]==' ')||(counter==lengthOfSubstring-1)) // checking for spcace character and if counter exceeds the length of substring
		{
			counter = 0;
		}
		if(paragraph[i]==substring[counter]) // checking if the character matches the substring character
		{
			counter++;
		}
		if(counter==lengthOfSubstring-1) // checking if there is a match of the substring
		{
			occurence++;
		}
	}

	return occurence;
}
int main()
{
	char paragraph[300];
	char substring[50];
	int x;
	
	cout << "Enter the paragraph: ";
	cin.getline(paragraph, 300); // inputing the paragraph

	cout << endl;
	
	cout << "Enter the substring: ";
	cin.getline(substring, 50); // inputing the string
	 
	cout << endl;

	x = search(paragraph, substring); // calling the function

	cout << "The number of occurences of SubString are: " << x; // outputing the number of occurances

	cout << endl;
}