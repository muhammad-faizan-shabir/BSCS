#include <iostream>
using namespace std;
int main()
{
	char arr[4];
	_itoa_s(200, arr,10);
	cout << arr;
}