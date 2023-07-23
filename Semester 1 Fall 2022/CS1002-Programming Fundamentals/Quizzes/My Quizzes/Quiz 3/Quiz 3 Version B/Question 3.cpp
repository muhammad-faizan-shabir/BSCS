#include <iostream>
using namespace std;
int main()
{
	int n = 5;
	int k = 5;
	n = (100 % k ? k + 1 : k - 1);
	cout << "n = " << n << " k = " << k << endl;

}