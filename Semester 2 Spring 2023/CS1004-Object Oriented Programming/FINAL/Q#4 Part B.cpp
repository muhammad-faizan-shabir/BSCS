#include<iostream>
using namespace std;

int count_friends(int ID) 
{
	int i = 0;
	if (num_users>ID)
		for (; friends[ID][i] != -1; i++);
	return i;
}

bool is_friends(int i, int j)
{
	//bool flag = false;
	for (int k = 0; friends[i][k] != -1; k++) 
	{
		if (friends[i][k] == j)
			return true;
	}
	return false;
}

float* comp_CC()
{
	float* cc = new float[num_users];
	//compute the CC of user u
	for (int u = 0; u < num_users; u++) 
	{
		cc[u] = 0;
		int count = count_friends(u);
		int pairs = 0;
		for (int i = 0; friends[u][i] != -1; i++) 
		{
			for (int j = i + 1; friends[u][j] != -1; j++) 
			{
				if (is_friends(friends[u][i], friends[u][j]))
					pairs++;
			}
		}
		if (pairs > 0)
			cc[u] = (2.0 * pairs) / (count * (count - 1));
	}
	return cc;
}