#include <iostream>
#include <cmath>
using namespace std;
void ITOA(int a,char arr[]) // will only work for integers greater than 0
{
	int end = 0;
	int i;
	int tempnum;
	int k;
	int j=0;
	if (a < 0)
	{
		a = a * -1;
		arr[0] = '-';
		j++;
		end = 1;
	}
	if(a==0)
	{
		arr[0] = '0';
		arr[1] = '\0';
		return;
	}
	tempnum = a;
	for(i=1;tempnum>0;i++)
	{
		tempnum = tempnum / 10;
	}
	j = j+i - 1;
	for(k = j - 1; k >= end;(k--),(a=a/10))
	{
		arr[k] = (a % 10) + 48;
	}
	arr[j] = '\0';
}
int main()
{
	char arr[10];
	int a = -111;
	ITOA(a,arr);
	cout << arr;
}