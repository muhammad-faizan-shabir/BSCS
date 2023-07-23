#include<iostream>
using namespace std;

template<class T,class U>
T GetMax(T a, U b)
{
	if (a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

template<class T,class U>
T GetMin(T a,U b)
{
	if (a>b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

template<class T>
T GetMax(T a, T b, T c)
{
	if ((a>b) && (a>c))
	{
		return a;
	}
	else if ((b>a) && (b>c))
	{
		return b;
	}
	else
	{
		return c;
	}
}

template<class T>
T GetMin(T a, T b, T c)
{
	if ((a<b) && (a<c))
	{
		return a;
	}
	else if ((b<a) && (b<c))
	{
		return b;
	}
	else
	{
		return c;
	}
}


int main()
{
	char i = 'Z';
	int j = 6, k;
	long l = 10, m = 5, n;
	k = GetMax(i, m);
	n = GetMin(j, l);
	cout <<k << endl;
	cout << n <<endl;

	cout << endl;
	system("pause");
}

