#include<iostream>
using namespace std;

class queue
{
	int MaxSize;// max Queue size
	int front, rear; // front and rear pointers
	int* QueueArray; // array pointer
	int size;// current size of queue
public:
	queue(int s = 10) // constructor
	{
		if (s <= 0)
		{
			MaxSize = 10;
		}
		else
		{
			MaxSize = s;
		}
		
		QueueArray = new int[MaxSize];
		size = 0;
		rear = -1;// points to the last element
		front = 0;// points to first element
	}

	bool isFull()  // function to tell whether queue is full or not
	{ 
		return MaxSize == size; 
	}

	bool isEmpty() // function to tell wheteher queue is empty or not
	{ 
		return size == 0; 
	}

	bool add(int n) // function to add data to queue
	{
		if (!isFull()) {
			rear = (rear + 1) % MaxSize; // circular increment of rear pointer
			QueueArray[rear] = n;
			size++;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool remove(int& n) // function to remove data from queue
	{
		if (!isEmpty()) {
			n = QueueArray[front];
			front = (front + 1) % MaxSize; // circular increment of front pointer
			size--;
			return true;
		}
		else
		{
			return false;
		}
	}

	void print() // function to print the queue
	{
		if(!isEmpty())
		{
			for (int i = 0; i < MaxSize; i++)
			{
				cout << QueueArray[i] << " ";
			}
			cout << endl;
			cout << "(Front index: " << front << ") " << "(Rear index: " << rear <<")"<< endl;
		}
	}

	bool isPalindrome() // function to check if the queue forms a palindrome
	{
		if (!isEmpty())
		{
			int tempFront = front; // move front pointer to a temporary pointer
			int tempRear = rear; // move rear pointer to a temporary pointer
			
			for (int i = 0; i < size / 2; i++) // loop runs half the current size of the queue
			{
				if (QueueArray[tempFront] != QueueArray[tempRear]) // check elements at oppsite ends one by one
				{
					return false; // return false if a mismatch
				}
				
				tempFront = (tempFront + 1) % MaxSize; // circular increment of temporary front pointer
				tempRear = tempRear - 1; // circular decrement of temporary rear pointer
				if (tempRear < 0)
				{
					tempRear = MaxSize - 1;
				}
			}
			return true; // return true if all elements at opposite ends match
		}
		else
		{
			return false; // retrun false if queue is empty
		}
	}

	~queue() // destructor
	{
		delete[] QueueArray;
	}
};

int main()
{
	queue q1(5);
	cout << "After inserting 1,2,3,2,1 in the queue 1:" << endl;
	q1.add(1);
	q1.add(2);
	q1.add(3);
	q1.add(2);
	q1.add(1);
	q1.print();
	bool palindrome;
	palindrome = q1.isPalindrome();
	if(palindrome==true)
	{
		cout << "The queue above forms a palindrome" << endl;
	}
	else
	{
		cout << "The queue above does NOT form a palindrome" << endl;
	}
	cout << "-----------------------------------------" << endl;

	queue q2(4);
	cout << "After inserting 1,6,2,8 in queue 2:" << endl;
	q2.add(1);
	q2.add(6);
	q2.add(2);
	q2.add(8);
	q2.print();
	palindrome = q2.isPalindrome();
	if (palindrome == true)
	{
		cout << "The queue above forms a palindrome" << endl;
	}
	else
	{
		cout << "The queue above does NOT form a palindrome" << endl;
	}
	cout <<"-----------------------------------------" << endl;

	queue q3(4);
	cout << "After inserting 1,2,2,1 in queue 3:" << endl;
	q3.add(1);
	q3.add(2);
	q3.add(2);
	q3.add(1);
	q3.print();
	palindrome = q3.isPalindrome();
	if (palindrome == true)
	{
		cout << "The queue above forms a palindrome" << endl;
	}
	else
	{
		cout << "The queue above does NOT form a palindrome" << endl;
	}
	cout << "-----------------------------------------" << endl;
	
	cout << endl;
	system("pause");
	return 0;
}

