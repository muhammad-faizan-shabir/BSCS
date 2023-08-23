//a program to print word Pakistan n times
#include <iostream>
using namespace std;
int main()
{
	int  n;
	cout << "Enter the number of times you want to print the word Pakistan" << endl;
	cin >> n;

	if(n<=0)
	{
		cout << "Enter valid input" << endl;
	}
	else
	{
		int i = 1;
		while(i<=n)
		{
			cout << i << ".Pakistan" << endl;
			i++;
		}
	}
}