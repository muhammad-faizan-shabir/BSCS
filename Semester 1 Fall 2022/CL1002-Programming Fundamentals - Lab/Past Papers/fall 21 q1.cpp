#include <iostream>
using namespace std;
void trim(char arr[])
{
	int length = 0;
	int startspaces = 0;
	int endspaces = 0;
	int index = 0;
	
	for(int i=0;arr[i]!='\0';i++)
	{
		length++;
	}
	
	for(int i=0;arr[i]==' '; i++)
	{
		startspaces++;
	}
	
	for(int i=length-1;arr[i]==' ';i--)
	{
		endspaces++;
	}

	if(startspaces>0)
	{
		for(int i=startspaces;i<(length-endspaces);i++)
		{
			arr[index] = arr[i];
			index++;
		}
		arr[index] = '\0';
	}

	if((startspaces==0)&&(endspaces>0))
	{
		arr[length - endspaces] = '\0';
	}
}

void RemoveExtraSpace(char arr[])
{
	int index=0;
	char temp[101];
	int i;
	for(i=0;arr[i]!='\0';i++)
	{
		temp[i] = arr[i];
	}
	temp[i] = '\0';

	for(int j=0;temp[j]!='\0';j++)
	{
		if(temp[j]!=' ')
		{
			arr[index] = temp[j];
			index++;
		}
		else
		{
			arr[index] = ' ';
			index++;
			for(;arr[j]==' ';j++)
			{
			}
			j--;
		}
	}
	arr[index] = '\0';
}

