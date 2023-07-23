#include <iostream>
#include <windows.h> // contains win32 API functions
#include <stdlib.h>  // standard library
#include <time.h>    // for date and time information
#include <conio.h>   // contains the _getch function
#include "Header.h"
using namespace std;
int i; // counter for a loop
int y; // counter for a loop
int pos[50]; 
int length = 3; // length of snake 
int temp; 
int j; // counter for a loop
int f_PosX; // x coordinate of food
int f_PosY; // y coordinate of food
int direction; // direction of snake: can be up,down,left and right
int head_x=25; // x coordinate of snakes's head
int head_y=12; // y coordinate of snake's head
int play = 1;  // game will end when play becomes 0
int s_pos_X[200]; // array to store x coordinates of the body of snake
int s_pos_Y[200]; // array to store y coordinates of the body of snake
int temp_x[200];  // array to temporarily hold the x coordinates of the body of snake
int temp_y[200];  // array to temporarily hold the y coordinates of the body of snake
int score = 0;    // variable to store the score of the player
int delay = 200;  // variable to create a delay of time
int counter = 0;  // counter for incrasing the difficulty level of the game

char ruc = 187; // stores the shape of the Right Upper Corner for the border 
char hl = 205;  // stores the shape of the Horizontal Length for the border
char vl = 186;  // stores the shape of the Vertical Length for the border
char luc = 201; // stores the shape of the Left Upper Corner for the border
char ldc = 200; // stores the shape of the Left Down Corner for the border
char rdc = 188; // stores the shape of the Right Down Corner for the border
char tu = 203;  // stores the shape of Upper T
char td = 202;  // stores the shape of Down T
char food = 153;// stores shape of the food 
char sn = 254;  // stores the shape of the snake's body
char key; // stores the key pressed by the user/player
char snake[200]; // stores the snake

int main()
{
	boder(ruc, hl, vl, luc, ldc, rdc, tu, td,score);
	key = _getch();
	//Sleep(10);
	if (key == 'p' || key == 'P')
	{
		game_play(length, f_PosX, f_PosY, direction, head_x, head_y, play, s_pos_X, s_pos_Y, temp_x, temp_y, score, delay, counter, ruc, hl, vl, luc, ldc, rdc,
			tu, td, food, sn, key, snake);
	}
	else
	{
		main();
	}
}



