#include<iostream>
using namespace std;

class linkedlist
{
	class node // nested node class
	{
	public:
		char data;
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

	void insertAtTail(char element)
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

	void Insert_After(node * ptr, char key)
	{
		node*temp = new node;
		temp->data = key;
		temp->next = ptr->next;
		ptr->next = temp;
	}

	void Delete_After(node * ptr)
	{
		if (ptr->next != nullptr)
		{
			node*temp = ptr->next;
			ptr->next = ptr->next->next;
			delete temp;
		}
	}

	bool Equalize_Occurrences(char key, int maxcount)
	{
		if (head != nullptr)
		{
			node*current = head;
			node*previous = nullptr;
			node*ahead = nullptr;
			bool found = false; 
			while (current != nullptr)
			{
				if (current->data == key&&current == head)
				{
					while (current != nullptr&&current->data == key)
					{
						ahead = current->next;
						delete current;
						current = ahead;
					}

					head = current;
					found = true;
					
					for (int i = 0; i < maxcount; i++)
					{
						node*temp = new node;
						temp->data = key;
						temp->next = head;
						head = temp;
					}
				}
				else if (current->data==key)
				{
					while (current != nullptr&&current->data == key)
					{
						ahead = current->next;
						Delete_After(previous);
						current = ahead;
					}

					for (int i = 0; i < maxcount; i++)
					{
						Insert_After(previous, key);
					}
					found = true;
				}
				else
				{
					previous = current;
					current = current->next;
				}
			}
			return found;
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
	cout << "Before:" << endl;
	list.insertAtTail('C');
	list.insertAtTail('B');
	list.insertAtTail('C');
	list.insertAtTail('C');
	list.insertAtTail('A');
	list.insertAtTail('D');
	list.insertAtTail('C');
	list.insertAtTail('C');
	list.insertAtTail('C');
	list.insertAtTail('C');
	list.insertAtTail('B');
	list.print();
	list.Equalize_Occurrences('C',2);
	cout << "After:" << endl;
	list.print();
	cout << endl;
	
	system("pause");
	return 0;
}