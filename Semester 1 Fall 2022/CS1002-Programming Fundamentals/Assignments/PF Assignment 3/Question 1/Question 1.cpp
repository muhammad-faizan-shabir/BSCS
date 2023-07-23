#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int sum1=0; // total for player one
	int sum2=0; // total for player two
	int dice1;  // dice value of player one
	int dice2; // dice value of player two

	srand(time(0));
	for(;1;)
	{
		cout << "Player 1's turn (press any key): "; //start of player one's code
		_getch();
		
		dice1 = (rand() % 6) + 1; //random dice value of player one
		cout << dice1<<endl;
		
		if((sum1+dice1)<=20) // checking if move is possible or not
		{
			sum1 = sum1 + dice1;
			cout << "Player 1's total: " << sum1 << endl;
		}
		else
		{
			cout << "Player 1's total: " << sum1 << " (move not possible)" << endl;
		}

		if(sum1==20) //checking if player one's total has become 20
		{
			break;
		}
		
		
		cout << "Player 2's turn (press any key): ";  // start of player two's code
		_getch();
		
		dice2 = (rand() % 6) + 1; //random dice value of player two
		cout << dice2 << endl;

		if ((sum2 + dice2) <= 20) // checking if move is possible or not
		{
			sum2 = sum2 + dice2;
			cout << "Player 2's total: " << sum2;
		}
		else
		{
			cout << "Player 2's total: " << sum2 << " (move not possible)" ;
		}
		
		if(sum2==20) //checking if player two's total has become 20
		{
			break;
		}
		cout << endl;
		cout << endl;
	}
	
	cout << endl;
	cout << endl;
	if(sum1==20) // deciding which player won?
	{
		cout << "Player 1 Won!!!" << endl;
	}
	else
	{
		cout << "Player 2 Won!!!" << endl;
	}
	
}