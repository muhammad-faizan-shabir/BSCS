#include<iostream>
using namespace std;

class linkedlist
{
	class node // nested node class
	{
	public:
		int data;
		node* next;
		node()
		{
			next = nullptr;
		}
	};

	node*head;
	node*tail;
public:
	linkedlist()
	{
		head = nullptr;
		tail = nullptr;
	}

	void insertAtHead(int element)
	{
		node *temp = new node;
		temp->data = element;
		
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}

	void insertAtTail(int element)
	{
		node*temp = new node;
		temp->data = element;
		
		if (tail == nullptr)
		{
			tail = temp;
			head = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	void print()
	{
		node*current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}

	void eraseAtHead()
	{
		if (head != nullptr)
		{
			if (head == tail)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			} 
			else
			{
				node*temp = head->next;
				delete head;
				head = temp;
			}
		}
	}

	void eraseAtTail()
	{
		if (head != nullptr)
		{
			node *current, *previous;
			current = head;
			previous = nullptr;

			while (current->next != nullptr) 
			{
				previous = current;
				current = current->next;
			}

			if (head == tail)
			{
				delete tail;
				tail = nullptr;
				head = nullptr;
			}
			else
			{
				previous->next = nullptr;
				delete current;
				tail = previous;
			}
		}
	}
	
	~linkedlist()
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

int main()
{
	linkedlist list;

	cout << "after adding data at head: " << endl;
	list.insertAtHead(6);
	list.print();
	cout << endl;
	
	cout << "after adding data at head: " << endl;
	list.insertAtHead(5);
	list.print();
	cout << endl;
	
	cout << "after adding data at tail: " << endl;
	list.insertAtTail(90);
	list.print();
	cout << endl;
	
	cout << "after adding data at tail: " << endl;
	list.insertAtTail(40);
	list.print();
	cout << endl;
	cout << endl;
	
	cout << "after erasing data from head: " << endl;
	list.eraseAtHead();
	list.print();
	cout << endl;
	
	cout << "after erasing data from head: " << endl;
	list.eraseAtHead();
	list.print();
	cout << endl;
	
	cout << "after erasing data from tail: " << endl;
	list.eraseAtTail();
	list.print();
	cout << endl;
	
	cout << "after erasing data from tail: " << endl;
	list.eraseAtTail();
	list.print();
	cout << endl;
	
	cout << endl;
	system("pause");
	return 0;
}