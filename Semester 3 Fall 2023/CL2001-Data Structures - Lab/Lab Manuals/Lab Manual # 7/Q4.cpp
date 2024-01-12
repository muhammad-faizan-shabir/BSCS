#include<iostream>
#include<string>
using namespace std;

struct node // node to store all the data about the customer
{
	int customer_id;
	string transaction_type;
	int amount;
	int balance;
	node* next;
	
	node(int id=0,string transaction="", int amt=0, int bl=0) // constructor
	{
		customer_id = id;
		transaction_type = transaction;
		amount = amt;
		balance = bl;
		next=nullptr;
	}
};
 
class queue
{
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

	void enqueue(node &data) // function to add data in queue
	{
		node* temp = new node; // make new node
		temp->customer_id = data.customer_id;           // insert data 
		temp->transaction_type = data.transaction_type; // insert data 
		temp->amount = data.amount; // insert data 
		temp->balance = data.balance; // insert data 
		temp->next = nullptr;// insert data 
		size++; // increment current size

		if (rear == nullptr) // case when queue is empty
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
		if (!isEmpty()) // make sure queue is not already empty
		{
			node* temp = front; // temporarily hold the front node
			front = front->next; // point front pointer to next element
			delete temp; // delete original front
			size--; // decrement size

			if (front == nullptr) // case when last element is removed from queue and queue becomes empty
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
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	node Front() // function that returns element at front of queue
	{
		if (!isEmpty())
		{
			return *front; // return first customer details
		}
		else
		{
			return node(0,"",0,0); // return dummy object in case queue is empty
		}
	}
	
	void print() // function to print the queue
	{
		node* current = front;
		cout << "<StartOfQueue> " << endl;
		while (current != nullptr)
		{
			cout << "ID: " << current->customer_id << ", TransactionType: " << current->transaction_type << ", Amount: " << current->amount << ", Balance: " << current->balance << endl;
			current = current->next;
		}
		cout << "<EndOfQueue>" << endl;
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

class stack
{
	node* topOfStackPointer; // pointer that points to element at top of stack
	int size; // current size of stack
public:
	stack() // constructor
	{
		topOfStackPointer = nullptr;
		size = 0;
	}

	int Size() // function that returns size of stack
	{
		return size;
	}

	bool isEmpty() // function that tells whether stack is empty or not
	{
		return size == 0;
	}

	node top() // function to peek the element at the top of stack
	{
		if (!isEmpty())
		{
			return *topOfStackPointer; // return element at top of stack
		}
		else
		{
			return node(0,"",0,0); // return dummy object in case stack is empty
		}
	}

	void pop() // function to remove element from top of stack
	{
		if (size != 0)
		{
			node* temp = topOfStackPointer;
			topOfStackPointer = topOfStackPointer->next;
			delete temp;
			size--;
		}
		else
		{
			cout << "Cannot pop, Stack already empty" << endl;
		}
	}

	void push(node &data) // function to add element at top of stack
	{
		node* temp = new node; // make new node
		temp->customer_id= data.customer_id; // insert data
		temp->transaction_type = data.transaction_type; // insert data
		temp->amount = data.amount; // insert data
		temp->balance = data.balance; // insert data
		temp->next = topOfStackPointer; // insert data
		topOfStackPointer = temp; // insert data
		size++; // increment size
	}

	void print() // function to print the stack
	{
		node* current = topOfStackPointer;
		cout << "<TopOfStack>" << endl;
		while (current != nullptr)
		{
			cout << "ID: " << current->customer_id << ", TransactionType: " << current->transaction_type << ", Amount: " << current->amount << ", Balance: " << current->balance << endl;
			current = current->next;
		}
		cout <<"<BottomOfStack>" << endl;
	}

	~stack() // destructor
	{
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				pop();
			}
		}
	}
};

void enqueue_customer(queue &queue,node &customer_data) // function to add a customer to the queue.
{
	queue.enqueue(customer_data); // add customer to queue 
}

void teller_serve_customer(queue&queue, stack &teller_stack) // function that removes a customer from queue and serves that removed customer
{
	node customerData = queue.Front(); // get customer from start of queue
	queue.dequeue(); // remove the customer from start of queue
	
	if(customerData.transaction_type=="withdrawal") // case when transaction is a withdrawal
	{
		customerData.balance = customerData.balance - customerData.amount; // deduct customer's balance
	}
	else if(customerData.transaction_type=="deposit") // case when transaction is a deposit
	{
		customerData.balance = customerData.balance + customerData.amount; // add balance to customer's account
	}

	teller_stack.push(customerData); // push the updated details of the customer on the top of stack
}

void check_balance(queue&queue,stack &teller_stack) // function that prints the balance of customer at the start of queue
{
	node customerData = queue.Front(); // get customer from start of queue
	queue.dequeue(); // remove the customer from start of queue
	
	customerData.transaction_type = "check_balance"; // update transaction record
	cout << "Customer with Id: " << customerData.customer_id << " has balance: " << customerData.balance << endl; // print customer's current balance
	
	teller_stack.push(customerData); // push the updated details of the customer on the top of stack
}

void get_transaction_history(stack &teller_stack)
{
	node customerData = teller_stack.top(); // get the details of last customer from top of stack
	cout << "Last customer served had Id:" << customerData.customer_id << ", Transaction Type was: " << customerData.transaction_type << endl; // print details of the last retrieved trasaction details from top of stack 
}

int main()
{
	queue queueOfCustomers; // make a queue of customers
	stack teller_stack; // make stack to hold transaction history
	
	node customer1(1, "withdrawal", 1000, 5000); // make an object of customer1
	node customer2(2, "deposit", 500, 4000);  // make an object of customer2
	node customer3(3, "check_balance", 0, 3000); // make an object of customer3
	cout << "After adding three customers to the queue: " << endl;
	enqueue_customer(queueOfCustomers, customer1); // add customer1 to queue
	enqueue_customer(queueOfCustomers, customer2); // add customer2 to queue
	enqueue_customer(queueOfCustomers, customer3); // add customer3 to queue
	queueOfCustomers.print(); // print the queue of customers
	cout <<"---------------------------------------------------------------" << endl;
	
	cout << "Performing transaction for first two customers . . ." << endl;
	teller_serve_customer(queueOfCustomers, teller_stack); // call teller_serve_customer() function to serve customer 1
	teller_serve_customer(queueOfCustomers, teller_stack); // call teller_serve_customer() function to serve customer 2
	cout << "---------------------------------------------------------------" << endl;
	
	cout << "Performing transaction for third customer . . ." << endl;
	check_balance(queueOfCustomers, teller_stack); // call check_balance() function to serve customer 3
	cout << "---------------------------------------------------------------" << endl;
	
	cout << "Getting transaction history for last customer:" << endl;
	get_transaction_history(teller_stack); // call get_transaction_history() function to print details of the last transaction
	cout << "---------------------------------------------------------------" << endl;
	
	cout << "The condition of teller_stack after serving all three customers in the queue:" << endl;
	teller_stack.print(); // print the stack after all the customers are served
	cout << "---------------------------------------------------------------" << endl;
	
	cout << endl;
	system("pause");
	return 0;
}