// hollow square using for loop
#include <iostream>
using namespace std;
int main()
{
	int size;
	cout << "Enter size of hollow square" << endl;
	cin >> size;
	for(int i=1;i<=size;i++)
	{
		for(int j=1;j<=size;j++)
		{
			if((i==1) ||i==size)
			{
				cout << "* ";
			}
			else if(j==1||j==size)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}