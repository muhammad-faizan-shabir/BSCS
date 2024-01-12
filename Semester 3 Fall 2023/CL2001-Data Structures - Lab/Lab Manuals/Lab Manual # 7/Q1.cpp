#include<iostream>
using namespace std;
 
template<class T> //template class
class queue
{
	struct node // node to store data and next pointer
	{
		T data;
		node *next;
		node() // constructor
		{
			next = nullptr;
		}
	};

	node* front; // pointer that points at front element of queue
	node* rear; // pointer that points at rear element of queue
	int size; // variable to hold current size of queue
public:
	queue() // constructor
	{
		front = nullptr;
		rear = nullptr;
		size = 0;
	}

	void enqueue(T const data) // function to add data in queue
	{
		node* temp = new node; // make new node
		temp->data = data; // insert data 
		temp->next = nullptr; 
		size++; // increment current size
		
		if(rear==nullptr) // case when queue is empty
		{
			rear = temp;
			front = temp;
		} 
		else // case when queue is not already empty
		{ 
			rear->next = temp;
			rear = temp;
		}
	}
	
	void dequeue() // function to remove data from queue
	{
		if(!isEmpty()) // make sure queue is not already empty
		{
			node* temp = front;
			front = front->next; // point front pointer to next element
			delete temp; // delete original front
			size--; // decrement size
			
			if(front==nullptr) // case when last element is removed from queue and queue becomes empty
			{
				rear = nullptr;
			}
		}
	}

	bool isFull()
	{
		return false; // since this queue is implemented using a linked list so it never gets full and so this function always returns false
	}

	int Size() // function that return current size of queue
	{
		return size;
	}

	bool isEmpty() // function that tells whether queue is empty or not
	{
		if(size==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	T Front() // function that returns element at front of queue
	{
		if(!isEmpty())
		{
			return front->data;
		}
		else
		{
			return 0;
		}
	}

	T Rear() // function that returns element at rear of queue
	{
		if(!isEmpty())
		{
			return rear->data;
		}
		else
		{
			return 0;
		}
	}
	
	void print() // function to print the queue
	{
		node* current = front;
		cout << "<FrontOfQueue> ";
		while(current!=nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << "<RearOfQueue>";
		cout << endl;
	}

	~queue() //destructor
	{
		if (!isEmpty())
		{
			node* current = front;
			node* ahead = nullptr;
			while (current != nullptr)
			{
				ahead = current->next;
				delete current;
				current = ahead;
			}
		}
	}
};

int main()
{
	queue<int> q1; // make an object of queue class
	cout << "After insering 1,2,3,4,5 in queue: " << endl;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.print();
	cout << "Size of the queue above is: " << q1.Size() << endl;
	cout << endl;
	
	cout << "After removing two elements from queue:" << endl;
	q1.dequeue();
	q1.dequeue();
	q1.print();
	cout << "Size of the queue above is: " << q1.Size() << endl;
	cout << endl;
	
	cout << "After adding 6,9 in queue:" << endl;
	q1.enqueue(6);
	q1.enqueue(9);
	q1.print();
	cout << "Size of the queue above is: " << q1.Size() << endl;
	cout << "The element at the front of queue above  is: " << q1.Front() << endl;
	cout << "The element at the rear of queue above is: " << q1.Rear() << endl;
 	
	cout << endl;
	system("pause");
	return 0;
}