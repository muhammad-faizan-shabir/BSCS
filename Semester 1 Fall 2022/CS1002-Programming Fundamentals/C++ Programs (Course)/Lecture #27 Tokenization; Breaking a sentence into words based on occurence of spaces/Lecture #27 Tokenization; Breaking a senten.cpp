#include <iostream>
using namespace std;
void Tokenize(char a[])
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!=' ')
		{
			cout << a[i];
		}
		else
		{
			cout<<endl;
		}
	}
}

int main()
{
	char arr[100];
	cout << "Enter a sentence to tokenize it: " << endl;
	cin.getline(arr, 100);
	cout << endl;
	Tokenize(arr);
}