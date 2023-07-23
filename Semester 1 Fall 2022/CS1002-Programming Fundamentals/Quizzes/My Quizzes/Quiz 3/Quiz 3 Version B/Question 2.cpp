#include <iostream>
using namespace std;
int main()
{
	int n = 3, i = 1, sum = 0;
	int t = 1;

	while(i<=n)
	{
		cout << t << " ";
		if(i<n)
		{
			cout << "+ " ;
		}
		sum = sum + t;
		t = (t * 10) + 1;
		i++;
	}
	cout << "The sum of the series is: " << sum << endl;
}