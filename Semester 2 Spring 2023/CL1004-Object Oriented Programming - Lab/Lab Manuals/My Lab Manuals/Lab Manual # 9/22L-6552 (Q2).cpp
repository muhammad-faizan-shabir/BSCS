#include<iostream>
using namespace std;

class shape
{
protected:
	double length;
	double breadth;
	double height;
public:
	shape(double l=0, double b=0, double h=0)
	{
		length = l;
		breadth = b;
		height = h;
	}

	virtual double getArea() = 0;
};

class painting
{
public:
	double getCost(double area)
	{
		return(area * 10);
	}
};

class square: public shape, public painting
{
public:
	square(int l = 0, int b = 0, int h = 0) :shape(l,b,h)
	{
	}

	double getArea()
	{
		return(length*length);
	}
};

class rectangle :public shape, public painting
{
public:
	rectangle(int l = 0, int b = 0, int h = 0) :shape(l,b, h)
	{
	}

	double getArea()
	{
		return (length*breadth);
	}
};

class triangle :public shape, public painting
{
public:
	triangle(int l = 0, int b = 0, int h = 0) :shape(l, b, h)
	{
	}

	double getArea()
	{
		return(0.5*breadth*height);
	}
};

int main()
{
	cout << "The rate of paint per unit area is: 10 ruppees" << endl << endl;

	cout << "Making a SQUARE with 5 length and 5 breadth " << endl;
	square obj1(5, 5);
	cout << "Area of SQUARE is: " << obj1.getArea() << endl;
	cout << "Cost of painting SQUARE is: " << obj1.getCost(obj1.getArea()) << endl << endl;

	cout << "Making a RECTANGLE with 7 length and 5 breadth" << endl;
	rectangle obj2(7, 5);
	cout << "Area of RECTANGLE is: " << obj2.getArea() << endl;
	cout << "Cost of painting RECTANGLE is: " << obj2.getCost(obj2.getArea()) << endl << endl;

	cout << "Making a TRIANGLE with 30 breadth and 2 height" << endl;
	triangle obj3(0, 30, 2);
	cout << "Area of TRIANGLE is: " << obj3.getArea() << endl;
	cout << "Cost of painting TRIANGLE is: " << obj3.getCost(obj3.getArea()) << endl << endl;

	system("pause");
}