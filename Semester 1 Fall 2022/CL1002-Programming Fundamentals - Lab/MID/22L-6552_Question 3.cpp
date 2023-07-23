#include <iostream>
using namespace std;
int main()
{
	int arr[100];
	int n;
	int temp1=0;
	int temp2=1;
	int num;
	bool zagzig = true;
	bool zigzag = true;

	cout << "Enter the length of sequence n: ";
	cin >> n;

	cout << "Enter " << n << " numbers" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		arr[i] = num;
	}

	for (int j=1; j < n;j++)
	{
		if (!((arr[temp2] < arr[temp1]) && (arr[(temp2)+1] > arr[(temp1)+1])))
		{
			zigzag = false;
			break;
		}

		temp1 = temp1 + 2;
		temp2 = temp2 + 2;
	}

	for (int j = 1; j < n; j++)
	{
		if (!((arr[temp2] > arr[temp1]) && (arr[(temp2) + 1] < arr[(temp1) + 1])))
		{
			zagzig = false;
			break;
		}

		temp1 = temp1 + 2;
		temp2 = temp2 + 2;
	}

	if (zigzag == true)
	{
		cout << "It is a zigzag sequence" << endl;
	}
	else if (zagzig == true)
	{
		cout << "It is a zagzig sequence" << endl;
	}
	else
	{
		cout << "The sequence is niether " << endl;
	}

	

	

	
}