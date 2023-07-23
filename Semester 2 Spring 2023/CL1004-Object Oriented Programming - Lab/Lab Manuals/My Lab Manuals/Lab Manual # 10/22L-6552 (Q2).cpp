#include <iostream>
using namespace std;

class BasicShape
{
protected:
	double area;
public:
	double getArea()
	{
		return area;
	}

	virtual void calcArea() = 0;
};

class Circle: public BasicShape
{
private:
	long int centerX;
	long int centerY;
	double radius;
public:
	Circle(long int x=0,long int y=0,int r=0)
	{
		centerX = x;
		centerY = y;
		radius = r;
		calcArea();
	}

	long int getCenterX()
	{
		return centerX;
	}

	long int getCenterY()
	{
		return centerY;
	}

	void calcArea()
	{
		area = 3.14159*radius*radius;
	}
};

class Rectangle: public BasicShape
{
private:
	long int width;
	long int length;
public:
	Rectangle(long int w,long int l)
	{
		width = w;
		length = l;
		calcArea();
	}

	long int getWidth()
	{
		return width;
	}

	long int getLength()
	{
		return length;
	}

	void calcArea()
	{
		area = length*width;
	}
};

int main()
{
	cout << "Making a CIRCLE OBJECT with RADIUS=4" << endl;
	Circle obj1(0, 0, 4);
	cout << "The area of the CIRCLE is: " << obj1.getArea() << endl << endl;

	cout << "Making a RECTANGLE OBJECT with LENGTH =4 and WIDTH=3 " << endl;
	Rectangle obj2(3, 4);
	cout << "The area of the RECTANGLE is: " << obj2.getArea() << endl;
	
	cout << endl;
	system("pause");
}