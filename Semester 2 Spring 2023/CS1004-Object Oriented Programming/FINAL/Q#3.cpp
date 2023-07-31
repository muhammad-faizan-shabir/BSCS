#include<iostream>
using namespace std;

class package 
{
	string source;
	string destination;
	float weight;
public:
	package(string s, string d, float w) 
	{
		source = s;
		destination = d;
		weight = w;
	}
	virtual float comp_charges() {
		return 20 * weight;
	}
};

class TwoD_package : public package 
{
	float add_charges;
public:
	TwoD_package(string s, string d, float w, float a) :package(s, d, w) 
	{
		add_charges = a;
	}
	virtual float comp_charges()
	{
		return package::comp_charges() + add_charges;
	}
};

class Urgent_package :public package 
{
	float add_per;
public:
	Urgent_package(string s, string d, float w, float p) : package(s, d, w) 
	{
		add_per = p;
	}
	virtual float comp_charges() 
	{
		return package::comp_charges() * (1 + (add_per / 100));
	}
};

int main() 
{
	const int size = 5;
	package ** pkg = new package *[size];
	pkg[0] = new package("Lahore", "Karachi", 20 );
	pkg[1] = new TwoD_package("Lahore", "Islamabad", 35, 200);
	pkg[2] = new Urgent_package("Karachi", "Lahore", 25, 10);
	pkg[3] = new TwoD_package("Karachi", "Islamabad", 30, 250);
	pkg[4] = new Urgent_package("Karachi", "Peshawar", 40, 25);
	for (int i = 0; i < size; i++)
	{
		cout << "Package charges : " << pkg[i]->comp_charges();
		cout << endl;
		delete pkg[i];
	}
	delete[] pkg;
	cout << endl;
	system("pause");
	return 0;
}