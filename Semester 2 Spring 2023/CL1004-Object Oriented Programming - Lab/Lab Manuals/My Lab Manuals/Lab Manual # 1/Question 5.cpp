#include <iostream>
using namespace std;
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	cout << "Array before bieng incremented: ";
	
	for(int i=0;i<10;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int* p;
	p = arr;

	for(int i=0;i<10;i++)
	{
		*(p + i) = *(p + i) + 3;
	}
	
	cout << "Array after  bieng incremented: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	system("pause");
}