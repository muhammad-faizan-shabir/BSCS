#include <iostream>
using namespace std;
int main()
{
	char stc[100];
	char stc2[100];
	cout << "Enter the sentence: " << endl;
	cin.getline(stc, 100);
	int index = 0;
	stc2[index] = stc[0];
	index++;
	for(int i=1;stc[i]!='\0';i++)
	{
		if((stc[i]>='a')&&(stc[i]<='z'))
		{
			stc2[index] = stc[i];
			index++;
		}
		else if ((stc[i] >= 'A') && (stc[i] <= 'Z'))
		{
			stc2[index] = ' ';
			index++;
			stc2[index] = stc[i] + 32;
			index++;
		}
		else
		{
			stc2[index] = stc[i];
			index++;
		}
	}

	stc2[index] = '\0';
	cout << endl;
	cout << stc2;

}
