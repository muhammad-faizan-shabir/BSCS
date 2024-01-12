#include<iostream>
using namespace std;

template<class T> //template class
class queue
{
	struct node // node to store data and next pointer
	{
		T data;
		node* next;
		node() // constructor
		{
			next = nullptr;
		}
	};
	
	T minElement; // variable to hold minimum element of queue
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

		if (rear == nullptr) // case when queue is empty
		{
			minElement = data;
			rear = temp;
			front = temp;
		}
		else // case when queue is not already empty
		{
			rear->next = temp;
			rear = temp;
			
			if(data<minElement) // update the minimum element variable if the data being added is the smallest
			{
				minElement = data;
			}
		}
	}

	T dequeue() // function to remove data from queue
	{
		if (!isEmpty()) // make sure queue is not already empty
		{
			T data; // temporary variable to hold data to be returned
			node* temp = front; // save front 
			data = temp->data; // save data of front
			front = front->next; // point front pointer to next element
			delete temp; // delete original front
			size--; // decrement size

			if (front == nullptr) // case when last element is removed from queue and queue becomes empty
			{
				rear = nullptr;
			}
			
			if (data == minElement) // if the data being removed is the minimum element then find the new minimum element in the queue
			{
				updateMinElement();
			}
			return data;
		}
		return 0;
	}

	bool getMin(T& min) // function to get minimum element of queue in constant time
	{
		if (!isEmpty())
		{
			min = minElement;
			return true;
		}
		else
		{
			return false;
		}
	}

	void updateMinElement() // function that finds the new minimum element if the current minimum element is removed from the queue
	{
		if(!isEmpty())
		{
			node* current = front;
			minElement = current->data;
			current = current->next;
			
			while(current!=nullptr)
			{
				if(current->data<minElement)
				{
					minElement = current->data;
				}
				current = current->next;
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
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void print() // function to print the queue
	{
		node* current = front;
		cout << "<FrontOfQueue> ";
		while (current != nullptr)
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
	cout << "After insering 5,3,1,8,9 in queue: " << endl;
	q1.enqueue(5);
	q1.enqueue(3);
	q1.enqueue(1);
	q1.enqueue(8);
	q1.enqueue(9);
	q1.print(); // print queue
	int min;
	q1.getMin(min); // get minimum element from queue in constant time
	cout << "The Minimum Element of the queue above is: " << min << endl;
	cout <<"-----------------------------------------" << endl;

	cout << "After removing three elements from queue:" << endl;
	q1.dequeue();
	q1.dequeue();
	q1.dequeue();
	q1.print(); // print queue
	q1.getMin(min); // get minimum element from queue in constant time
	cout << "The Minimum Element of the queue above is: " << min << endl;
	
	cout << endl;
	system("pause");
	return 0;
}