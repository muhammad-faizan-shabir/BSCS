#include<iostream>
#include<string>
using namespace std;

template<class T> // template class
class Queue
{
private:
	struct node
	{
	public: 
		T data; // variable to store data
		node* next; // next pointer

		node()
		{
			next = nullptr;
		}
	};

	node* front; // front of queue pointer
	node* rear; // rear of queue pointer
	int size; // variable to store size of the queue
public:
	Queue() // constructor
	{
		front = nullptr;
		rear = nullptr;
		size = 0;
	}

	bool IsEmpty() // function to tell whether the queue is empty or not
	{
		if (front == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	int getSize() // function that returns the size of the queue
	{
		return size;
	}

	bool enqueue(const T& data) // function to add data to the front of queue
	{
		node* temp =  new node; // maek new node
		temp->data = data; // insert data
		temp->next = nullptr; // set the next pointer to nullptr

		if (rear == nullptr) // case when the queue is empty
		{
			front = temp;
			rear = temp;
		}
		else // case when there is atleast one element in the queue
		{
			rear->next = temp; // rear node points to new node
			rear = temp; // update rear
		}
		size++; // update size
		return true;
	}
	
	bool dequeue(T& data) // function to remove data from front of the queue
	{ 
		if (!IsEmpty()) // make sure that the queue is not already empty
		{
			data = front->data; // get data from front of queue
			node* temp = front;
			front = front->next; // update front pointer
			delete temp; // delete the front node
			
			if (front == nullptr) // case when queue becomes empty of removing node from front
			{
				rear = nullptr;
			}
			size--; // update size
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void print() // function to print the queue
	{
		cout << "<Front>";
		node* current = front;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << "<Rear>" << endl;
	}

	~Queue() // destructor
	{
		T data;
		while (!IsEmpty()) // remove nodes from start of queue until the queue becomes empty
		{
			dequeue(data);
		}
	}
};

void RadixSortForIntegers(Queue<int>& q, int n, int k) // function to perform radix sort on integers
{ 
	Queue<int> queues[10]; // make an array of 10 queues
	int key = 0;  // variable to hold key
	int queueNum = 0; // variable to hold queue number that ranges from 0-9
	
	for (int i = 0; i < k; i++) // loop runs k times since each key has k digits
	{
		for (int j = 0; j < n; j++) // loop runs n times i.e the size of the queue times
		{
			q.dequeue(key); // get a key from queue
			queueNum = key;
			
			for(int l=0;l<i;l++)
			{
				queueNum = queueNum / 10; // get to the required place digit
			}
			
			queueNum = queueNum % 10; // get the required place digit by taking mod by 10
			queues[queueNum].enqueue(key); // put the key in the queue corresponding to the place digit
		}

		for (int j = 0; j < 10; j++) // loop runs 10 times since there are 10 queues
		{
			while (!queues[j].IsEmpty()) // empty each of the 10 queues
			{
				queues[j].dequeue(key); // get data from queue
				q.enqueue(key); // put data into the original queue
			}
		}
	}
}

int getQueueNumber(char alpha) // function to tell bucket number for alphbets ranging from (a-z) or (A-Z)
{
	if(alpha>='A'&&alpha<='Z')
	{
		return alpha - 65; // queue number for alphabets A-Z
	} 
	else if(alpha>='a'&&alpha<='z')
	{
		return alpha - 97; // queue number for alphabets a-z
	}
	else
	{
		return -1; // return -1 if the alphabet is not in the range (a-z) or (A-Z)
	}
}

void RadixSortForStrings(Queue<string>& q, int n, int k) // function to perform radix sort on strings
{
	Queue<string> queues[26]; // make array of 26 queues
	string key; // variable to store the key
	int queueNum = 0; // variable to hold queue number that ranges from 0-25
	int index = 0; // index used to access individual alphabets in a string
	
	for (int i = 0; i < k; i++) // loop runs k times since each key has k alphabets
	{ 
		for (int j = 0; j < n; j++) // loop runs n times i.e the size of the queue times
		{
			q.dequeue(key); // get a key/string from the queue
			index = key.size() - 1 - i; // caluclate the index of the alphabet to be examined
			
			if(index >= 0) // case when the index is not out of bounds
			{
				queueNum = getQueueNumber(key[index]); // get respective queue number for the alphabet
				if(queueNum==-1) // case when the alphabet in not in the range (a-z) or (A-Z)
				{
					throw -1; // throw an exception
				}
				queues[queueNum].enqueue(key); // put the key in the respective queue
			}
			else // case when one of the strings has length less than k
			{
				throw -2; // throw wn exception
			}
		}

		for (int j = 0; j < 26; j++) // loop runs 26 times since there are 26 queues
		{
			while (!queues[j].IsEmpty()) // empty each of the 26 queues
			{
				queues[j].dequeue(key); // get data from queue
				q.enqueue(key); // put data into the original queue
			}
		}
	}
}

int main()
{
	Queue<int> q; // make a queue of integers 
	int data = 329;
	q.enqueue(data);
	data = 457;
	q.enqueue(data);
	data = 657;
	q.enqueue(data);
	data = 839;
	q.enqueue(data);
	data = 436;
	q.enqueue(data);
	data = 720;
	q.enqueue(data);
	data = 355;
	q.enqueue(data);
	cout << "The integer queue before being sorted:" << endl;
	q.print(); // print the queue

	RadixSortForIntegers(q, q.getSize(), 3); // call radix sort function for integers
	cout << "The integer queue after being sorted:" << endl;
	q.print(); // print the queue
	cout << endl;

	Queue<string> s; // make a queue for strings
	string key;
	key = "chat";
	s.enqueue(key);
	key = "love";
	s.enqueue(key);
	key = "book";
	s.enqueue(key);
	key = "bass";
	s.enqueue(key);
	key = "easy";
	s.enqueue(key);
	key = "idea";
	s.enqueue(key);
	key = "home";
	s.enqueue(key);
	key = "time";
	s.enqueue(key);
	key = "word";
	s.enqueue(key);
	key = "good";
	s.enqueue(key);
	cout << "The string queue before being sorted:" << endl;
	s.print(); // print the queue
	try
	{
		RadixSortForStrings(s, s.getSize(), 4); // call radix sort function for queues
		cout << "The string queue after being sorted:" << endl;
		s.print(); // print the queue
		cout << endl;
	}
	catch(int x) // catch any thrown exception
	{
		if(x==-1) // excpetion 1
		{
			cout << "Error: There is some character other than a-z in one of the strings" << endl;
		}
		else // exception 2
		{
			cout << "Error: There is a string that has length less than k" << endl;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
