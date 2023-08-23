#include <iostream>
using namespace std;
float ATOF(char a[])
{
	float num = 0;
	bool flag = false;
	float j=10;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='.')
		{
			flag = true;
			continue;
		}
		if(flag==true)
		{
			num = num + ((a[i] - 48) / (float)(j));
			j=j*10;
		}
		else
		{
			num = (num * 10) + (a[i] - 48);
		}
		
	}
	return num;
}
int main()
{
	char s[] = "325.576";
	cout << ATOF(s) + 1.0;
}