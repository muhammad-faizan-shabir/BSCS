#include<iostream>
using namespace std;

class Player
{
	char*playername;
	int score;
	int ballsPlayed;
	int matchesPlayed;
public:
	Player(char*name="",int score=0,int ballsPlayed=0,int matchesPlayed=0)
	{
		playername = name;
		this->score = score;
		this->ballsPlayed = ballsPlayed;
		this->matchesPlayed = matchesPlayed;
	}
	virtual double calculateAverage();
	virtual void display()
	{
		cout << "Palyer name: " << playername << " Score: " << score << " BallsPlayed: " << ballsPlayed << " MatchesPlayed: " << matchesPlayed << endl;
	}
};

class Batsman: public Player
{
	char*battingStyle;
	int totalScore;
	int noOfTimesBowled;
public:
	Batsman(char*name = "", int score = 0, int ballsPlayed = 0, int matchesPlayed = 0, char*style = "", int totalScore = 0, int timesBowled = 0) : Player(name,score,ballsPlayed,matchesPlayed)
	{
		battingStyle = style;
		this->totalScore = totalScore;
		noOfTimesBowled = timesBowled;
	}
	double calculateAverage()
	{
		return ((double)totalScore) / noOfTimesBowled;
	}

	void display()
	{
		cout << "Player Type : Batsman, " << "BattingStyle: " << battingStyle << ", TotalScore: " << totalScore << ", NoOfTimesBowled: " << noOfTimesBowled << endl;
	}
};

class Bowler: public Player
{
	char*bowlingStyle;
	int totalWickets;
	int totalRunsConceded;
public:
	Bowler(char*name = "", int score = 0, int ballsPlayed = 0, int matchesPlayed = 0, char*style = "", int wickets = 0, int totalRuns = 0) : Player(name, score, ballsPlayed, matchesPlayed)
	{
		bowlingStyle = style;
		totalWickets = wickets;
		totalRunsConceded = totalRuns;
	}
	double calculateAverage()
	{
		return ((double)totalRunsConceded) / totalWickets;
	}

	void display()
	{
		cout << "Player Type: Bowler, " << "BowlingStyle: " << bowlingStyle << ", TotalWickets: " << totalWickets << ", TotalRunsConceded: " << totalRunsConceded << endl;
	}
};



int main()
{
	Batsman b1("Ali", 23, 160, 5, "Right-Hand", 180, 2);
	b1.display();
	cout << b1.calculateAverage() << endl;
	Bowler b2("Sam", 10, 170, 7, "Fast-bowler", 10, 210);
	b2.display();
	cout << b2.calculateAverage() << endl;

	Player**player_arr = new Player*[2];

	player_arr[0] = &b1;
	player_arr[1] = &b2;

	for (int i = 0; i < 2; i++)
	{
		player_arr[i]->display();
		cout << player_arr[i]->calculateAverage() << endl;
	}
	cout << endl;
	system("pause");
}