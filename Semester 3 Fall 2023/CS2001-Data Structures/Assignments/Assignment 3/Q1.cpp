#include <SFML/Graphics.hpp>
#include <cmath>
#include<iostream>
#include<string>
#define PI 3.14159265
#include<ctime>
#include<cstdlib>
#include<windows.h>
using namespace std;

template<class T> // template class
struct node
{
public:
	T data; // data variable
	node* next; // next pointer

	node() // constructor
	{
		next = nullptr;
	}
};

template<class T> // template class
class Queue
{
private:
	node<T>* front; // front pointer
	node<T>* rear; // rear pointer
	int size; // variable to store size of queue

public:
	Queue() // constructor
	{
		front = nullptr;
		rear = nullptr;
		size = 0;
	}

	bool IsEmpty() // function to check whether the queue is empty or not
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int getSize() // function to return the size of the queue
	{
		return size;
	}

	bool enqueue(const T& data) // function to add data at the rear of the queue
	{
		node<T>* temp = new node<T>; // make new node
		temp->data = data;
		temp->next = nullptr;
		if (size == 0) // case when queue is empty
		{
			front = temp;
			rear = temp;
		}
		else // case when queue has atleast one element
		{
			rear->next = temp;
			rear = temp;
		}
		
		size++; // update size
		return true;
	}
	