void DisplayCountofAlphabets(char arr[])
{
	int countA = 0;
	int countB = 0;
	int countC = 0;
	int countD = 0;
	int countE = 0;
	int countF = 0;
	int countG = 0;
	int countH = 0;
	int countI = 0;
	int countJ = 0;
	int countK = 0;
	int countL = 0;
	int countM = 0;
	int countN = 0;
	int countO = 0;
	int countP = 0;
	int countQ = 0;
	int countR = 0;
	int countS = 0;
	int countT = 0;
	int countU = 0;
	int countV = 0;
	int countW = 0;
	int countX = 0;
	int countY = 0;
	int countZ = 0;

	for(int i=0;arr[i]!='\0';i++)
	{
		if((arr[i]=='A')||(arr[i]=='a'))
		{
			countA++;
		}
		if ((arr[i] == 'B') || (arr[i] == 'b'))
		{
			countB++;
		}
		if ((arr[i] == 'C') || (arr[i] == 'c'))
		{
			countC++;
		}
		if ((arr[i] == 'D') || (arr[i] == 'd'))
		{
			countD++;
		}
		if ((arr[i] == 'E') || (arr[i] == 'e'))
		{
			countE++;
		}
		if ((arr[i] == 'F') || (arr[i] == 'f'))
		{
			countF++;
		}
		if ((arr[i] == 'G') || (arr[i] == 'g'))
		{
			countG++;
		}
		if ((arr[i] == 'H') || (arr[i] == 'h'))
		{
			countH++;
		}
		if ((arr[i] == 'I') || (arr[i] == 'i'))
		{
			countI++;
		}
		if ((arr[i] == 'J') || (arr[i] == 'j'))
		{
			countJ++;
		}
		if ((arr[i] == 'K') || (arr[i] == 'k'))
		{
			countK++;
		}
		if ((arr[i] == 'L') || (arr[i] == 'l'))
		{
			countL++;
		}
		if ((arr[i] == 'M') || (arr[i] == 'm'))
		{
			countM++;
		}
		if ((arr[i] == 'N') || (arr[i] == 'n'))
		{
			countN++;
		}
		if ((arr[i] == 'O') || (arr[i] == 'o'))
		{
			countO++;
		}
		if ((arr[i] == 'P') || (arr[i] == 'p'))
		{
			countP++;
		}
		if ((arr[i] == 'Q') || (arr[i] == 'q'))
		{
			countQ++;
		}
		if ((arr[i] == 'R') || (arr[i] == 'r'))
		{
			countR++;
		}
		if ((arr[i] == 'S') || (arr[i] == 's'))
		{
			countS++;
		}
		if ((arr[i] == 'T') || (arr[i] == 't'))
		{
			countT++;
		}
		if ((arr[i] == 'U') || (arr[i] == 'u'))
		{
			countU++;
		}
		if ((arr[i] == 'V') || (arr[i] == 'v'))
		{
			countV++;
		}
		if ((arr[i] == 'W') || (arr[i] == 'w'))
		{
			countW++;
		}
		if ((arr[i] == 'X') || (arr[i] == 'x'))
		{
			countX++;
		}
		if ((arr[i] == 'Y') || (arr[i] == 'y'))
		{
			countY++;
		}
		if ((arr[i] == 'Z') || (arr[i] == 'z'))
		{
			countZ++;
		}
	}

	if(countA>0)
	{
		cout << "A appears " << countA << " times" << endl;
	}
	if (countB > 0)
	{
		cout << "B appears " << countB << " times" << endl;
	}
	if (countC > 0)
	{
		cout << "C appears " << countC << " times" << endl;
	}
	if (countD > 0)
	{
		cout << "D appears " << countD << " times" << endl;
	}
	if (countE > 0)
	{
		cout << "E appears " << countE << " times" << endl;
	}
	if (countF > 0)
	{
		cout << "F appears " << countF << " times" << endl;
	}
	if (countG > 0)
	{
		cout << "G appears " << countG << " times" << endl;
	}
	if (countH > 0)
	{
		cout << "H appears " << countH << " times" << endl;
	}
	if (countI > 0)
	{
		cout << "I appears " << countI << " times" << endl;
	}
	if (countJ > 0)
	{
		cout << "J appears " << countJ << " times" << endl;
	}
	if (countK > 0)
	{
		cout << "K appears " << countK << " times" << endl;
	}
	if (countL > 0)
	{
		cout << "L appears " << countL << " times" << endl;
	}
	if (countM > 0)
	{
		cout << "M appears " << countM<< " times" << endl;
	}
	if (countN > 0)
	{
		cout << "N appears " << countN << " times" << endl;
	}
	if (countO > 0)
	{
		cout << "O appears " << countO << " times" << endl;
	}
	if (countP > 0)
	{
		cout << "P appears " << countP << " times" << endl;
	}
	if (countQ > 0)
	{
		cout << "Q appears " << countQ<< " times" << endl;
	}
	if (countR > 0)
	{
		cout << "R appears " << countR << " times" << endl;
	}
	if (countS > 0)
	{
		cout << "S appears " << countS << " times" << endl;
	}
	if (countT > 0)
	{
		cout << "T appears " << countT << " times" << endl;
	}
	if (countU > 0)
	{
		cout << "U appears " << countU << " times" << endl;
	}
	if (countV > 0)
	{
		cout << "V appears " << countV << " times" << endl;
	}
	if (countW > 0)
	{
		cout << "W appears " << countW << " times" << endl;
	}
	if (countX > 0)
	{
		cout << "X appears " << countX << " times" << endl;
	}
	if (countY > 0)
	{
		cout << "Y appears " << countY << " times" << endl;
	}
	if (countZ > 0)
	{
		cout << "Z appears " << countZ << " times" << endl;
	}
}
int main()
{
	char sentence[101];
	cout << "Please enter a sentence upto 100 characters long" << endl;
	cin.getline(sentence, 101);
	trim(sentence);
	cout << "After calling trim: " << endl;
	cout << sentence << endl;
	
	RemoveExtraSpace(sentence);
	cout << "After calling RemoveExtraSpace: " << endl;
	cout << sentence << endl;
	
	DisplayCountofAlphabets(sentence);
}