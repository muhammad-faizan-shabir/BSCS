#include <iostream>
using namespace std;

bool exists(int data[][6], int rows1, int cols1, int pattern[][3], int rows2, int cols2)
{
	bool flag = false;
	
	if((rows2*cols2)>(rows1*cols1))
	{
		return flag;
	}
	else
	{
		int count = 0;
		int lowCol = 0;
		int upCol = cols2-1;
		int lowRow = 0;
		int upRow = rows2-1;
	
		for(;upRow<rows1;)
		{
			cout << lowRow << "-" << upRow << " " << lowCol << "-" << upCol << "  " <<count << endl;
		
			count = 0;
			int x = 0;
			int y = 0;
			
			for (int i = lowRow; i <= upRow; i++)
			{
				y = 0;
				for (int j = lowCol; j <= upCol; j++)
				{
					if((data[i][j] != pattern[x][y]))
					{
						
					}
					else
					{
						count++;
						if(count==(rows2*cols2))
						{
							flag = true;
						}
					}
					y++;
				}
				x++;
			}
			
			lowCol = lowCol + 1;
			upCol = upCol + 1;
			if (upCol > cols1 - 1)
			{
				lowRow = lowRow + 1;
				upRow = upRow + 1;
				lowCol = 0;
				upCol = cols2 - 1;
			}
		}
		return flag;
	}
}

int main()
{
	int data[10][6] = { {8,7,9,2,4,1},
		                {6,3,1,9,4,7},
		                {2,6,3,4,5,9},
		                {7,5,3,4,5,2},
		                {8,1,3,4,5,9},
		                {4,7,3,6,7,9},
		                {1,9,3,7,4,8},
		                {6,3,2,4,5,7},
		                {1,7,3,9,2,7},
		                {2,1,3,9,4,9} };

	int pattern[3][3] = { {3,4,5},
		                  {3,4,5},
		                  {3,4,5} };

	bool flag = exists(data, 10,6,pattern,3,3);
	cout << endl;
	cout << flag;
}