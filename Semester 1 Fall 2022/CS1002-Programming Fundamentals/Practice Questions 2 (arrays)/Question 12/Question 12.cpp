#include <iostream>
using namespace std;
int main()
{
	int ar[6] = {0,1,0,1,1,0}; // array to store ones and zeros
	int max_index = 5; 
	int n;
	n = max_index - 1;

	bool flag = false;
	int temp;
	cout << "The original array: " << endl;
	for(int i=0;i<=max_index;i++) // outputting original array
	{
		cout << ar[i] << " ";
	}
	cout << endl;
	while(flag == false) // sorting the array to segregate ones and zeros
	{
		flag = true;

		for(int i =0;i<=n;i++)
		{
			if ((ar[i] == 1) && (ar[i + 1] == 0))
			{
				flag = false;
				temp = ar[i];
				ar[i] = ar[i + 1];
				ar[i + 1] = temp;

			}
			
		}
		n--;
	}

	cout << "segregated array is: " << endl;
	for (int i = 0; i <= max_index; i++) // outputing the segregated array 
	{
		cout << ar[i] << " ";
	}



}