#include <iostream>
#include <windows.h>   // contains COORD class and SetConsoleCursorPosition() function
#include <stdlib.h>    // contains srand(), rand() and system() functions
#include <time.h>      // contains time() function
#include <conio.h>     // contains _getch() and _kbhit() functions
#include "Header.h"    // our own header file
using namespace std;
int main()
{
	int length = 3;    // length of snake 
	int f_PosX;        // x coordinate of food
	int f_PosY;        // y coordinate of food
	int direction;     // direction of snake: can be up,down,left and right
	int head_x = 25;   // x coordinate of snakes's head
	int head_y = 12;   // y coordinate of snake's head
	int play = 1;      // game will end when play becomes 0
	int s_pos_X[200];  // array to store x coordinates of the body of snake
	int s_pos_Y[200];  // array to store y coordinates of the body of snake
	int score = 0;     // variable to store the score of the player
    
	char ruc = 187;    // stores the shape of the Right Upper Corner for the border 
	char hl = 205;     // stores the shape of the Horizontal Length for the border
	char vl = 186;     // stores the shape of the Vertical Length for the border
	char luc = 201;    // stores the shape of the Left Upper Corner for the border
	char ldc = 200;    // stores the shape of the Left Down Corner for the border
	char rdc = 188;    // stores the shape of the Right Down Corner for the border
	char tu = 203;     // stores the shape of Upper T
	char td = 202;     // stores the shape of Down T
	char food = 153;   // stores shape of the food 
	char sb = 254;     // stores the shape of the Snake's Body
	char key;          // stores the key pressed by the user/player
	char sf = 1;       // stores the shape of the Snake's head/Face
	
	bool flagu = false;// flag becomes true when snake touches the upper edge
	bool flagd = false;// flag becomes true when snake touches the lower edge
	bool flagr = false;// flag becomes true when snake touches right edge
	bool flagl = false;// flag becomes true when snake touches left edge
	
	boder(ruc, hl, vl, luc, ldc, rdc, tu, td,score); // calling the boder() function to draw the borders
	
	key = _getch(); // getting input from user to start the game
	while ((key!='p')&&(key!='P')) // loop will run until the user presses 'p' or 'P' to start the game
	{
		key = _getch();
	}
	
	game_play(length, f_PosX, f_PosY, direction, head_x, head_y, play, s_pos_X, s_pos_Y,score, ruc, hl, vl, luc, ldc, rdc,
			tu, td, food, sb, key, sf, flagu, flagd, flagr, flagl); // calling game_play() function to start the game
}



