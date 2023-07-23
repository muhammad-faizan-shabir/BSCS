#include <iostream>
using namespace std;

class complex
{
	int real;
	int imaginary;
public:
	complex(int r = 0, int i = 0)
	{
		real = r;
		imaginary = i;
	}

	complex(const complex&obj)
	{
		real = obj.real;
		imaginary = obj.imaginary;
	}


	~complex()
	{
	}

	complex operator+(const complex&obj)
	{
		complex a;
		a.real = real + obj.real;
		a.imaginary = imaginary + obj.imaginary;

		return a;
	}

	complex operator-(const complex&obj)
	{
		complex a;
		a.real = real - obj.real;
		a.imaginary = imaginary - obj.imaginary;

		return a;
	}


	friend ostream&operator<<(ostream &strm,const complex&obj)
	{
		strm << obj.real << " + " << obj.imaginary << "i";
		cout << endl;
		return strm;
	}

	friend istream &operator>>(istream &strm, complex&obj)
	{
		cout << "Enter the real part: ";
		strm >> obj.real;
		cout << "Enter the imaginary part: ";
		strm >> obj.imaginary;
		return strm;
	}


	bool operator==(const complex&obj)
	{
		if ((real == obj.real) && (imaginary == obj.imaginary))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const complex&obj)
	{
		if ((real != obj.real) || (imaginary != obj.imaginary))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void operator=(const complex&obj)
	{
		real = obj.real;
		imaginary = obj.imaginary;
	}
};


int main()
{
	complex C1;
	complex C2(5, 6);

	complex C3;

	cout << "Input a complex number" << endl;
	cin >> C3;

	cout << C1 << C2 << C3;

	if (C1 == C2)
	{
		cout << "C1 ==  C2" << endl;
	}
	else
	{
		cout << "C1 !=  C2" << endl;
	}

	if (C1 != C3)
	{
		cout << "C1 != C3" << endl;
	}
	else
	{
		cout << "C1 == C3" << endl;
	}

	complex C4 = C2 - C3;

	cout << C4;

	system("pause");
	return 0;


}