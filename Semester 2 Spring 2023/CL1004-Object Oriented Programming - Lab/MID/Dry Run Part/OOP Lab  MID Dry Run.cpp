#include <iostream>
using namespace std;

class Rectangle
{
private:
	int length;
	int width;

public:
	Rectangle(int, int);
	void Print();
	Rectangle GetRotatedRectangle();
	~Rectangle();
};

Rectangle::Rectangle(int l = 0, int w = 0)
{
	cout << "\nConstructor Called with parameters " << l << " and " << w << " \n";
	length = l;
	width = w;
}

Rectangle Rectangle::GetRotatedRectangle()
{
	Rectangle temp(width, length);
	return temp;
}

Rectangle::~Rectangle()
{
	cout << "\nDestructor Called for Rectangle " << length << " X " << width << endl;
}

void Rectangle::Print()
{
	cout << length << " X " << width << endl;
}

int main()
{ 
	{
		Rectangle r1(5, 10);
		cout << "Rectangle 1:\t";
		r1.Print();

		Rectangle r2(2, 3);
		cout << "Rectangle 2:\t";
		r2.Print();

		cout << "Calling Get Rotated Rect.\n";
		r2 = r1.GetRotatedRectangle();

		cout << "Rectangle 2:\t";
		r2.Print();
	}
	system("pause");
}