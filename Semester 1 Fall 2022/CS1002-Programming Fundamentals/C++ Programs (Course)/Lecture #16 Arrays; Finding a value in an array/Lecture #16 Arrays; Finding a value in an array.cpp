#include <iostream>
using namespace std;
int main()
{
	bool found = false;
	int num;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	for(int i =0;i<10;i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl << "what do you want to find: ";

	cin >> num;

	for(int i =0 ;i<10;i++)
	{
		if(num==arr[i])
		{
			found = true;
			break;
		}
	}

	if(found == true)
	{
		cout <<endl <<"Number is found";
	}
	else
	{
		cout << "Number is not found";
	}
}