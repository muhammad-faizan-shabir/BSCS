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

	void merge(linkedlist &obj)
	{
		tail->next = obj.head;
		obj.head = nullptr;
		obj.tail = nullptr;
	}
	
	void sort()
	{
		node*current;
		node*prev;
		bool noMoreSwaps = false;

		while (noMoreSwaps == false)
		{
			current = head->next;
			prev = head;
			noMoreSwaps = true;

			while (current != nullptr)
			{
				if (prev->data > current->data)
				{
					int temp = prev->data;
					prev->data = current->data;
					current->data = temp;
					noMoreSwaps = false;
				}
				prev = current;
				current = current->next;
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
	linkedlist list1;

	cout << "after adding data at head of List1: " << endl;
	list1.insertAtHead(6);
	list1.print();
	cout << endl;
	
	cout << "after adding data at head of List1: " << endl;
	list1.insertAtHead(5);
	list1.print();
	cout << endl;
	
	cout << "after adding data at tail of List1: " << endl;
	list1.insertAtTail(90);
	list1.print();
	cout << endl;
	
	cout << "after adding data at tail of List1: " << endl;
	list1.insertAtTail(40);
	list1.print();
	cout << endl;
	cout << endl;
	cout << endl;

	linkedlist list2;

	cout << "after adding data at head of List2: " << endl;
	list2.insertAtHead(23);
	list2.print();
	cout << endl;
	
	cout << "after adding data at head of List2: " << endl;
	list2.insertAtHead(32);
	list2.print();
	cout << endl;
	
	cout << "after adding data at tail of List2: " << endl;
	list2.insertAtTail(86);
	list2.print();
	cout << endl;
	
	cout << "after adding data at tail of List2: " << endl;
	list2.insertAtTail(63);
	list2.print();
	cout << endl;
	cout << endl;

	cout << "After merging List1 and List2: " << endl;
	list1.merge(list2);
	list1.print();
	cout << endl;
	cout << endl;
	
	cout << "After sorting merged List1 and List2:" << endl;
	list1.sort();
	list1.print();
	
	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}