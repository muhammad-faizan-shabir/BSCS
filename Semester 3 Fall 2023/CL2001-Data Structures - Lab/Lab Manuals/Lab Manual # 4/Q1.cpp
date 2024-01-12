#include<iostream>
using namespace std;

struct node // node that holds data as well as addresses to implement a stack that stores addresses
{
	int data; // to store integer data
	node*Address; // to store address of a node
	node*next; // to store address of next node
	node*child; // to store address of child list
	node() // constructor
	{
		next = nullptr;
		child = nullptr;
	}
};

class LinkedList // dual functionality class that can act as an integer list or a stack of addresses
{
	node*head;
public:
	friend void flatten(LinkedList &list); // making flatten function friend of this class
	friend int main(); // making main function friend of this class
	
	LinkedList() // constructor
	{
		head = nullptr;
	}

	void pushAddress(node* address) // push function adds an address at the top of stack
	{
		node*temp = new node; // create new node
		temp->Address = address; // store address in the node
		
		node*current;
		node*previous = nullptr;
		current = head;
		
		while (current != nullptr) // move till end of list/stack
		{
			previous = current;
			current = current->next;
		}

		if (current == head) // case where list/stack is initially empty
		{
			head = temp; // add node at start of list/stack
		}
		else // case when at least one node already exists in the list/stack
		{
			previous->next = temp; // add new node after the last node
		}
	}

	node* popAddress() // pop function removes and returns the address stored at the top of stack
	{
		if (head == nullptr) // case when the list is empty and no node exists
		{
			return nullptr;
		}
		else
		{
			node*current; 
			node*previous = nullptr;
			current = head;
			
			while (current->next != nullptr) // move till last node
			{
				previous = current;
				current = current->next;
			}
			
			node* poppedValue = current->Address; // store the address from the node that is to be popped
			
			if (current == head) // case when only one node in the stack
			{
				delete current; // delete node from stack
				head = nullptr; // head should become null since stack is now empty
			}
			else
			{
				delete current; // delete node from stack
				previous->next = nullptr; // previous node should now point to null
			}
			
			return poppedValue; // returning the popped value
		}
	}

	bool isEmpty() // function that tells whether the stack is empty or not
	{
		if (head == nullptr) // case when stack is empty
		{
			return 1; // return 1 indicating that stack is empty
		}
		else // case when stack is not empty 
		{
			return 0; // return 0 indicating that stack is not empty 
		}
	}

	void insert(int data) // this function inserts integer data in the list
	{
		node *temp = new node; // create new node
		temp->data = data; // add data in the node
		
		node *current, *previous;
		current = head;
		previous = nullptr;
		
		while (current != nullptr && current->data < data) // move till the correct position where data is to be inserted
		{
			previous = current;
			current = current->next;
		}
		
		temp->next = current; // the new node will point to current
		
		if (current == head) // case when node is to be added at the start of the list
		{
			head = temp; 
		} 
		else // case when data is to be added other than start of the list
		{
			previous->next = temp;
		}
	}

	void print() // print function
	{
		node*current = head;
		while (current != nullptr)
		{
			cout << current->data;
			if (current->next != nullptr)
			{
				cout << " -> ";
			}
			current = current->next;
		}
		cout << endl;
	}

	~LinkedList() // destructor
	{
		if (head != nullptr)
		{
			node * current, *ahead;
			current = head;
			ahead = nullptr;
			while (current != nullptr)
			{
				ahead = current->next;
				delete current;
				current = ahead;
			}
		}
	}
};

void flatten(LinkedList &list) // function to flatten the given multi level linked list
{
	node* head = list.head; // initially storing head
	
	LinkedList stack; // making a stack using LinkedList class
	
	stack.pushAddress(head); // pushing the head on the stack
	
	node* prev = nullptr; 

	while (!(stack.isEmpty()))  // this loop will end when stack becomes empty
	{
		node* temp = stack.popAddress(); // poping an address from stack

		if (temp->next!=nullptr) // if next node exists then this condition will be true
			stack.pushAddress(temp->next); // pushing the address of next node on stack
		
		if (temp->child!=nullptr) // if child list exists then this condition will be true
			stack.pushAddress(temp->child); // pushing the address of child list on stack

		if (prev != nullptr) // case when the cuurent address is not the first address
			prev->next = temp; // falttening the list by joining the popped node with the previous node
		
		prev = temp; // updating the previous  
	}
}

int main()
{
	LinkedList multiLevelList; ////////////////////////////////  creating  a multilevel linked list
	multiLevelList.insert(1); /////////////////////////////////   1 -> 2 -> 3 -> 4
	multiLevelList.insert(2); /////////////////////////////////        |
	multiLevelList.insert(3); /////////////////////////////////        5 -> 6 
	multiLevelList.insert(4); /////////////////////////////////        |
	multiLevelList.head->next->child = new node; //////////////        7 -> 8 
	multiLevelList.head->next->child->data = 5; ///////////////
	multiLevelList.head->next->child->next = new node; ////////
	multiLevelList.head->next->child->next->data = 6; /////////
	multiLevelList.head->next->child->child = new node; ///////
	multiLevelList.head->next->child->child->data = 7; ////////
	multiLevelList.head->next->child->child->next = new node;//
	multiLevelList.head->next->child->child->next->data = 8; //
	
	flatten(multiLevelList); // calling the flatten function with the multilevel linked list as parameter

	multiLevelList.print(); // printing the list after it has been flattened

	cout << endl;
	system("pause");
	return 0;
}