#include<iostream>
#include<string>
using namespace std;


void grow(char** &arr, int size)
{
	char**temp = new char*[size + 1];

	for (int i= 0; i < size; i++)
	{
		temp[i] = arr[i];
	}

	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;

	arr = temp;
}

void putWord(char**arr, char*word, int index)
{
	char* temp = new char[strlen(word)+1];

	strcpy(temp, word);

	arr[index] = temp;
}

bool alreadyIn(char**arr, char*word, int size)
{
	bool flag = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i], word) == 0)
		{
			flag = 1;
		}
	}
	return flag;
}

void createIndex(char**tweets, int n,char **&keyWords,int &size,int**&IDs)
{
	for (int i = 0; i < n; i++)
	{
		char word[100];
		int x = -1;
		for (int j = 0; tweets[i][j] != '\0'; j++)
		{
			if (tweets[i][j] != ' ')
			{
				word[++x] = tweets[i][j];
			}
			else
			{
				x = -1;
				if (alreadyIn(keyWords, word, size) == 0)
				{
					grow(keyWords, size);
					size++;
					putWord(keyWords, word, size - 1);
				}

			}
		}
	}

	IDs = new int*[size];


	for (int i = 0; i < size; i++)
	{
		int tempsizeId = 0;
		for (int j = 0; j < n; j++)
		{
			char word[100];
			int x = -1;
			for (int k = 0; tweets[j][k] != '\0';k++)
			{
				if (tweets[i][j] != ' ')
				{
					word[++x] = tweets[i][j];
				}
				else
				{
					x = -1;
					if (strcmp(keyWords[i], word) == 0)
					{
						int *temp = new int[++tempsizeId];
						for (int l = 0; l < tempsizeId - 1; l++)
						{
							temp[i] = IDs[i][l];
						}
						delete[] IDs[i];
						IDs[i] = temp;
						IDs[i][tempsizeId - 1] = j;
					}
				}

			}
		}
		int *temp = new int[++tempsizeId];
		for (int l = 0; l < tempsizeId - 1; l++)
		{
			temp[i] = IDs[i][l];
		}
		delete[] IDs[i];
		IDs[i] = temp;
		IDs[i][tempsizeId - 1] = -1;

	}
}
int main()
{
	char a[10] = "kkg";
	char b[20] = "kkg";
	cout << strlen(a) << endl;
	cout << endl;
	system("pause");
}