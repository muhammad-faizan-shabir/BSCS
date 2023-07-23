#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float sum = 0;
	int n;
	int x = 1; // for loop 
	float temp = 0;

	cout << "Input the value for the nth term" << endl;
	cin >> n;

	while (x<=n)
	{
		temp =  (1 / (pow(x, x)));
		cout << "1/" << x << "^" << x << "=" << temp<<endl;
		sum = sum + temp;
		x = x + 1;
	}
	cout << "The sum of the series is: " << sum << endl;

}