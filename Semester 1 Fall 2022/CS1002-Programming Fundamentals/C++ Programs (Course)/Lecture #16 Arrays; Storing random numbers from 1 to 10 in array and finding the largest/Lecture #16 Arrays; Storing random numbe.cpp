#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int array[10];
	srand(time(0));
	int biggest;

	for(int i =0;i<10;i++)
	{
		array[i] = (rand() % 10) + 1;
	}
	cout << "Current situation of array is as below: " << endl;
	for(int i=0;i<10;i++)
	{
		cout << "index " << i << " : " << array[i] << endl;
	}

	biggest = array[0];

	for(int i=1;i<10;i++)
	{
		if(array[i]>biggest)
		{
			biggest = array[i];
		}
	}
	cout << endl;
	cout<< "Biggest number in the array is: " << biggest;


}