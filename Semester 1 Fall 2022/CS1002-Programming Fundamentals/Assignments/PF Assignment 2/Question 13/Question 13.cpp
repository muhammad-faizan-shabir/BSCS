#include <iostream>
#include<cmath>
#include <string>
using namespace std;

void PrintDescriptions(float L)
{
	if ((L >= 0) && (L < 30))
	{
		cout << "A light leaf rustling" << endl;
	}
	else if ((L >= 30) && (L < 60))
	{
		cout << "Calm library" << endl;
	}
	else if ((L >= 60) && (L < 90))
	{
		cout << "Normal conversation" << endl;
	}
	else if ((L >= 90) && (L < 100))
	{
		cout << "Traffic on a busy roadway at 10m" << endl;
	}
	else if ((L >= 100) && (L < 120))
	{
		cout << "Jack hammer at 1m" << endl;
	}
	else if ((L >= 120) && (L < 130))
	{
		cout << "Possible hearing damage" << endl;
	}
	else if (L == 130)
	{
		cout << "Threshold of Pain" << endl;
	}
	else if (L > 130)
	{
		cout << "Threshold of Pain exceeded" << endl;
	}
}

int main()
{
	float L;
	float p;
	const float p0 = 0.00002;
	string choice;
	
	cout << "Enter unit: Either 'dB' or 'Pa' with same spelling as stated" << endl;
	cin >> choice;
	if(choice=="Pa")
	{
		cout << "Enter the sound pressure: " << endl;
		cin >> p;
		L = (20) * (log10(p/p0));
		PrintDescriptions(L);
	}
	else if(choice=="dB")
	{
		cout << "Enter sound level L" << endl;
		cin >> L;
		PrintDescriptions(L);
	}
	else
	{
		cout << "Error! Wrong unit " << endl;
	}
	
	
}
