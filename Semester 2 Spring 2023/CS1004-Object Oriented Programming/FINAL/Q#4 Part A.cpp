#include<iostream>
using namespace std;

int count_friends(int ID) 
{
	int i = 0;
	if (num_users>ID)
	{
		for (; friends[ID][i] != -1; i++)
		{
		}
	}
	return i;
}

void add_Friend(int ID, int friend_ID) 
{
	int count = count_friends(ID);
	int* temp = new int[count + 2];
	for (int i = 0; friends[ID][i] != -1; i++) 
	{
		temp[i] = friends[ID][i];
	}
	temp[count] = friend_ID;
	temp[count + 1] = -1;
	delete[]friends[ID];
	friends[ID] = temp;
}

void add_user(int* frnd, int size) 
{
	int** temp = new int*[num_users + 1];
	for (int i = 0; i < num_users; i++)
	{
		temp[i] = friends[i];
	}
	delete[] friends;
	friends = temp;
	friends[num_users] = new int[size + 1];
	for (int j = 0; j < size; j++) 
	{
		friends[num_users][j] = frnd[j];
		add_Friend(frnd[j], num_users);
	}
	friends[num_users][size] = -1;
	num_users++;
}