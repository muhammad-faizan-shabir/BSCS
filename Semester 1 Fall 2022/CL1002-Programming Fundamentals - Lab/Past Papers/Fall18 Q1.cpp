#include <iostream>
using namespace std;
int main()
{
	int sum = 0;
	char arr[100];
	cout << "Enter number in character array to get sum of its digits: ";
	cin.getline(arr, 100);

	for(int i=0;arr[i]!='\0';i++)
	{
		sum = sum + (arr[i] - 48);
	}
	cout << "Sum: " << sum;
}