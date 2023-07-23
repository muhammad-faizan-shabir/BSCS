#include <iostream>
using namespace std;
bool equalsIgnoreCase(const char ar1[], int size1,const char ar2[],int size2)
{
	char temp1;
	char temp2;
	if(!(size1==size2))
	{
		return false;
	}
	else
	{
		for(int i=0;((ar1[i]!='\0')||(ar2[i]!='\0')); i++)
		{
			if((ar1[i]>='A')&&(ar1[i] <= 'Z'))
			{
				temp1 = ar1[i] + 32;
			}
			else
			{
				temp1 = ar1[i];
			}

			if ((ar2[i] >= 'A') && (ar2[i] <= 'Z'))
			{
				temp2 = ar2[i] + 32;
			}
			else
			{
				temp2 = ar2[i];
			}
			
			if (!(temp1 == temp2))
			{
				return false;
			}

		}
		return true;
	}
}
int main()
{
	char ar1[] = "AbC";
	char ar2[] = "aBc";
	cout << equalsIgnoreCase(ar1, 4, ar2, 4);
}