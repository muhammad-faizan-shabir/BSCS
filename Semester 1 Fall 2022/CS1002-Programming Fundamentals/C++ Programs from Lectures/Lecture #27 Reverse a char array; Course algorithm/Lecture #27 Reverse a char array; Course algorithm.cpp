#include <iostream>
using namespace std;
int length(char k[])
{
	int count=0;
	for(int i=0;k[i]!='\0';i++)
	{
		count++;
	}
	return count;
}
void reverse(char arr[])
{
	char temp;
	int len =length(arr);
	for (int i = 0; (arr[i] != '\0') && (len > i); i++)
	{
		temp = arr[i];
		arr[i] = arr[len - 1];
		arr[--len] = temp;
	}
}
int main()
{
	char arr[] = "abckh";
	reverse(arr);
	cout << arr;

}