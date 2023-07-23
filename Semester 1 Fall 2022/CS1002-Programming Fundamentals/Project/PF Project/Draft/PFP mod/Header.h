#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

void gotoxy(int x,int y)
{
	COORD p = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void intro(int score)
{
	gotoxy(54, 4);
	cout << "THE_CLASSIC_SNAKE";
	gotoxy(54, 8);
	cout << "W : UP";
	gotoxy(54, 9);
	cout << "S : DOWN";
	gotoxy(54, 10);
	cout << "D : RIGHT";
	gotoxy(54, 11);
	cout << "A : LEFT";
	gotoxy(54, 12);
	cout << "P : PAUSE/PLAY";
	if (score > 0)
	{
		gotoxy(52, 19);
		cout << "SCORE : " << score;
	}
	gotoxy(54, 14);
	cout << "PROJECT BY :";
	gotoxy(54, 15);
	cout << "Umer Khalid 22L-6546 ";
	gotoxy(54, 16);
	cout << "Faizan Shabir 22L-6552";
	gotoxy(54, 17);
	cout << "Tahawar Ali 22L-6761";
	gotoxy(54, 18);
	cout << "Muhammad Abdullah 22L-6594";
}

void boder(char ruc, char hl, char vl, char luc, char ldc, char rdc, char tu, char td,int score)
{
	intro(score);
	gotoxy(0, 0);
	cout << luc;
	gotoxy(1, 0);
	for (int i = 0; i <= 74; i++)
	{
		cout << hl;
	}
	gotoxy(75, 0);
	cout << ruc;
	for (int i = 1; i <= 24; i++)
	{
		gotoxy(0, i);
		std::cout << vl;
	}
	gotoxy(0, 25);
	cout << ldc;
	gotoxy(1, 25);
	for (int i = 0; i <= 74; i++)
	{
		std::cout << hl;
	}
	gotoxy(75, 25);
	std::cout << rdc;
	for (int i = 1; i <= 25; i++)
	{
		gotoxy(75, i);
		cout << vl;
	}
	gotoxy(75, 25);
	cout << rdc;
	gotoxy(50, 0);
	cout << tu;
	for (int i = 1; i <= 25; i++)
	{
		gotoxy(50, i);
		cout << vl;
	}
	gotoxy(50, 25);
	cout << td;
}
void in_snake(char snake[], int s_pos_X[], int s_pos_Y[],int head_x,int head_y, int length,char sn)
{
	snake[0] = 1;
	s_pos_X[0] = head_x;
	s_pos_Y[0] = head_y;
	for (int i = 1; i < length; i++)
	{
		snake[i] = sn;
		s_pos_X[i] = head_x - i;
		s_pos_Y[i] = head_y;
	}
}

void food_pos(int &f_PosX, int &f_PosY)
{
	srand(time(0));
	f_PosX = rand() % 49 + 1;
	f_PosY = rand() % 24 + 1;
}
void show_food(int& f_PosX, int& f_PosY, char food)
{
	gotoxy(f_PosX, f_PosY);
	cout << food;
}
void sn_eat(int &head_x,int &head_y,int &f_PosX,int &f_PosY,int &length,int s_pos_X[],int s_pos_Y[],char snake[],char sn,int &score,int &counter)
{
	char sound = 7;
	if (head_x == f_PosX && head_y == f_PosY)
	{
		cout << sound;
		length = length + 1;
		s_pos_X[length - 1] = s_pos_X[length - 2];
		s_pos_Y[length - 1] = s_pos_Y[length - 2] - 1;
		snake[length - 1] = sn;
		score = score + 1;
		food_pos(f_PosX, f_PosY);
		//counter = counter + 1;
	}
}

void sn_dir(char key, int &direction)
{
	switch (key)
	{
	case 72:
		if (direction != 2)
		{
			direction = 8;
		}
		break;

	case 'w':
		if (direction != 2)
	    {
			direction = 8;
	    }
		break;
	case 80:
		if (direction != 8)
		{
			direction = 2;
		}
		break;
	case 's': 
		if (direction != 8)
	    {
			direction = 2;
	    }
		break;
	case 77:
		if (direction != 4)
		{
			direction = 6;
		}
		break;
	case 'd': 
		if (direction != 4)
	    {
			direction = 6;
	    }
		break;
	case 75:
		if (direction != 6)
		{
			direction = 4;
		}
		break;
	case 'a': 
		if (direction != 6)
	    {
			direction = 4;
	    }
		break;
	}
}

void pos_val(int direction,int length,int temp_x[],int temp_y[],int s_pos_X[],int s_pos_Y[],int &head_x,int &head_y,bool &flagu, bool &flagd, bool &flagr, bool &flagl)
{
	if (direction == 6)
	{
		for (int j = 0; j < length; j++)
		{
			temp_x[j] = s_pos_X[j];
			temp_y[j] = s_pos_Y[j];
		}
		for (int j = 0; j - 1 < length; j++)
		{
			s_pos_X[j + 1] = temp_x[j];
			s_pos_Y[j + 1] = temp_y[j];
		}
		if(flagr==true)
		{
			head_x = 1;
			s_pos_X[0] = head_x;
			flagr = false;
		}
		else
		{
			head_x = head_x + 1;
			s_pos_X[0] = head_x;
		}
	}
	if (direction == 4)
	{
		for (int j = 0; j < length; j++)
		{
			temp_x[j] = s_pos_X[j];
			temp_y[j] = s_pos_Y[j];
		}
		for (int j = 0; j - 1 < length; j++)
		{
			s_pos_X[j + 1] = temp_x[j];
			s_pos_Y[j + 1] = temp_y[j];
		}
		if(flagl==true)
		{
			head_x = 49;
			s_pos_X[0] = head_x;
			flagl = false;
		}
		else
		{
			head_x = head_x - 1;
			s_pos_X[0] = head_x;
		}
		
	}
	if (direction == 2)
	{
		for (int j = 0; j < length; j++)
		{
			temp_x[j] = s_pos_X[j];
			temp_y[j] = s_pos_Y[j];
		}
		for (int j = 0; j - 1 < length; j++)
		{
			s_pos_X[j + 1] = temp_x[j];
			s_pos_Y[j + 1] = temp_y[j];
		}
		if(flagd==true)
		{
			head_y = 1;
			s_pos_Y[0] = head_y;
			flagd = false;
		}
		else
		{
			head_y = head_y + 1;
			s_pos_Y[0] = head_y;
		}
		
	}
	if (direction == 8)
	{
		for (int j = 0; j < length; j++)
		{
			temp_x[j] = s_pos_X[j];
			temp_y[j] = s_pos_Y[j];
		}
		for (int j = 0; j - 1 < length; j++)
		{
			s_pos_X[j + 1] = temp_x[j];
			s_pos_Y[j + 1] = temp_y[j];
		}
		if(flagu==true)
		{
			head_y = 24;
			s_pos_Y[0] = head_y;
			flagu = false;
		}
		else
		{
			head_y = head_y - 1;
			s_pos_Y[0] = head_y;
		}
		
	}
}

void move(int direction,int y,int s_pos_X[],int s_pos_Y[],char snake[])
{
	if ((direction == 6)||(direction == 4)||(direction == 2)||(direction == 8))
	{
		gotoxy(s_pos_X[y], s_pos_Y[y]);
		cout << snake[y];
	}
}

void check(int length, int &head_x, int &head_y,int s_pos_X[],int s_pos_Y[],int &play, bool &flagu, bool &flagd, bool &flagr, bool &flagl,int &direction)
{
	for (int i = 1; i < length; i++)
	{
		if (head_x == s_pos_X[i] && head_y == s_pos_Y[i])
		{
			play = 0;
		}
	}
	if (((head_x-1) == 0)&&(direction==4))
	{
		//for (int i = 0; i <= 25; i++)
		//{
			//if (head_y == i)
			//{
	    flagl = true;
		
			//}
		//}
	}
	if (((head_x+1) == 50)&&(direction==6))
	{
		//for (int i = 0; i <= 25; i++)
		//{
			//if (head_y == i)
			//{
		flagr = true;
		
			///}
		//}
	}
	if (((head_y-1) == 0)&&(direction==8))
	{
		//for (int i = 0; i <= 50; i++)
		//{
			//if (head_x == i)
			//{
		flagu = true;
		
			//}
		//}
	}
	if (((head_y+1) == 25)&&(direction==2))
	{
		//for (int i = 0; i <= 50; i++)
		//{
			//if (head_x == i)
			//{
		flagd = true;
		
			//}
		//}
	}
}

void game_play(int &length, int &f_PosX, int &f_PosY, int &direction, int &head_x, int &head_y, int &play, int s_pos_X[], int s_pos_Y[], int temp_x[], int temp_y[], int &score, int &delay, int &counter, char &ruc, char &hl, char &vl, char &luc, char &ldc, char &rdc,
	char &tu, char &td, char &food, char &sn, char &key, char snake[],bool &flagu,bool &flagd,bool &flagr,bool &flagl)
{
	
	in_snake(snake,s_pos_X,s_pos_Y,head_x,head_y,length,sn);
	food_pos(f_PosX,f_PosY);
	direction = 6;
	while (play == 1)
	{
		system("cls");
		if (_kbhit())
		{
			key = _getch();
			sn_dir(key,direction);
			if (key == 'p')
			{
				system("pause");
			}
		}
		/*if (counter == 5)
		{
			counter = 0;
			if (delay != 100)
			{
				delay = delay - 10;
			}
		}*/
		show_food(f_PosX,f_PosY,food);
		boder(ruc,hl,vl,luc,ldc,rdc,tu,td,score);
		for (int y = 0; y < length; y++)
		{
			move(direction,y,s_pos_X,s_pos_Y,snake);
		}
		check(length,head_x,head_y,s_pos_X,s_pos_Y,play, flagu, flagd, flagr, flagl,direction);
		sn_eat(head_x,head_y,f_PosX,f_PosY,length,s_pos_X,s_pos_Y,snake,sn,score,counter);
		pos_val(direction,length,temp_x,temp_y,s_pos_X,s_pos_Y,head_x,head_y, flagu, flagd, flagr, flagl);
	    //Sleep(500);
		/*if (play == 1)
		{
			system("cls");
		}*/
		if((play==0)&&(counter<4))
		{
			cout << counter;
			++counter;
			system("cls");
			gotoxy(21, 12);
			cout << "Snake hit itself";
			gotoxy(10, 15);
			cout << "PRESS Y or y to continue";
			gotoxy(25, 16);
			key = _getch();
			while((key!='y')&&(key!='Y'))
			{
				key = _getch();
			}
			play = 1;
			head_x = 1;
			head_y = 1;
			direction = 6;
			in_snake(snake, s_pos_X, s_pos_Y, head_x, head_y, length, sn);
			continue;
		}
		if(counter>=3)
		{
			break;
		}
	}
	gotoxy(21, 12);
	cout << "GAME OVER";
	gotoxy(10, 15);
	cout << "PRESS Y TO PLAY AGAIN ELSE PRESS N";
	gotoxy(25, 16);
	key = _getch();
	cout << key;
	switch (key)
	{
	case 'y':score = 0;
		length = 3;
		play = 1;
		in_snake(snake, s_pos_X, s_pos_Y, head_x, head_y, length, sn);
		system("cls");
		head_x = 7;
		head_y = 1;
		delay = 200;
		direction = 6;
		boder(ruc, hl, vl, luc, ldc, rdc, tu, td,score);
		game_play(length, f_PosX, f_PosY, direction, head_x, head_y, play, s_pos_X, s_pos_Y, temp_x, temp_y, score, delay, counter, ruc, hl, vl, luc, ldc, rdc,
			tu, td, food, sn, key, snake, flagu, flagd, flagr, flagl);
		break;
	default:system("cls");
		boder(ruc, hl, vl, luc, ldc, rdc, tu, td,score);
		gotoxy(15, 12);
		cout << "THANKS FOR PLAYING";
		break;
	}
	gotoxy(0, 26);
}