#include<iostream>
using namespace std;

// Extended Euclidean Algorithm
int extendedGCD(int a, int b, int& x, int& y) 
{
	if (a == 0) 
	{
		x = 0;
		y = 1;
		return b;
	}

	int x1, y1;
	int gcd = extendedGCD(b % a, a, x1, y1);

	x = y1 - (b / a) * x1;
	y = x1;

	return gcd;
}

// Modular Inverse Function
int modInverse(int a, int m) 
{
	int x, y;
	int gcd = extendedGCD(a, m, x, y);

	if (gcd != 1) 
	{
		throw runtime_error("Modular inverse does not exist");
	}

	return (x % m + m) % m;
}

int addition(int num1,int num2)
{
	const int m1 = 99;
	const int m2 = 98;
	const int m3 = 97;
	const int m4 = 95;

	int tupleNum1[4];
	int tupleNum2[4];
	
	tupleNum1[0] = num1 % m1;
	tupleNum1[1] = num1 % m2;
	tupleNum1[2] = num1 % m3;
	tupleNum1[3] = num1 % m4;

	tupleNum2[0] = num2 % m1;
	tupleNum2[1] = num2 % m2;
	tupleNum2[2] = num2 % m3;
	tupleNum2[3] = num2 % m4;

	int a1 = (tupleNum1[0] + tupleNum2[0]) % m1;
	int a2 = (tupleNum1[1] + tupleNum2[1]) % m2;
	int a3 = (tupleNum1[2] + tupleNum2[2]) % m3;
	int a4 = (tupleNum1[3] + tupleNum2[3]) % m4;

	int m = m1 * m2 * m3 * m4;
	int M1 = m / m1;
	int M2 = m / m2;
	int M3 = m / m3;
	int M4 = m / m4;

	int result = ((a1 * M1 * modInverse(M1, m1)) + (a2 * M2 * modInverse(M2, m2)) + (a3 * M3 * modInverse(M3, m3)) + (a4 * M4 * modInverse(M1, m1))) % m;
	return result;
}

