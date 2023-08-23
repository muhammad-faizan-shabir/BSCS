#include <iostream>
using namespace std;

class A
{
	int num;
public:
	A(int n=5)
	{
		num = n;
		cout << n << endl;
	}
	
	void SetValue(int val);
};

void A::SetValue(int val)
{
	num = val;
}

int main()
{
	A obj1, obj2(10);
}