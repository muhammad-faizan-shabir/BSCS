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
		cout << endl;
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

	void deleteSubsequence()
	{
		if (head != nullptr)
		{
			node*current = head;
			node*previous = nullptr;
			node*ahead = nullptr;

			while (current != nullptr)
			{
				if (current->data == 0)
				{
					previous = current;
					current = current->next;
				}
				else if (current->data == 1 && current->next == nullptr)
				{
					current = current->next;
				}
				else if (current->data == 1 && current->next->data == 1)
				{
					previous = current;
					current = current->next;
				}
				else
				{
					do
					{
						ahead = current->next;
						delete current;
						current = ahead;
					} while (current != nullptr && current->data != 1);
					
					if (previous != nullptr)
					{
						previous->next = current;
					}
					else
					{
						head = current;
					}
				}
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
	cout << "Case1:" << endl;
	cout << "Before:" << endl;
	list.insertAtTail(1);
	list.insertAtTail(1);
	list.insertAtTail(0);
	list.insertAtTail(0);
	list.insertAtTail(1);
	list.insertAtTail(0);
	list.insertAtTail(1);
	list.print();
	list.deleteSubsequence();
	cout << "After:" << endl;
	list.print();
	cout << endl;

	linkedlist list2;
	cout << "Case2:" << endl;
	cout << "Before:" << endl;
	list2.insertAtTail(1);
	list2.insertAtTail(0);
	list2.insertAtTail(0);
	list2.insertAtTail(0);
	list2.insertAtTail(1);
	list2.insertAtTail(1);
	list2.insertAtTail(0);
	list2.print();
	list2.deleteSubsequence();
	cout << "After:" << endl;
	list2.print();
	cout << endl;

	linkedlist list3;
	cout << "Case3:" << endl;
	cout << "Before:" << endl;
	list3.insertAtTail(0);
	list3.insertAtTail(1);
	list3.insertAtTail(1);
	list3.insertAtTail(1);
	list3.print();
	list3.deleteSubsequence();
	cout << "After:" << endl;
	list3.print();
	cout << endl;

	linkedlist list4;
	cout << "Case4:" << endl;
	cout << "Before:" << endl;
	list4.insertAtTail(1);
	list4.insertAtTail(0);
	list4.print();
	list4.deleteSubsequence();
	cout << "After:" << endl;
	list4.print();
	cout << endl;
	
	system("pause");
	return 0;
}