#include <iostream>
using namespace std;
int main()
{
	int size;
	cout << "Enter size for 1D array: ";
	cin >> size;
	int* ptr = new int[size];

	delete[]ptr;
	ptr = 0;
}