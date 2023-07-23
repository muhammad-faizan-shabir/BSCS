#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
int main()
{
	int pileSize; // total number of marbles
	bool firstTurn; // 0 for computer's turn and 1 for user's turn
	int smartORstupid; // 0 for stupid mode and 1 for smart mode
	int marblesEntered; // marbles picked by the user or the computer
	
	srand(time(0));
	
	pileSize = (rand() % 91) + 10;// random value of marbles between 10 and 100
	
	cout << "Tossing......." << endl;
	firstTurn = rand() % 2; // random value which will be either 1 or 0

	if(firstTurn==1) // prompting whose turn is first
	{
		cout << "User will take first turn" << endl;
	}
	else
	{
		cout << "Computer will take first turn" << endl;
	}

	smartORstupid = rand() % 2; // random value which will be either 1 or 0

	if(smartORstupid==1) // prompting mode of computer which will be either smart or stupid
	{
		cout << "Computer will play in SMART mode" << endl << endl;
	}
	else
	{
		cout << "Computer will play in STUPID mode" << endl << endl;
	}
	
	cout << "Total number of marbles are: " << pileSize << endl; // prompting initial number of marbles
	
	for(;true;) // loop will run until it breaks
	{
		if(firstTurn==1) // for user's turn
		{
			cout << "User's turn, enter number of marbles: ";
			cin >> marblesEntered;
			cout << endl;

			for(;!((marblesEntered>=1)&&(marblesEntered<=(pileSize/2)));) // making sure marbles entered by user are valid
			{
				cout << "Please enter valid no of marbles i.e between 1 and " << pileSize / 2 << ": ";
				cin >> marblesEntered;
				cout << endl;
			}
		}
		else // for computer's turn
		{
			cout << "Computer's turn: ";
			if(smartORstupid==0) // for stupid mode
			{
				marblesEntered = (rand() % (pileSize / 2)) + 1;// picking marbles between 1 and half of total marbles
				cout << marblesEntered << endl << endl;
			}
			else // for smart mode
			{
				bool integer = false; // flag to check whether a number is integer

				int temp = (log2(pileSize+1)) / 1; // checking whether the size of the pile is currently one less than a power of two

				if((log2(pileSize + 1))==temp) // checking whether the size of the pile is currently one less than a power of two
				{
					integer = true;
				}

				if(integer== true) // when size of the pile is already currently one less than a power of two
				{
					marblesEntered = (rand() % (pileSize / 2)) + 1;
					cout << marblesEntered << endl << endl;
				}
				else  // making sure that  the size of the pile is currently one less than a power of two
				{
					integer = false;
					
					marblesEntered = pileSize / 2;

					for(;integer==false;marblesEntered--)  // making sure that  the size of the pile is currently one less than a power of two
					{
						int marblesLeft = pileSize - (marblesEntered);

						temp = log2(marblesLeft + 1)/1;
						if((log2(marblesLeft + 1))==temp)
						{
							integer = true;
						}
					}

					marblesEntered++;
					cout << marblesEntered << endl << endl;

				}
				
			}
		}

		pileSize = pileSize - marblesEntered; // updating the total number of marbles
		cout << "Total number of marbles left are: " << pileSize << endl;
		
		if((pileSize==1)&&(firstTurn==0)) // checking whether the computer wins
		{
			cout << "As only one marble is left for YOU to pick so YOU LOOSE and COMPUTER WINS" << endl;
			break; // exiting loop when computer wins
		}
		else if((pileSize == 1) && (firstTurn == 1)) // checking whether the user wins
		{
			cout << "As only one marble is left for COMPUTER to pick so COMPUTER LOOSES and YOU WIN" << endl;
			break; // exiting loop when computer wins
		}

		firstTurn = !(firstTurn); // changing turn from one to the other
	}

}