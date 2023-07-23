#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
using namespace std;
int i, y, pos[50], length = 3, temp, j, f_PosX, f_PosY, movement, head_x = 25;
int head_y = 12, game = 1, s_pos_X[200], s_pos_Y[200], temp_x[200], temp_y[200], score = 0, wait = 200, counter = 0;
char rc = 187, hl = 205, vl = 186, lc = 201, ldc = 200, rdc = 188, t = 203, td = 202, food = 153, sn = 254, key;
void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
char snake[200];
void move();
void in_snake();
void pos_val();
void boder();
void food_pos();
void show_food();
void sn_dir();
void pause_play();
void game_play();
void sn_eat();
void check();
void start();
int main()
{
	boder();
	key = _getch();
	Sleep(10);
	if (key == 'p' || key == 'P')
	{
		start();
	}
	else
	{
		main();
	}
}
void move()
{
	if (movement == 6)
	{
		gotoxy(s_pos_X[y], s_pos_Y[y]);
		cout << snake[y];
	}
	if (movement == 4)
	{
		gotoxy(s_pos_X[y], s_pos_Y[y]);
		cout << snake[y];
	}
	if (movement == 2)
	{
		gotoxy(s_pos_X[y], s_pos_Y[y]);
		cout << snake[y];
	}
	if (movement == 8)
	{
		gotoxy(s_pos_X[y], s_pos_Y[y]);
		cout << snake[y];
	}
}
void pos_val()
{
	if (movement == 6)
	{
		for (j = 0; j < length; j++)
		{
			temp_x[j] = s_pos_X[j];
			temp_y[j] = s_pos_Y[j];
		}
		for (j = 0; j - 1 < length; j++)
		{
			s_pos_X[j + 1] = temp_x[j];
			s_pos_Y[j + 1] = temp_y[j];
		}
		head_x = head_x + 1;
		s_pos_X[0] = head_x;
	}
	if (movement == 4)
	{
		for (j = 0; j < length; j++)
		{
			temp_x[j] = s_pos_X[j];
			temp_y[j] = s_pos_Y[j];
		}
		for (j = 0; j - 1 < length; j++)
		{
			s_pos_X[j + 1] = temp_x[j];
			s_pos_Y[j + 1] = temp_y[j];
		}
		head_x = head_x - 1;
		s_pos_X[0] = head_x;
	}
	if (movement == 2)
	{
		for (j = 0; j < length; j++)
		{
			temp_x[j] = s_pos_X[j];
			temp_y[j] = s_pos_Y[j];
		}
		for (j = 0; j - 1 < length; j++)
		{
			s_pos_X[j + 1] = temp_x[j];
			s_pos_Y[j + 1] = temp_y[j];
		}
		head_y = head_y + 1;
		s_pos_Y[0] = head_y;
	}
	if (movement == 8)
	{
		for (j = 0; j < length; j++)
		{
			temp_x[j] = s_pos_X[j];
			temp_y[j] = s_pos_Y[j];
		}
		for (j = 0; j - 1 < length; j++)
		{
			s_pos_X[j + 1] = temp_x[j];
			s_pos_Y[j + 1] = temp_y[j];
		}
		head_y = head_y - 1;
		s_pos_Y[0] = head_y;
	}
}
void intro()
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
	gotoxy(55, 24);
	cout << "CODED BY : ANKIT";
}
void boder()
{
	intro();
	gotoxy(0, 0);
	cout << lc;
	gotoxy(1, 0);
	for (i = 0; i <= 74; i++)
	{
		cout << hl;
	}
	gotoxy(75, 0);
	cout << rc;
	for (i = 1; i <= 24; i++)
	{
		gotoxy(0, i);
		std::cout << vl;
	}
	gotoxy(0, 25);
	cout << ldc;
	gotoxy(1, 25);
	for (i = 0; i <= 74; i++)
	{
		std::cout << hl;
	}
	gotoxy(75, 25);
	std::cout << rdc;
	for (i = 1; i <= 25; i++)
	{
		gotoxy(75, i);
		cout << vl;
	}
	gotoxy(75, 25);
	cout << rdc;
	gotoxy(50, 0);
	cout << t;
	for (i = 1; i <= 25; i++)
	{
		gotoxy(50, i);
		cout << vl;
	}
	gotoxy(50, 25);
	cout << td;
}
void food_pos()
{
	srand(time(0));
	f_PosX = rand() % 49 + 1;
	f_PosY = rand() % 24 + 1;
}
void show_food()
{
	gotoxy(f_PosX, f_PosY);
	cout << food;
}
void sn_dir()
{
	switch (key)
	{
	case'W':
	case 'w': if (movement != 2)
	{
		movement = 8;
	}
			break;
	case 'S':
	case 's': if (movement != 8)
	{
		movement = 2;
	}
			break;
	case 'D':
	case 'd': if (movement != 4)
	{
		movement = 6;
	}
			break;
	case 'A':
	case 'a': if (movement != 6)
	{
		movement = 4;
	}
			break;
	}
}
void sn_eat()
{
	if (head_x == f_PosX && head_y == f_PosY)
	{
		length = length + 1;
		s_pos_X[length - 1] = s_pos_X[length - 2];
		s_pos_Y[length - 1] = s_pos_Y[length - 2] - 1;
		snake[length - 1] = sn;
		score = score + 1;
		food_pos();
		counter = counter + 1;
	}
}
void check()
{
	for (i = 1; i < length; i++)
	{
		if (head_x == s_pos_X[i] && head_y == s_pos_Y[i])
		{
			game = 0;
		}
	}
	if (head_x == 0)
	{
		for (i = 0; i <= 25; i++)
		{
			if (head_y == i)
			{
				game = 0;
			}
		}
	}
	if (head_x == 50)
	{
		for (i = 0; i <= 25; i++)
		{
			if (head_y == i)
			{
				game = 0;
			}
		}
	}
	if (head_y == 0)
	{
		for (i = 0; i <= 50; i++)
		{
			if (head_x == i)
			{
				game = 0;
			}
		}
	}
	if (head_y == 25)
	{
		for (i = 0; i <= 50; i++)
		{
			if (head_x == i)
			{
				game = 0;
			}
		}
	}
}
void in_snake()
{
	snake[0] = 1;
	s_pos_X[0] = head_x;
	s_pos_Y[0] = head_y;
	for (i = 1; i < length; i++)
	{
		snake[i] = sn;
		s_pos_X[i] = head_x - i;
		s_pos_Y[i] = head_y;
	}
}
void game_play()
{
	in_snake();
	food_pos();
	movement = 6;
	while (game == 1)
	{
		system("cls");
		if (_kbhit())
		{
			key = _getch();
			sn_dir();
			if (key == 'p')
			{
				system("pause");
			}
		}
		if (counter == 5)
		{
			counter = 0;
			if (wait != 100)
			{
				wait = wait - 10;
			}
		}
		show_food();
		boder();
		for (y = 0; y < length; y++)
		{
			move();
		}
		check();
		sn_eat();
		pos_val();
		Sleep(wait);
		if (game == 1)
		{
			system("cls");
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
		game = 1;
		in_snake();
		system("cls");
		head_x = 7;
		head_y = 1;
		wait = 200;
		movement = 6;
		boder();
		game_play();
		break;
	default:system("cls");
		boder();
		gotoxy(15, 12);
		cout << "THANKS FOR PLAYING";
		break;
	}
	gotoxy(0, 26);
}
void start()
{
	game_play();
}
