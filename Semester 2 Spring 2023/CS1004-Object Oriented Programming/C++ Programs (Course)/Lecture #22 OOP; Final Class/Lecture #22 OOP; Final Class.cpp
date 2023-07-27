#include<iostream>
using namespace std;

class A final
{
};

class B : public A // cannot inherit class A
{
};