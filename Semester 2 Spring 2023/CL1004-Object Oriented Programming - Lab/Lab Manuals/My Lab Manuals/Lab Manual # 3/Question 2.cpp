#include <iostream>
using namespace std;

void myTokenizer(char* data, char** list_tokens,char delimiter,int strlen)
{
	int j = 0;
	int ctr = 0;
	for(int i=0;i<strlen;i++)
	{
		if((data[i]==delimiter)||(data[i]=='\0'))
		{
			list_tokens[ctr][j] = '\0';
			ctr++;
			j = 0;
		}
		else
		{
			list_tokens[ctr][j] = data[i];
			j++;
		}
	}
}

int main()
{
	int rows = 1;
	char delimiter;
	int size = 1;
	char* data = new char[size];
	int i = 0;
	char c='0';
	cout << "Enter a sentence: " << endl;
	while(c!='\n')
	{
		cin.get(c);
		if(c=='\n')
		{
			data[i] = '\0';
		}
		else
		{
			data[i] = c;
			i++;
			size++;
		}
	}

	cout << "Enter the delimeter: ";
	cin >> delimiter;
	
	for(int i=0;data[i]!='\0';i++)
	{
		if(data[i]==delimiter)
		{
			rows = rows + 1;
		}
	}

	char** list_tokens = new char* [rows];
	
	int strlen = 1;
	for(int i=0;data[i]!='\0';i++)
	{
		strlen++;
	}

	int temp = 0;
	int temprow = 0;
	for (int i = 0;i<strlen;i++)
	{
		if((data[i]!=delimiter)&&(data[i] != '\0'))
		{
			temp++;
		}
		else
		{
			list_tokens[temprow] = new char[temp + 1];
			temprow++;
			temp = 0;
		}
	}

	myTokenizer(data, list_tokens, delimiter,strlen);

	cout << "Tokens are: " << endl;
	for(int i=0;i<rows;i++)
	{
		cout << list_tokens[i] << endl;
	}

	for(int i=0;i<rows;i++)
	{
		delete [] list_tokens[i];
		list_tokens[i] = 0;
	}
	delete[] list_tokens;
	list_tokens = 0;
}