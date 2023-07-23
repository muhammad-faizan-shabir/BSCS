#include <iostream>
using namespace std;
void tok(char str1[],char newString[][100],int &ctr)
{
	int i, j;
	j = 0;
	ctr = 0;
	for(i=0;i<(strlen(str1));i++)
	{
		if((str1[i]==' ')||(str1[i]=='\0'))
		{
			newString[ctr][j] = '\0';
			ctr++;
			j = 0;
		}
		else
		{
			newString[ctr][j] = str1[i];
			j++;
		}
	}
	newString[ctr][j] = '\0';
}
int main()
{
	char str1[100];
	char newString[100][100];
	int ctr;
	cout << "Input String" << endl;
	cin.getline(str1, 100);
	tok(str1, newString, ctr);
	cout << endl;
	cout << "Tokenized verson: " << endl;
	for(int i=0;i<=ctr;i++)
	{
		cout << newString[i] << endl;
	}
}