#include <iostream>
#include <windows.h>   // contains COORD class and SetConsoleCursorPosition() function
#include <stdlib.h>    // contains srand(), rand() and system() functions
#include <time.h>      // contains time() function
#include <conio.h>     // contains _getch() and _kbhit() functions
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////
void gotoxy(int x,int y) // go to x and y function
{
	COORD p = { x,y }; // creating object named p of COORD class to store x and y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p); // moving the cursor to the coordinates in the object named p
}
//////////////////////////////////////////////////////////////////////////////////////
void intro(int score) // this function prints the intro
{
	// printing the name of the game
	gotoxy(54, 4);
	cout << "THE_CLASSIC_SNAKE";
	// printing the controls of the game
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
	
	// printing the score of the game
	gotoxy(54, 14);
	cout << "SCORE : " << score;
	gotoxy(54, 15);
	cout << "SNAKE LENGTH : " << score + 3;
	
	// printing the group members
	gotoxy(52, 17);
	cout << "PROJECT BY :";
	gotoxy(52, 18);
	cout << "Umer Khalid 22L-6546 ";
	gotoxy(52, 19);
	cout << "Faizan Shabir 22L-6552";
	gotoxy(52, 20);
	cout << "Tahawar Ali 22L-6761";
	gotoxy(52, 21);
	cout << "M.Abdullah 22L-6594";
}
//////////////////////////////////////////////////////////////////////////////////////
void boder(char ruc, char hl, char vl, char luc, char ldc, char rdc, char tu, char td,int score)// function prints the border
{
	intro(score); // calling the intro() function
	gotoxy(0, 0); // moving the cursor to (0,0) coordinates
	cout << luc;  // printing the Left Upper Corner of the border
	gotoxy(1, 0); // moving the cursor to (1,0) coordinates
	for (int i = 0; i <= 74; i++)
	{
		cout << hl; // printing the upper Horizontal Length of the border
	}
	gotoxy(75, 0); // moving the cursor to (75,0) coordinates
	cout << ruc;   // printing the Right Upper Corner of the border
	for (int i = 1; i <= 24; i++)
	{
		gotoxy(0, i);
		cout << vl; // printing the left Vertical Length of the border
	}
	gotoxy(0, 25); // moving the cursor to (0,25) coordinates
	cout << ldc;   // printing the Left Down Corner of the border
	gotoxy(1, 25); // moving the cursor to (1,25) coordinates
	for (int i = 0; i <= 74; i++)
	{
		cout << hl; // printing the lower Horizontal Length of the border
	}
	
	for (int i = 1; i <= 24; i++)
	{
		gotoxy(75, i);
		cout << vl; // printing the right Vertical Length of the border
	}
	gotoxy(75, 25); // moving the cursor to (75,25) coordinates
	cout << rdc;    // printing the Right Down Corner of the border
	gotoxy(50, 0); // moving the cursor to (50,0) coordinates
	cout << tu; // printing the 'T' shape
	for (int i = 1; i <= 25; i++)
	{
		gotoxy(50, i);
		cout << vl; // printing the vertical length of the 'T' shape
	}
	gotoxy(50, 25); // moving the cursor to (50,25) coordinates
	cout << td;     // printing the 'T' shape upside down
}
//////////////////////////////////////////////////////////////////////////////////////
void in_snake(int s_pos_X[], int s_pos_Y[],int head_x,int head_y, int length) // this function initialises the snake
{
	s_pos_X[0] = head_x; // initialising x coordinate of snake's head
	s_pos_Y[0] = head_y; // initialising y coordinate of snake's head
	for (int i = 1; i < length; i++) // intial snake length is 3
	{
		s_pos_X[i] = head_x - i; // initialising x coordinates of snake's body
		s_pos_Y[i] = head_y;     // intialising y coordinates of snake's body
	}
}
//////////////////////////////////////////////////////////////////////////////////////
void food_pos(int &f_PosX, int &f_PosY) // this function gives random coordinates for food
{
	srand(time(0));
	f_PosX = rand() % 49 + 1; // giving a random value to x coordinate of food
	f_PosY = rand() % 22 + 2; // giving a random value to y coordinate of food
}
//////////////////////////////////////////////////////////////////////////////////////
void show_food(int& f_PosX, int& f_PosY, char food) // this functions prints the food on the screen
{
	gotoxy(f_PosX, f_PosY); // moving the cursor to coordinates of the food
	cout << food; // printing the food
}
//////////////////////////////////////////////////////////////////////////////////////
void sn_eat(int &head_x,int &head_y,int &f_PosX,int &f_PosY,int &length,int s_pos_X[],int s_pos_Y[],int &score)// this functions checks if the snake has eaten the food
{
	char sound = 7; // ASCII value of sound
	if (head_x == f_PosX && head_y == f_PosY) // matching coordinates of snake's head with coordinates of food
	{
		cout << sound; // outputting sound when snake eats food
		length = length + 1; // incrementing snake's length
		score = score + 1; // updating the score
		food_pos(f_PosX, f_PosY); // determining new coordinates of the food
	}
}
//////////////////////////////////////////////////////////////////////////////////////
void sn_dir(char key, int &direction) // this function determines snake's direction
{
	switch (key)
	{
	case 'W': // for 'W', the direction becomes 8
		if (direction != 2)
		{
			direction = 8;
		}
		break;

	case 'w': // for 'w', the direction becomes 8
		if (direction != 2)
	    {
			direction = 8;
	    }
		break;
	case 'S': // for 'S', the direction becomes 2
		if (direction != 8)
		{
			direction = 2;
		}
		break;
	case 's': // for 's', the direction becomes 2
		if (direction != 8)
	    {
			direction = 2;
	    }
		break;
	case 'D': // for 'D', the direction becomes 6
		if (direction != 4)
		{
			direction = 6;
		}
		break;
	case 'd': // for 'd', the direction becomes 6
		if (direction != 4)
	    {
			direction = 6;
	    }
		break;
	case 'A': // for 'A', the direction becomes 4
		if (direction != 6)
		{
			direction = 4;
		}
		break;
	case 'a': // for 'a', the direction becomes 4
		if (direction != 6)
	    {
			direction = 4;
	    }
		break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////
void pos_val(int direction,int length,int s_pos_X[],int s_pos_Y[],int &head_x,int &head_y,bool &flagu, bool &flagd, bool &flagr, bool &flagl)
{
	// this function determines the updated coordinates of the whole snake's body
	for (int j = (length-1); j>=0; j--)
	{
		s_pos_X[j + 1] = s_pos_X[j]; // shifting all x coordinates by 1 index to the right
		s_pos_Y[j + 1] = s_pos_Y[j]; // shifting all y coordinates by 1 index to the right
	}

	if (direction == 6) // if direction is 6/right
	{
		if(flagr==true) // if snake touches the right edge of border
		{
			head_x = 1; // x coordinate of head becomes 1
			s_pos_X[0] = head_x;// updating x coordinate of head in the array
			flagr = false; // making the flag false
			// no change needed to the y coordinate
		}
		else // if snake is within the border
		{
			head_x = head_x + 1; // incrementing x coordinate of head by one
			s_pos_X[0] = head_x; // updating x coordinate of head in the array
			// no change needed to the y coordinate
		}
	}
	
	if (direction == 4) // if direction is 4/left
	{
		if(flagl==true) // if snake touches the left edge of border
		{
			head_x = 49; // x coordinate of head becomes 49
			s_pos_X[0] = head_x; // updating x coordinate of head in the array
			flagl = false; // making the flag false
			// no change needed to the y coordinate
		}
		else // if snake is within the border
		{
			head_x = head_x - 1; // decrementing x coordinate of head by one
			s_pos_X[0] = head_x; // updating x coordinate of head in the array
			// no change needed to the y coordinate
		}
	}
	
	if (direction == 2) // if direction is 2/down
	{
		if(flagd==true) // if snake touches the lower edge of border
		{
			head_y = 1; // y coordinate of head becomes 1
			s_pos_Y[0] = head_y; // updating y coordinate of head in the array
			flagd = false; // making the flag false
			// no change needed to the x coordinate
		}
		else // if snake is within the border
		{
			head_y = head_y + 1; // incrementing y coordinate of head by one
			s_pos_Y[0] = head_y; // updating y coordinate of head in the array
			// no change needed to the x coordinate
		}
	}
	
	if (direction == 8) // if direction is 8/up
	{
		if(flagu==true) // if snake touches the upper edge of border
		{
			head_y = 24; // y coordinate of head becomes 24
			s_pos_Y[0] = head_y; // updating y coordinate of head in the array
			flagu = false; // making the flag false
			// no change needed to the x coordinate
		}
		else // if snake is within the border
		{
			head_y = head_y - 1; // decrementing y coordinate of head by one
			s_pos_Y[0] = head_y; // updating y coordinate of head in the array
			// no change needed to the x coordinate
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////
void move(int direction,int y,int s_pos_X[],int s_pos_Y[],char sf,char sb)
{
	// this function moves/prints the snake at coordinates present in the arrays
	if ((direction == 6)||(direction == 4)||(direction == 2)||(direction == 8))
	{
		gotoxy(s_pos_X[y], s_pos_Y[y]); // moving the cursor at the coordinates in the arrays
		if(y!=0) // if y/index is not 0 then printing the body of snake
		{
			cout << sb;
		}
		else // if y/index is 0 then printing face/head of the snake since head/face is at the 0 index position
		{
			cout << sf;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////
void check(int length, int &head_x, int &head_y,int s_pos_X[],int s_pos_Y[],int &play, bool &flagu, bool &flagd, bool &flagr, bool &flagl,int &direction)
{
	// this function checks the snakes movement and behaviour
	char sound = 7;
	for (int i = 1; i < length; i++)
	{
		// if the snake's head's coordinates match with one of its body's coordinates i.e snake hits itself
		if (head_x == s_pos_X[i] && head_y == s_pos_Y[i])
		{
			cout << sound; // outputing a sound
			play = 0; // putting play equal to 0 so that the outer most while loop breaks/ends
		}
	}

	if (((head_x-1) == 0)&&(direction==4)) // if snake is about to hit the left border
	{
		flagl = true; // making left flag true
	}

	if (((head_x+1) == 50)&&(direction==6)) // if snake is about to hit the right border
	{
		flagr = true; // making the right flag true
	}

	if (((head_y-1) == 0)&&(direction==8)) // if the snake is about to hit the upper border
	{
		flagu = true; // making the up flag true
	}

	if (((head_y+1) == 25)&&(direction==2)) // if the snake is about to hit the lower border
	{
		flagd = true; // making the down flag true
	}
}
//////////////////////////////////////////////////////////////////////////////////////
void game_play(int &length, int &f_PosX, int &f_PosY, int &direction, int &head_x, int &head_y, int &play, int s_pos_X[], int s_pos_Y[],int &score,char &ruc, char &hl, char &vl, char &luc, char &ldc, char &rdc,
	char &tu, char &td, char &food, char &sb, char &key, char &sf,bool &flagu,bool &flagd,bool &flagr,bool &flagl)
{
	// this function runs the game by calling appropriate functions
	in_snake(s_pos_X,s_pos_Y,head_x,head_y,length); // calling the in_snake() function
	
	food_pos(f_PosX,f_PosY); // calling the food_pos() function
	
	direction = 6; // initially the direction of the snake will be 6/right
	
	while (play == 1) // loop will exit when play becomes zero
	{
		system("cls"); // clearing the screen of console
		if (_kbhit())  // checking if the user has pressed a key on the keyboard or not 
		{
			key = _getch(); // geting the key pressed by the user
			sn_dir(key,direction); // calling the sn_dir() function
			if ((key == 'p')or(key=='P')) //checking if the user presses 'p' or 'P' during the game 
			{
				system("pause"); // halting the program execution until the user presses any key
			}
		}
		
		show_food(f_PosX,f_PosY,food); // calling the show_food() function
		
		boder(ruc,hl,vl,luc,ldc,rdc,tu,td,score); // calling the boder() function
		
		for (int y = 0; y < length; y++) // loop will run for the length of the snake
		{
			move(direction,y,s_pos_X,s_pos_Y,sf,sb); // calling the move() function
		}
		
		check(length,head_x,head_y,s_pos_X,s_pos_Y,play, flagu, flagd, flagr, flagl,direction); // calling the check() function
		
		sn_eat(head_x,head_y,f_PosX,f_PosY,length,s_pos_X,s_pos_Y,score); // calling the sn_eat() function
		
		pos_val(direction,length,s_pos_X,s_pos_Y,head_x,head_y, flagu, flagd, flagr, flagl); // calling the pos_val() function
	}
	
	gotoxy(21, 10); // moving the cursor to (21,10) coordinates
	cout << "GAME OVER";
    gotoxy(15, 12); // moving the cursor to (15,12) coordinates
	cout << "THANKS FOR PLAYING";
	gotoxy(0, 27);// moving the cursor to (0,27) coordinates
}