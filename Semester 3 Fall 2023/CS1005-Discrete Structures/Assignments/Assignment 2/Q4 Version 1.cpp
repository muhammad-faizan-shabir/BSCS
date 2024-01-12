#include<iostream>
using namespace std;

class rationalNumber
{
	int p;
	int q;
public:
	rationalNumber(int p, int q)
	{
		this->p = p;
		this->q = q;
	}

	int getP()
	{
		return p;
	}
	int getQ()
	{
		return q;
	}

	void IncP()
	{
		p++;
	}
	void IncQ()
	{
		q++;
	}
	
	void DecP()
	{
		p--;
	}
	void DecQ()
	{
		q--;
	}
};

int gcd(int a, int b)
{
	// Find Minimum of a and b
	int result = min(a, b);
	while (result > 0) {
		if (a % result == 0 && b % result == 0) {
			break;
		}
		result--;
	}
	// Return gcd of a and b
	return result;
}

int main()
{
	int num = 1;
	int counter;
	for(counter=0;counter<1000;)
	{
		if(num%2!=0)
		{
			rationalNumber Obj(num, 1);
			do
			{
				if(gcd(Obj.getP(), Obj.getQ()) == 1)
				{
					counter++;
					cout<<counter<<":" << Obj.getP() << "/" << Obj.getQ() << endl;
				}
				Obj.DecP();
				Obj.IncQ();
	
			} while (Obj.getP()>0&&Obj.getQ()<num+1&&counter<1000);
			num++;
		}
		else
		{
			rationalNumber Obj(1, num);
			do
			{
				if (gcd(Obj.getP(), Obj.getQ()) == 1)
				{
					counter++;
					cout<<counter<<":" << Obj.getP() << "/" << Obj.getQ() << endl;
				}
				Obj.IncP();
				Obj.DecQ();
			} while (Obj.getP() < num + 1 && Obj.getQ() > 0&&counter<1000);
			num++;
		}
	}
	cout << counter << endl;
}