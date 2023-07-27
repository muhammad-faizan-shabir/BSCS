#include<iostream>
using namespace std;

class Parent
{
public:
	virtual void func() final // cannot be overridden
	{
	}
};

class Child: public Parent
{
public:
	void func() // cannot override the func() in Parent class
	{
	}
};