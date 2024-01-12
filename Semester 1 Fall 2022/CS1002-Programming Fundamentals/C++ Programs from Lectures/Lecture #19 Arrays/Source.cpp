//a program to seperate even and odd numbers in an array.Put all even numbers first and then odd numbers
#include <iostream>
using namespace std;
int main()
{
	int arr[] = {0,1,3,4,5,6,7,8,10};
	int lptr = 0;
	int rptr = 8;
	int temp;
	cout << "array before: " << endl;
	for(int i=0;i<9;i++)
	{
		cout << arr[i] << " ";
	}

	while(lptr<=rptr)
	{
		if (((arr[lptr]%2) == 0) && ((arr[rptr] % 2) != 0))
		{
			++lptr;
			--rptr;
		}
		else if(((arr[lptr] % 2) == 0)&&((arr[rptr]%2) == 0))
		{
			++lptr;
		}
		else if (((arr[lptr] % 2) != 0) && ((arr[rptr]%2) == 0))
		{
			temp = arr[lptr];
			arr[lptr] = arr[rptr];
			arr[rptr] = temp;
			++lptr;
			--rptr;
		}
		else if (((arr[lptr] % 2) != 0) && ((arr[rptr]%2) != 0)) 
		{
			--rptr;
		}

	}

	cout << endl;
	cout << "Array after " << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}

}