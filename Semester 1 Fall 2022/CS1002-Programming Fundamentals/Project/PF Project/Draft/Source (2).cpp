#include<iostream>
#include<conio.h>
#include"help.h"
using namespace std;

int key;
int a = 120, b = 140, c = 200, d = 125, e = 185, y = 665, f;

void init()
{
	myRectangle(0, 0, 910, 700, 205, 92, 92);
	myLine(0, 400, 100, 250, 250);
	myLine(100, 250, 200, 400, 250);
	myLine(200, 400, 300, 250, 250);
	myLine(300, 250, 400, 400, 250);
	myLine(400, 400, 500, 250, 250);
	myLine(500, 250, 600, 400, 250);
	myLine(600, 400, 700, 250, 250);
	myLine(700, 250, 800, 400, 250);
	myLine(800, 400, 900, 250, 250);
	myLine(450, 680, 450, 700, 250);
	myLine(450, 20, 450, 35, 250); //stars
	myLine(445, 28, 455, 28, 250);
	myLine(570, 20, 570, 35, 250);
	myLine(565, 28, 575, 28, 250);
	myLine(600, 120, 600, 135, 250);
	myLine(595, 128, 605, 128, 250);
	myLine(50, 120, 50, 135, 250);
	myLine(45, 128, 55, 128, 250);
	myLine(300, 130, 300, 145, 250);
	myLine(295, 138, 305, 138, 250);
	myLine(800, 170, 800, 185, 250);
	myLine(795, 178, 805, 178, 250);
	myLine(150, 170, 150, 185, 250);
	myLine(145, 178, 155, 178, 250);
	myLine(165, 30, 165, 45, 250);
	myLine(160, 38, 170, 38, 250);
	myLine(700, 60, 700, 75, 250);
	myLine(695, 68, 705, 68, 250);

	myRectangle(a, 630, a + 95, 665, 0, 128, 0);
	myRectangle(b, 600, b + 60, 630, 0, 128, 0);
	myRectangle(c, 609, c + 20, 619, 0, 128, 0);
	myEllipse(d, 665, d + 30, 690, 192, 192, 192);
	myEllipse(e, 665, e + 30, 690, 192, 192, 192);
	myEllipse(100, 50, 150, 150, 132, 112, 255);
	myEllipse(80, 90, 170, 120, 0, 128, 128);
	
}

int x1 = 695;
int x2 = 715;
int mid = 705;
bool flag = true;
void moveTarget()
{
	Sleep(100);
	if (x2 == 905)
		flag = false;
	else if (x1 == 465)
		flag = true;
	if (flag) {
		myEllipse(x1, 685, x2, 630, 0, 0, 0);
		myLine(mid, 695, mid, 685, 0);
		x1 += 10;
		x2 += 10;
		mid += 10;
		myEllipse(x1, 685, x2, 630, 255, 0, 0);
		myLine(mid, 695, mid, 685, 250);

	}
	else
	{
		myEllipse(x1, 685, x2, 630, 0, 0, 0);
		myLine(mid, 695, mid, 685, 0);
		x1 -= 10;
		x2 -= 10;
		mid -= 10;
		myEllipse(x1, 685, x2, 630, 255, 0, 0);
		myLine(mid, 695, mid, 685, 250);
	}
}
int main()
{

	cout << "Instructions:" << endl;
	cout << "1:Use left and right cursor keys to move the tank" << endl;
	cout << "2:Use Up and Down cursor keys to shoot from the tank. " << endl;
	cout << "3:Hit the red target with bullet to win!!" << endl;
	system("Pause");

	init();
	int i = 1;
	int j = 1;

	while(i>0)
	{
		//tankmovement
		if(isCursorKeyPressed(key))
		{
			f = c;
			if(key==3 && c!=430)//forward
			{
				myRectangle(a, 630, a + 95, 665, 0, 0, 0);
				myRectangle(b, 600, b + 60, 630, 0, 0, 0);
				myRectangle(c, 609, c + 20, 619, 0, 0, 0);
				myEllipse(d, 665, d + 30, 690, 0, 0, 0);
				myEllipse(e, 665, e + 30, 690, 0, 0, 0);
				a = a + 10;
				b = b + 10;
				c = c + 10;
				d = d + 10;
				e = e + 10;
				myRectangle(a, 630, a + 95, 665, 0, 128, 0);
				myRectangle(b, 600, b + 60, 630, 0, 128, 0);
				myRectangle(c, 609, c + 20, 619, 0, 128, 0);
				myEllipse(d, 665, d + 30, 690, 192, 192, 192);
				myEllipse(e, 665, e + 30, 690, 192, 192, 192);
			}
			else if(key == 1 && a!=10)//backward
			{
				myRectangle(a, 630, a + 95, 665, 0, 0, 0);
				myRectangle(b, 600, b + 60, 630, 0, 0, 0);
				myRectangle(c, 609, c + 25, 619, 0, 0, 0);
				myEllipse(d, 665, d + 30, 690, 0, 0, 0);
				myEllipse(e, 665, e + 30, 690, 0, 0, 0);
				a = a - 10;
				b = b - 10;
				c = c - 10;
				d = d - 10;
				e = e - 10;
				myRectangle(a, 630, a + 95, 665, 0, 128, 0);
				myRectangle(b, 600, b + 60, 630, 0, 128, 0);
				myRectangle(c, 609, c + 20, 619, 0, 128, 0);
				myEllipse(d, 665, d + 30, 690, 192, 192, 192);
				myEllipse(e, 665, e + 30, 690, 192, 192, 192);
			}
			else if(key==2 || key==4)//attack
			{
				y = 620;
				myEllipse(f+25, y, f+5, y+5, 255, 255, 0);
				for(int j = 1;j<65;j++)
				{
					myEllipse(f + 25, y, f + 5, y + 5, 0, 128, 128);
					Sleep(10);
					myEllipse(f + 25, y, f + 5, y + 5, 0, 0, 0);
					f = f + 5;
					y = y + 1;
					myLine(450, 680, 450, 700, 250);
					if (y > 630 && y  < 685)
					{
						if (f+5 > x1 && f + 5< x2)
							i = -1;
					}	
				}
			}
		}
		moveTarget();
	}
	system("CLS");
	cout << "Congrats You Won!!";
	_getch();
	return 0;
}