	bool dequeue(T& data) // function to remove data from front of queue
	{
		if (!IsEmpty()) // make sure the queue is not already empty
		{
			size--; // update size
			data = front->data;
			node<T>* temp = front;

			if (size == 0) // case when queue becomes empty after remove element at front
			{
				front = nullptr;
				rear = nullptr;
			}
			else // case when atleast one element in the queue after removing element from front
			{
				front = front->next;
			}
			delete temp;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	~Queue() // destructor
	{
		T data;
		while (!IsEmpty()) // remove each element from queue until it becomes empty
		{
			dequeue(data);
		}
	}
};

void nodeToBeginWith(Queue<int>& q, int n) // function that rotates the queue such that the soldier at the front is the one from which counting is to be started
{
	srand(time(0));
	int startPosition = (rand() % n) + 1; // get a random value for the starting position that is between 1 and n
	cout << "Starting with Soldier Number: " << startPosition << endl << endl;
	
	int position = 1; // current position
	int data;
	while (position < startPosition) // skip to the position from where counting is to be started
	{
		q.dequeue(data);
		q.enqueue(data);
		position++;
	}
}

void killKthPerson(Queue<int>& q, int k,int *&arr) // function to kill the kth soldier
{                      
	int counter = 1;
	int data;
	while (counter < k) // skip k-1 soldiers
	{
		q.dequeue(data);
		q.enqueue(data);
		counter++;
	}

	q.dequeue(data); // dequeue/kill the kth soldier
	arr[data - 1] = 0; // update alive status to false for the killed player, in the array
	cout << "Soldier Number " << data << " is killed!" << endl;
}

void JosephusProblem(int n, int k) // primary function to solve the JosephusProblem for values of n and k
{ 
	Queue<int> q; // make queue for soldiers
	
	int* arr = new int[n]; // make an array to hold the killed status of each soldier
	for(int i=0;i<n;i++)
	{
		arr[i] = 1; // all soldiers are alive initially
	}
	for (int i = 0; i < n; i++)
	{
		q.enqueue(i + 1); // store the soldier numbers in the queue
	}

	if (!q.IsEmpty()) // make sure the queue is not empty
	{
		nodeToBeginWith(q, n); // call nodeToBeginWith() function to start counting from a random soldier
		
		sf::RenderWindow window(sf::VideoMode(700, 600), "Josephus Problem"); // create a window
		sf::Event event; // make an event object
		
		float x; // the x factor for scaling the sprite
		float y; // the y factor for scaling the sprite
		float ringRadius; // varible to store the radius of the circle of soldiers
		int soldierNum = 0; // variable to hold soldier number
		float angleToskip = 360.0 / n; // the angle to skip when rotating the sprite
		int j = 0; // index for the array of killed status
		
		if(n>30) // case when soldiers are between 31 and 50
		{
			ringRadius = 250;
			x = 0.08;
			y = 0.08;
		}
		else if(n>20) // case when soldiers are between 21 and 30
		{
			ringRadius = 250;
			x = 0.13;
			y = 0.13;
		}
	    else if(n>9) // case when soldiers are between 10 and 20
		{
			ringRadius = 200;
			x = 0.15;
			y = 0.15;
		}
		else if(n>5) // case when soldiers are between 6 and 9
		{
			ringRadius = 100;
			x = 0.18;
			y = 0.18;
		}
		else // case when soldiers are between 2 and 5
		{
			ringRadius = 100;
			x = 0.2;
			y = 0.2;
		}
		
		sf::Texture alive;
		alive.loadFromFile("alive.jpeg");
		sf::Sprite aliveSoldier(alive); // sprite for alive soldier
		aliveSoldier.setScale(x, y); // adjust size of the sprite 
		aliveSoldier.setOrigin(aliveSoldier.getLocalBounds().width / 2.0, aliveSoldier.getLocalBounds().height / 2.0); // set the origin 
		
		sf::Texture dead;
		dead.loadFromFile("dead.jpeg");
		sf::Sprite deadSoldier(dead); // sprite for the dead soldier
		deadSoldier.setScale(x, y); // adjust size of the sprite
		deadSoldier.setOrigin(deadSoldier.getLocalBounds().width / 2.0, deadSoldier.getLocalBounds().height / 2.0); // set the origin 
		
		while (window.isOpen()) // the loop runs while the window is open
		{
			while (window.pollEvent(event)) // check for any events that happened
			{
				if (event.type == sf::Event::Closed) // if there is a window close event then close the window 
					window.close();
			}
			
			window.clear(); // clear the window before printing the next frame
			
			j = 0; // reset index for the array of killed status of the soldiers
			for (float i = 270; i < 630; i += angleToskip) // loop runs n number of times
			{
				if(arr[j]==0) // check killed status for current soldier
				{
					// formula to tranlate the sprite so that it fits in a circle
					                                           // translation of the y coordinate                                               // translation of the x coordinate
					deadSoldier.setPosition(static_cast<float>(window.getSize().x / 2.0 + ringRadius * cos(i * PI / 180.0)), static_cast<float>(window.getSize().y / 2.0 + ringRadius * sin(i * PI / 180.0)));
					window.draw(deadSoldier); // draw the sprite at the translated position
				}
				else
				{
					// formula to tranlate the sprite so that it fits in a circle
															   // translation of the y coordinate                                                // translation of the x coordinate
					aliveSoldier.setPosition(static_cast<float>(window.getSize().x / 2.0 + ringRadius * cos(i * PI / 180.0)), static_cast<float>(window.getSize().y / 2.0 + ringRadius * sin(i * PI / 180.0)));
					window.draw(aliveSoldier);  // draw the sprite at the translated position
				}
				j++; // move to next index position
			}
			
			window.display(); // print the current frame
			Sleep(4000); // make delay of some milliseconds to show the transition from one frame to the other
			
			if((q.getSize())!=1) // kill the kth soldier if the queue has more than one soldier
			{
				killKthPerson(q, k, arr); // call the killKthPerson()
			}
			else
			{
				q.dequeue(soldierNum); // dequeue the winner soldier
				cout<<endl << "The winner is Soldier Number: " << soldierNum << endl;
				system("pause"); 
				window.close(); // close the window
			}
		}
	}
	delete[] arr; // delete the array of killed status for each soldier
}

int main()
{
	int n = 0;
	int k = 0;
	cout << "---------------------The Josephus Problem---------------------" << endl;
	do // validate the value of n 
	{
		cout << "Enter the value for n (min value is 2 and max value is 50): ";
		cin >> n;
	} while ((n < 2) || (n > 50));
	do // validate the value of k
	{
		cout << "Enter the value for k (min value is 2): ";
		cin >> k;
	} while (k < 2);
	cout << endl;
	
	JosephusProblem(n, k); // the JosephusProblem() function
	
	cout << endl;
	system("pause");
	return 0;
}

